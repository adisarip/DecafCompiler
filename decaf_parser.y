/* Parser for the Decaf programming language */

/* Declarations */

%{
	#include <stdio.h>
	extern union Node yylval;
%}

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


%%

/* Parser Rules*/ 

start:
		/* Do Nothing */
    |   start program EOL { printf(" = %d\n", $2); }
    ;

program: CLASS PROGRAM '{' field_declaration_list method_declaration_list '}'


field_declaration_list:
		/* epsilon */
	|	field_declaration_list field_declaration
	;

field_declaration:
		INT field_declaration_variables_list ';'
	|	BOOLEAN field_declaration_variables_list ';'
	;

field_declaration_variables_list:
		/* epsilon */
	|	field_declaration_variable
	|	field_declaration_variables_list ',' field_declaration_variable
	;

field_declaration_variable:
		ID
	|	ID '[' int_literal ']'
	;


method_declaration_list:
		/* epsilon */
	|	method_declaration method_declaration_list
	;

method_declaration:
		VOID ID '(' parameter_list ')' block_statement
	|	INT ID '(' parameter_list ')' block_statement
	|	BOOLEAN ID '(' parameter_list ')' block_statement
	;

parameter_list:
		/* epsilon */
	|	parameter
	|	parameter_list ',' parameter
	;

parameter:
		INT ID
	|	BOOLEAN ID
	;

block_statement: '{' variable_declaration_list statement_list '}'

variable_declaration_list:
		/* epsilon */
	|	variable_declaration_list variable_declaration
	;

variable_declaration:
		INT id_list ';'
	|	BOOLEAN id_list ';'

id_list:
		/* epsilon */
	|	ID
	|	id_list ',' ID
	;

statement_list:
		/* epsilon */
	|	statement_list statement
	;

statement:
		block_statement
	|	if_conditional_statement
	|	for_loop_statement
	|   assignment_operation ';'
	|   method_call ';'
	|	return_statement ';'
	|	BREAK ';'
	|	CONTINUE ';'
	;

 assignment_operation:
        location '=' expr
	|   location OP_PLUS_EQ expr
	|   location OP_MINUS_EQ expr
	;

if_conditional_statement:
		IF '(' expr ')' block_statement
	|	IF '(' expr ')' block_statement ELSE block_statement
	;

for_loop_statement:	FOR ID '=' expr ',' expr block_statement ;

return_statement:
		RETURN
	|	RETURN '(' expr ')'
	;

method_call:
		ID '(' expr_list ')'
	|	CALLOUT '(' STRING ',' callout_arg_list ')'
	;

expr_list:
		/* epsilon */
	|	expr
	|	expr_list ',' expr
	;

callout_arg_list:
		/* epsilon */
	|	callout_arg
	|	callout_arg_list ',' callout_arg
	;

callout_arg:
		expr
	|	string_literal
	;

expr:
		location
	| 	literal
	|	method_call
	|	binary_operation
	|	unary_operation
	|	'(' expr ')'
	;

location:
		ID
	|	ID '[' expr ']'
	;

literal:
		int_literal
	|	bool_literal
	|	char_literal
	;

int_literal:
		decimal_literal
	|	hex_literal
	;

decimal_literal: NUMBER;
hex_literal:	 HEX_NUMBER;
char_literal:    CHAR;
string_literal:  STRING;
bool_literal:
		TRUE
	|	FALSE
	;

binary_operation:
		expr '+' expr
	|	expr '-' expr
	|	expr '*' expr
	|	expr '/' expr
	|	expr '%' expr
	|	expr '<' expr
	|	expr '>' expr
	|	expr OP_EEQ expr
	|	expr OP_GET expr
	|	expr OP_LET expr
	|	expr OP_NEQ expr
	|	expr OP_AND expr
	|	expr OP_OR  expr
	;

unary_operation:
		'-' expr %prec UMINUS
	|	'!' expr
	;


%%


/*Code Section*/

int main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}

int yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}