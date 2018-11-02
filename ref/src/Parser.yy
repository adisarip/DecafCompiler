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

%token END 0
%token EOL
%token ID
%token TRUE FALSE CALLOUT INT BOOLEAN CLASS PROGRAM VOID IF ELSE FOR BREAK CONTINUE RETURN
%token NUMBER HEX_NUMBER
%token ALPHA ALPHA_NUM CHAR STRING

%left OP_OR
%left OP_AND
%left OP_EEQ OP_NEQ
%left '<' OP_LET '>' OP_GET
%left '+' '-'
%left '*' '/' '%'
%right '!'
%right UMINUS

/***************
%token ID
%token TRUE FALSE CALLOUT INT BOOLEAN CLASS PROGRAM VOID IF ELSE FOR BREAK CONTINUE RETURN
%token NUMBER HEX_NUMBER
%token ALPHA ALPHA_NUM CHAR STRING
%token EOL
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
******************/

%%

line:
        EOL       { $$ = NULL; driver.mAstCtx.pRoot = NULL;}
    |   expr ';'  { $$ = $1; driver.mAstCtx.pRoot = $1; }
    ;

expr:
        literal          { $$ = $1; }
    |   binary_operation { $$ = $1; }
    |   unary_operation  { $$ = $1; }
    |   '(' expr ')'     { $$ = $2; }
    ;

literal:
        int_literal  { $$ = $1; }
    |   bool_literal { $$ = $1; }
    ;

int_literal:
        decimal_literal { $$ = $1; }
    |   hex_literal     { $$ = $1; }
    ;

decimal_literal : NUMBER { $$ = new IntegerAstNode(yylval->integerVal) };
hex_literal : HEX_NUMBER { $$ = new HexAstNode(yylval->hexVal) };
bool_literal:
        TRUE  { $$ = new BooleanAstNode(true); }
    |   FALSE { $$ = new BooleanAstNode(false); }
    ;

binary_operation:
        expr '+' expr    { $$ = new BinaryAstNode("+", $1, $3); }
    |   expr '-' expr    { $$ = new BinaryAstNode("-", $1, $3); }
    |   expr '*' expr    { $$ = new BinaryAstNode("*", $1, $3); }
    |   expr '/' expr    { $$ = new BinaryAstNode("/", $1, $3); }
    |   expr '%' expr    { $$ = new BinaryAstNode("%", $1, $3); }
    |   expr '<' expr    { $$ = new BinaryAstNode("<", $1, $3); }
    |   expr '>' expr    { $$ = new BinaryAstNode(">", $1, $3); }
    |   expr OP_EEQ expr { $$ = new BinaryAstNode("==", $1, $3); }
    |   expr OP_GET expr { $$ = new BinaryAstNode(">=", $1, $3); }
    |   expr OP_LET expr { $$ = new BinaryAstNode("<=", $1, $3); }
    |   expr OP_NEQ expr { $$ = new BinaryAstNode("!=", $1, $3); }
    |   expr OP_AND expr { $$ = new BinaryAstNode("&&", $1, $3); }
    |   expr OP_OR  expr { $$ = new BinaryAstNode("||", $1, $3); }
    ;

unary_operation:
        '-' expr %prec UMINUS { $$ = new UnaryAstNode("-", $2); }
    |   '!' expr              { $$ = new UnaryAstNode("!", $2); }
    ;


%%

void decaf::Parser::error(const Parser::location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
