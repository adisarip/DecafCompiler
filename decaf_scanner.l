/* Lexical Analyser / Scanner of the Decaf Programming language */

%{
    #include "decaf_parser.tab.h"
    int lineno = 0;
%}


%%

"true"  { return TRUE; }
"false" { return FALSE; }

[a-zA-Z_][a-zA-Z0-9_]*	    {return ID;}
[0-9][0-9]*                 {yylval = atoi(yytext); return DIGITS;}
[0-9a-fA-F][0-9a-fA-F]*     {return HEX_DIGIT;}

"="     {return '=';}
"+"     {return '+';}
"-"		{return '-';}
"*"		{return '*';}
"/"		{return '/';}
"%"     {return '%';}
"<"     {return '<';}
">"     {return '>';}
"<="    {return OP_LET;}
">="    {return OP_GET;}
"=="    {return OP_EEQ;}
"!="    {return OP_NEQ;}
"&&"    {return OP_AND;}
"||"    {return OP_OR;}
"0x"    {return HEX_PREFIX;}
"!"     {return '!';}
"("		{return '(';}
")"		{return ')';}
"["     {return '[';}
"]"     {return ']';}
"{"     {return '{';}
"}"     {return '}';}

[ \t]	{ /* Ignore whitespaces */ }
\n		{++lineno; return EOL;}
.		{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

