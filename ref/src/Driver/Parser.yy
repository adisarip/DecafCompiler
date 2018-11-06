/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/
#include <stdio.h>
#include <string>
#include <vector>

extern union Nodes yylval;

class Program* start = NULL;
int errors=0;

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug


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

%code requires
{
    #include "Modules.hh"
}

%start program

%token CLASS CALLOUT EOL END
%token IF ELSE FOR BREAK CONTINUE RETURN
%token TRUE FALSE
%token <iValue> NUMBER
%token <hexValue> HEX_NUMBER
%token <cValue> CHAR
%token <pStrValue> INT BOOLEAN ID VOID
%token <pStrValue> ALPHA ALPHA_NUM STRING
%token ','

%right OP_PLUS_EQ OP_MINUS_EQ
%right '='
%left OP_OR
%left OP_AND
%left OP_EEQ OP_NEQ
%left '<' OP_LET '>' OP_GET
%left '+' '-'
%left '*' '/' '%'
%right '!'
%right UMINUS


%type <pProgram> program
%type <pFieldList> field_declaration_list
%type <pField> field_declaration
%type <pFieldVarList> field_declaration_variables_list
%type <pFieldVar> field_declaration_variable
%type <pMDeclList> method_declaration_list
%type <pMDecl> method_declaration
%type <pArgList> parameter_list
%type <pArg> parameter
%type <pVarDeclList> variable_declaration_list
%type <pVarDecl> variable_declaration
%type <pIdList> id_list
%type <pStmtList> statement_list
%type <pStmt> statement
%type <pBlockStmt> block_statement
%type <pCondStmt> if_conditional_statement
%type <pLoopStmt> for_loop_statement
%type <pReturnStmt> return_statement
%type <pAssgnStmt> assignment_operation
%type <pLocation> location
%type <pMCall> method_call
%type <pCallArgList> callout_arg_list
%type <pCallArg> callout_arg
%type <pExprList> expr_list
%type <pExpr> expr
%type <pLit> literal
%type <pIntLit> int_literal
%type <pHexLit> hex_literal
%type <pBoolLit> bool_literal
%type <pCharLit> char_literal
%type <pUExpr> unary_operation
%type <pBExpr> binary_operation


%{

#include "Driver.hh"
#include "Scanner.hh"
#include "Modules.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}


%%

/* Parser Rules*/ 

program:
    CLASS ID '{' field_declaration_list method_declaration_list '}' {
        $$ = new Program(*$2, $4, $5);
        driver.mAstCtx.pRoot = $$;
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
		ID                     { $$ = new Variable(*$1); }
	|	ID '[' int_literal ']' { $$ = new Variable(*$1, $3->getValue()); }
    |	ID '[' hex_literal ']' { $$ = new Variable(*$1, $3->getHexValue()); }
	;


method_declaration_list:
	{ $$ = new MethodDeclarationsList(); }
	|	method_declaration method_declaration_list { $$->add($1); }
	;

method_declaration:
		VOID ID '(' parameter_list ')' block_statement {
            $$ = new MethodDeclaration("void", *$2, $4, $6);
        }
	|	INT ID '(' parameter_list ')' block_statement {
            $$ = new MethodDeclaration("int", *$2, $4, $6);
        }
	|	BOOLEAN ID '(' parameter_list ')' block_statement {
            MethodDeclaration("boolean", *$2, $4, $6);
        }
	;

parameter_list:
	{ $$ = new ArgumentsList();  }
	|	parameter  { $$->add($1); }
	|	parameter_list ',' parameter  { $$->add($3); }
	;

parameter:
		INT ID     { $$ = new Argument("int", *$2); }
	|	BOOLEAN ID { $$ = new Argument("boolean", *$2); }
	;

block_statement:
    '{' variable_declaration_list statement_list '}'  {
        $$ = new BlockStatement($2, $3);
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
	|	ID  { $$->add(*$1); }
	|	id_list ',' ID  { $$->add(*$3); }
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
            $$ = new ForStatement(*$2, $4, $6, $7);
        };

return_statement:
		RETURN              { $$ = new ReturnStatement(NULL); }
	|	RETURN '(' expr ')' { $$ = new ReturnStatement($3); }
	;

method_call:
		ID '(' expr_list ')'  {
            $$ = new UserDefinedMethodCall(*$1, $3);
        }
	|	CALLOUT '(' STRING ',' callout_arg_list ')'  {
            $$ = new CalloutMethodCall(*$3, $5);
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
	|	STRING { $$ = new CalloutArgument(*$1); }
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
		ID              { $$ = new VariableLocation(*$1); }
	|	ID '[' expr ']' { $$ = new VariableLocation(*$1, $3); }
	;

literal:
		int_literal  { $$ = $1; }
    |	hex_literal  { $$ = $1; }
	|	bool_literal { $$ = $1; }
	|	char_literal { $$ = $1; }
	;

bool_literal:
		TRUE             { $$ = new BooleanLiteral("true"); }
	|	FALSE            { $$ = new BooleanLiteral("false"); };
int_literal:  NUMBER     { $$ = new IntegerLiteral($1); };
hex_literal:  HEX_NUMBER { $$ = new HexadecimalLiteral($1); };
char_literal: CHAR       { $$ = new CharacterLiteral($1); };


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
