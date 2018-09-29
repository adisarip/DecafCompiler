/* Parser for the Decaf programming language */

/* Declarations */

%{
	#include <stdio.h>
%}

%token ID
%token TRUE FALSE
%token DIGITS HEX_PREFIX HEX_DIGIT HEX_DIGITS
%token ALPHA ALPHA_NUM
%token EOL
%left '<' '>' '=' OP_NEQ OP_LET OP_GET OP_EEQ
%left '+' '-'
%left '*' '/' '%' OP_AND OP_OR
%left '!'


%%

/* Parser Rules*/ 

start	:   /* Nothing */
        |   start expr EOL { printf(" = %d\n", $2); }
        ;

expr	:	location
		| 	literal
		| 	expr '+' expr
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
		|	expr OP_OR expr
		|	'-' expr
		|	'!' expr
		|	'(' expr ')'
		;
 
literal	        :	int_literal | bool_literal;
int_literal	    :	decimal_literal | hex_literal;
decimal_literal	: 	DIGITS;
hex_literal		: 	HEX_PREFIX HEX_DIGITS;
bool_literal	:	TRUE | FALSE;

location	:	ID
			|	ID   '[' expr ']'
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