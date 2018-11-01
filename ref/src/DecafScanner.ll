/* Lexical Analyser / Scanner of the Decaf Programming language */

%{
    #include "Scanner.hh"
    int lineno = 0;
%}


%%

"true"      {return TRUE;}
"false"     {return FALSE;}
"callout"   {return CALLOUT;}
"int"       {return INT;}
"boolean"   {return BOOLEAN;}
"class"     {return CLASS;}
"Program"   {return PROGRAM;}
"void"      {return VOID;}
"if"        {return IF;}
"else"      {return ELSE;}
"for"       {return FOR;}
"break"     {return BREAK;}
"continue"  {return CONTINUE;}
"return"    {return RETURN;}

[a-zA-Z_][a-zA-Z0-9_]*	    {return ID;}
[0-9][0-9]*                 {yylval = atoi(yytext); return NUMBER;}
0x[0-9a-fA-F]+              {return HEX_NUMBER;}

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
"+="    {return OP_PLUS_EQ;}
"-="    {return OP_MINUS_EQ;}
"!"     {return '!';}
"("		{return '(';}
")"		{return ')';}
"["     {return '[';}
"]"     {return ']';}
"{"     {return '{';}
"}"     {return '}';}
","     {return ',';}
";"     {return ';';}


[ !#$%&(-[]-~]      {return CHAR;}
[ !#$%&(-[]-~]*     {return STRING;}

[ \t]	{ /* Ignore whitespaces */ }
\n		{++lineno; return EOL;}
.		{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%

