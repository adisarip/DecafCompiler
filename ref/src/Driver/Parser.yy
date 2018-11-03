/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#include "Modules.hh"
#include "Scanner.hh"
#include "Driver.hh"

extern union Node yylval;
class Program* start = NULL;
int errors=0;

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start line

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="decaf"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

/*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union
{
    int            integerVal;
    long int       hexVal;
    bool           boolValue;
    class AstNode* pAstNode;
}

%type <pAstNode> line expr 

//%destructor { delete $$; } expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%token CLASS
%token CALLOUT RETURN
%token BREAK CONTINUE
%token IF ELSE FOR
%token <pStrValue> BOOLEAN CHAR STRING HEX_NUMBER ID VOID
%token <number> INTEGER
%token OB CB OSB CSB OP CP
%token <pStrValue> COND_AND COND_OR NOT
%token <pStrValue> ADD SUB MUL DIV MOD
%token <pStrValue> LT GT LE GE
%token <pStrValue> EQUAL NOT_EQUAL
%token <pStrValue> EQ ADDEQ SUBEQ


%token ID
%token TRUE FALSE INT VOID
%token NUMBER 
%token ALPHA ALPHA_NUM

%left OP_OR
%left OP_AND
%left OP_EEQ OP_NEQ
%left '<' OP_LET '>' OP_GET
%left '+' '-'
%left '*' '/' '%'
%right '!'
%right UMINUS


%%

/* Parser Rules*/ 

start:
		/* Do Nothing */
    |   start program EOL { printf(" = %d\n", $2); }
    ;

program:
    CLASS ID '{' field_declaration_list method_declaration_list '}' {
        $$ = new Program(string($2), $4, $5);
    };


field_declaration_list:
	{ $$ = new FieldDeclarationsList(); }
	|	field_declaration_list field_declaration { $$->add($2); }
	;

field_declaration:
		INT field_declaration_variables_list ';' {
            $$ = new FieldDeclaration("int", $2);
        }
	|	BOOLEAN field_declaration_variables_list ';' {
            $$ = new FieldDeclaration("boolean", $2);
        }
	;

field_declaration_variables_list:
	{ $$ = new VariablesList(); }
	|	field_declaration_variable  { $$->add($1); }
	|	field_declaration_variables_list ',' field_declaration_variable { $$->add($3); }
	;

field_declaration_variable:
		ID                         { $$ = new Variable(string($1)); }
	|	ID '[' decimal_literal ']' { $$ = new Variable(string($1), $3->getValue()); }
    |	ID '[' hex_literal ']'     { $$ = new Variable(string($1), $3->getHexValue()); }
	;


method_declaration_list:
	{ $$ = new MethodDeclarationsList(); }
	|	method_declaration method_declaration_list { $$->add($1); }
	;

method_declaration:
		VOID ID '(' parameter_list ')' block_statement {
            $$ = new MethodDeclaration("void", string($2), $4, $6);
        }
	|	INT ID '(' parameter_list ')' block_statement {
            $$ = new MethodDeclaration("int", string($2), $4, $6);
        }
	|	BOOLEAN ID '(' parameter_list ')' block_statement {
            MethodDeclaration("boolean", string($2), $4, $6);
        }
	;

parameter_list:
	{ $$ = new ArgumentsList();  }
	|	parameter  { $$->add($1); }
	|	parameter_list ',' parameter  { $$->add($3); }
	;

parameter:
		INT ID     { $$ = new Argument("int", string($2)); }
	|	BOOLEAN ID { $$ = new Argument("boolean", string($2)); }
	;

block_statement:
    '{' variable_declaration_list statement_list '}'  {
        $$ = new BlockStatement($1, $2);
    };

variable_declaration_list:
	{ $$ = new VariableDeclarationsList(); }
	|	variable_declaration_list variable_declaration { $$->add($2); }
	;

variable_declaration:
		INT id_list ';'     { $$ = new VariableDeclaration("int", $2); }
	|	BOOLEAN id_list ';' { $$ = new VariableDeclaration("boolean", $2); }

id_list:
	{ $$ = new IdentifiersList(); }
	|	ID  { $$->add(string($1)); }
	|	id_list ',' ID  { $$->add(string($3)); }
	;

statement_list:
	{ $$ = new StatementsList(); }
	|	statement_list statement { $$->add($2); }
	;

