/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include "Modules.hh"
#include "Scanner.hh"

extern union Node yylval;

/* import the parser's token type into a local typedef */
typedef decaf::Parser::token token;
typedef decaf::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "decafFlexLexer" */
%option prefix="decaf"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
    #define YY_USER_ACTION  yylloc->columns(yyleng);
%}

stringVal (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}


"true"      {yylval->pStrValue = new std::string(yytext); return token::TRUE;}
"false"     {yylval->pStrValue = new std::string(yytext); return token::FALSE;}
"callout"   {yylval->pStrValue = new std::string(yytext); return token::CALLOUT;}
"int"       {yylval->pStrValue = new std::string(yytext); return token::INT;}
"boolean"   {yylval->pStrValue = new std::string(yytext); return token::BOOLEAN;}
"class"     {yylval->pStrValue = new std::string(yytext); return token::CLASS;}
"void"      {yylval->pStrValue = new std::string(yytext); return token::VOID;}
"if"        {yylval->pStrValue = new std::string(yytext); return token::IF;}
"else"      {yylval->pStrValue = new std::string(yytext); return token::ELSE;}
"for"       {yylval->pStrValue = new std::string(yytext); return token::FOR;}
"break"     {yylval->pStrValue = new std::string(yytext); return token::BREAK;}
"continue"  {yylval->pStrValue = new std::string(yytext); return token::CONTINUE;}
"return"    {yylval->pStrValue = new std::string(yytext); return token::RETURN;}

"//".*		/* Ignore Comments */

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval->pStrValue = new std::string(yytext);
    return token::ID;
}

[0-9]+ {
    yylval->iValue = atoi(yytext);
    return token::NUMBER;
}

0x[0-9a-fA-F]+ {
    yylval->hexValue = atol(yytext);
    return token::HEX_NUMBER;
}

"="     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"+"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"-"		{yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"*"		{yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"/"		{yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"%"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"<"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
">"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"<="    {yylval->pStrValue = new std::string(yytext); return token::OP_LET;}
">="    {yylval->pStrValue = new std::string(yytext); return token::OP_GET;}
"=="    {yylval->pStrValue = new std::string(yytext); return token::OP_EEQ;}
"!="    {yylval->pStrValue = new std::string(yytext); return token::OP_NEQ;}
"&&"    {yylval->pStrValue = new std::string(yytext); return token::OP_AND;}
"||"    {yylval->pStrValue = new std::string(yytext); return token::OP_OR;}
"+="    {yylval->pStrValue = new std::string(yytext); return token::OP_PLUS_EQ;}
"-="    {yylval->pStrValue = new std::string(yytext); return token::OP_MINUS_EQ;}
"!"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"("		{yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
")"		{yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"["     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"]"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"{"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
"}"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
","     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}
";"     {yylval->cValue = *yytext; return static_cast<token_type>(*yytext);}


[ !#$%&(-[]-~] {
    yylval->cValue = *yytext;
    return token::CHAR;
}

\"{stringVal}*\" {
    yylval->pStrValue = new std::string(yytext);
    return token::STRING;
    }


 /* gobble up white-spaces & end-of-lines */
[ \t\r]+ {
    yylloc->step();
}

\n {
    yylloc->lines(yyleng);
    yylloc->step();
}

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}


%% /*** Additional Code ***/

namespace decaf
{

Scanner::Scanner(std::istream* in,
		         std::ostream* out)
: decafFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}


/* This implementation of DecafFlexLexer::yylex() is required to fill the
 * vtable of the class DecafFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int decafFlexLexer::yylex()
{
    std::cerr << "in decafFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int decafFlexLexer::yywrap()
{
    return 1;
}

