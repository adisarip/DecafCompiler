/* Parser for the Decaf programming language */

/* Declarations */

%{
	#include <stdio.h>
%}

%token ID
%token TRUE FALSE
%token DIGIT DIGITS HEX_PREFIX HEX_DIGIT HEX_DIGITS
%token ALPHA ALPHA_NUM
%token OP_LET OP_GET OP_EEQ OP_NEQ OP_AND OP_OR
%token EOL
%left '<' '>' '=' OP_NEQ OP_LET OP_GET OP_EEQ
%left '+' '-'
%left '*' '/' '%' OP_AND OP_OR
%left '!'
%left '(' '['
%right ')' ']'

/* Parser Rules*/ 
%%

expr	:	location
		| 	literal
		| 	expr bin_op expr
		|	'-' expr		{ $$ = -$2; }
		|	'!'	expr		{ $$ = !$2; }
		|	'(' expr ')'	{ $$ = ($2); }
		;

bin_op  	:	arith_op | rel_op | eq_op | cond_op;
arith_op	: 	'+' | '-' | '*' | '/' | '%' ;
rel_op  	:	'<' | '>' | OP_LET | OP_GET ;
eq_op		:	OP_EEQ | OP_NEQ ;
cond_op		:	OP_AND | OP_OR ;

literal	        :	int_literal | bool_literal;
int_literal	    :	decimal_literal | hex_literal;
decimal_literal	: 	DIGITS;
hex_literal		: 	HEX_PREFIX HEX_DIGITS;
bool_literal	:	TRUE | FALSE;

location	:	id
			|	id   '[' expr ']'
			;

id	:  ID;

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