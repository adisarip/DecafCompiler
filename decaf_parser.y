/* Parser for the Decaf programming language */

/* Declarations */

%{
	#include <stdio.h>
%}

%token ID
%token TRUE FALSE CALLOUT
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
%left '!'
%right UMINUS


%%

/* Parser Rules*/ 

start	:   /* Nothing */
        |   start expr EOL { printf(" = %d\n", $2); }
        ;

method_call:
		ID '(' expr_list ')'
	|	CALLOUT '(' STRING ',' callout_arg_list ')'
	;

expr_list:
		/* epsilon */
	| expr ',' expr_list
	;

callout_arg_list:
		callout_arg
	|	callout_arg ',' callout_arg_list
	;

callout_arg:
		expr
	|	STRING
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
	|	ID   '[' expr ']'
	;

literal:
		int_literal
	|	bool_literal
	;

int_literal:
		decimal_literal
	|	hex_literal
	;

decimal_literal	:	NUMBER;
hex_literal		:	HEX_NUMBER;
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