statement:
		block_statement          { $$ = $1; }
	|	if_conditional_statement { $$ = $1; }
	|	for_loop_statement       { $$ = $1; }
	|   assignment_operation ';' { $$ = $1; }
	|   method_call ';'          { $$ = $1; }
	|	return_statement ';'     { $$ = $1; }
	|	BREAK ';'                { $$ = new BreakStatement(); }
	|	CONTINUE ';'             { $$ = new ContinueStatement(); }
	;

 assignment_operation:
        location '=' expr          { $$ = new AssignmentStatement("=", $1, $3); }
	|   location OP_PLUS_EQ expr   { $$ = new AssignmentStatement("+=", $1, $3); }
	|   location OP_MINUS_EQ expr  { $$ = new AssignmentStatement("-=", $1, $3); }
	;

if_conditional_statement:
		IF '(' expr ')' block_statement {
            $$ = new IfElseStatement($3, $5, NULL);
        }
	|	IF '(' expr ')' block_statement ELSE block_statement {
            $$ = new IfElseStatement($3, $5, $7);
    }
	;

for_loop_statement:
        FOR ID '=' expr ',' expr block_statement {
            $$ = new ForStatement(string($2), $4, $6, $7);
        };

return_statement:
		RETURN              { $$ = new ReturnStatement(NULL); }
	|	RETURN '(' expr ')' { $$ = new ReturnStatement($3); }
	;

method_call:
		ID '(' expr_list ')'  {
            $$ = new UserDefinedMethodCall(string($1), $3);
        }
	|	CALLOUT '(' STRING ',' callout_arg_list ')'  {
            $$ = new CalloutMethodCall(string($3), $5);
        }
	;

expr_list:
	{ $$ = new ExpressionsList(); }
	|	expr { $$->add($1); }
	|	expr_list ',' expr { $$->add($3); }
	;

callout_arg_list:
	{ $$ = new CalloutArgumentsList();}
	|	callout_arg { $$->add($1); }
	|	callout_arg_list ',' callout_arg { $$->add($3); }
	;

callout_arg:
		expr   { $$ = new CalloutArgument($1); }
	|	STRING { $$ = new CalloutArgument(string($1)); }
	;

expr:
		location         { $$ = $1; }
	| 	literal          { $$ = $1; }
	|	method_call      { $$ = $1; }
	|	binary_operation { $$ = $1; }
	|	unary_operation  { $$ = $1; }
	|	'(' expr ')'     { $$ = new EnclosedExpression($2); }
	;

location:
		ID              { $$ = new VariableLocation(string($1)); }
	|	ID '[' expr ']' { $$ = new VariableLocation(string($1), $3); }
	;

literal:
		int_literal  { $$ = $1; }
	|	bool_literal { $$ = $1; }
	|	char_literal { $$ = $1; }
	;

int_literal:
		decimal_literal { $$ = $1; }
	|	hex_literal     { $$ = $1; }
	;

bool_literal:
		TRUE                { $$ = new BooleanLiteral("true"); }
	|	FALSE               { $$ = new BooleanLiteral("false") };
decimal_literal: NUMBER     { $$ = new IntegerLiteral($1); };
hex_literal:	 HEX_NUMBER { $$ = new HexadecimalLiteral($1); };
char_literal:    CHAR       { $$ = new CharacterLiteral($1); };


binary_operation:
        expr '+' expr    { $$ = new BinaryExpression("+", $1, $3); }
    |   expr '-' expr    { $$ = new BinaryExpression("-", $1, $3); }
    |   expr '*' expr    { $$ = new BinaryExpression("*", $1, $3); }
    |   expr '/' expr    { $$ = new BinaryExpression("/", $1, $3); }
    |   expr '%' expr    { $$ = new BinaryExpression("%", $1, $3); }
    |   expr '<' expr    { $$ = new BinaryExpression("<", $1, $3); }
    |   expr '>' expr    { $$ = new BinaryExpression(">", $1, $3); }
    |   expr OP_EEQ expr { $$ = new BinaryExpression("==", $1, $3); }
    |   expr OP_GET expr { $$ = new BinaryExpression(">=", $1, $3); }
    |   expr OP_LET expr { $$ = new BinaryExpression("<=", $1, $3); }
    |   expr OP_NEQ expr { $$ = new BinaryExpression("!=", $1, $3); }
    |   expr OP_AND expr { $$ = new BinaryExpression("&&", $1, $3); }
    |   expr OP_OR  expr { $$ = new BinaryExpression("||", $1, $3); }
    ;

unary_operation:
        '-' expr %prec UMINUS { $$ = new UnaryExpression("-", $2); }
    |   '!' expr              { $$ = new UnaryExpression("!", $2); }
    ;
%%

void decaf::Parser::error(const Parser::location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
