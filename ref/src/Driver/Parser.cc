// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   decaflex

// First part of user declarations.
#line 4 "./src/Driver/Parser.yy" // lalr1.cc:407
 /*** C/C++ Declarations ***/
#include <stdio.h>
#include <string>
#include <vector>

extern union Nodes yylval;

class Program* start = NULL;
int errors=0;

#line 117 "./src/Driver/Parser.yy" // lalr1.cc:407


#include "Driver.hh"
#include "Scanner.hh"
#include "Modules.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 63 "./src/Driver/Parser.cc" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "Parser.hh"

// User implementation prologue.

#line 77 "./src/Driver/Parser.cc" // lalr1.cc:415


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace decaf {
#line 172 "./src/Driver/Parser.cc" // lalr1.cc:491

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value (other.value)
    , location (other.location)
  {
  }

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    value = that.value;
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.value, that.location)
  {
    // that is emptied.
    that.type = empty_symbol;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  Parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
    #line 41 "./src/Driver/Parser.yy" // lalr1.cc:750
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 526 "./src/Driver/Parser.cc" // lalr1.cc:750

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 137 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
        (yylhs.value.pProgram) = new Program(*(yystack_[4].value.pStrValue), (yystack_[2].value.pFieldList), (yystack_[1].value.pMDeclList));
        driver.mAstCtx.pRoot = (yylhs.value.pProgram);
    }
#line 645 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 3:
#line 144 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldList) = new FieldDeclarationsList(); }
#line 651 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 4:
#line 145 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldList)->add((yystack_[0].value.pField)); }
#line 657 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 5:
#line 149 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pField) = new FieldDeclaration("int", (yystack_[1].value.pFieldVarList));
        }
#line 665 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 6:
#line 152 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pField) = new FieldDeclaration("boolean", (yystack_[1].value.pFieldVarList));
        }
#line 673 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 7:
#line 158 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVarList) = new VariablesList(); }
#line 679 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 8:
#line 159 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVarList)->add((yystack_[0].value.pFieldVar)); }
#line 685 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 9:
#line 160 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVarList)->add((yystack_[0].value.pFieldVar)); }
#line 691 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 10:
#line 164 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[0].value.pStrValue)); }
#line 697 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 11:
#line 165 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[3].value.pStrValue), (yystack_[1].value.pIntLit)->getValue()); }
#line 703 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 12:
#line 166 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[3].value.pStrValue), (yystack_[1].value.pHexLit)->getHexValue()); }
#line 709 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 13:
#line 171 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pMDeclList) = new MethodDeclarationsList(); }
#line 715 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 14:
#line 172 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pMDeclList)->add((yystack_[1].value.pMDecl)); }
#line 721 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 15:
#line 176 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pMDecl) = new MethodDeclaration("void", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }
#line 729 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 16:
#line 179 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pMDecl) = new MethodDeclaration("int", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }
#line 737 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 17:
#line 182 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            MethodDeclaration("boolean", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }
#line 745 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 18:
#line 188 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pArgList) = new ArgumentsList();  }
#line 751 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 19:
#line 189 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pArgList)->add((yystack_[0].value.pArg)); }
#line 757 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 20:
#line 190 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pArgList)->add((yystack_[0].value.pArg)); }
#line 763 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 21:
#line 194 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pArg) = new Argument("int", *(yystack_[0].value.pStrValue)); }
#line 769 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 22:
#line 195 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pArg) = new Argument("boolean", *(yystack_[0].value.pStrValue)); }
#line 775 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 23:
#line 199 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
        (yylhs.value.pBlockStmt) = new BlockStatement((yystack_[2].value.pVarDeclList), (yystack_[1].value.pStmtList));
    }
#line 783 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 24:
#line 204 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pVarDeclList) = new VariableDeclarationsList(); }
#line 789 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 25:
#line 205 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pVarDeclList)->add((yystack_[0].value.pVarDecl)); }
#line 795 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 26:
#line 209 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pVarDecl) = new VariableDeclaration("int", (yystack_[1].value.pIdList)); }
#line 801 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 27:
#line 210 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pVarDecl) = new VariableDeclaration("boolean", (yystack_[1].value.pIdList)); }
#line 807 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 28:
#line 213 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pIdList) = new IdentifiersList(); }
#line 813 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 29:
#line 214 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue)); }
#line 819 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 30:
#line 215 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue)); }
#line 825 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 31:
#line 219 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmtList) = new StatementsList(); }
#line 831 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 32:
#line 220 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmtList)->add((yystack_[0].value.pStmt)); }
#line 837 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 33:
#line 224 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[0].value.pBlockStmt); }
#line 843 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 34:
#line 225 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[0].value.pCondStmt); }
#line 849 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 35:
#line 226 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[0].value.pLoopStmt); }
#line 855 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 36:
#line 227 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[1].value.pAssgnStmt); }
#line 861 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 37:
#line 228 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[1].value.pMCall); }
#line 867 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 38:
#line 229 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = (yystack_[1].value.pReturnStmt); }
#line 873 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 39:
#line 230 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = new BreakStatement(); }
#line 879 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 40:
#line 231 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pStmt) = new ContinueStatement(); }
#line 885 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 41:
#line 235 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }
#line 891 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 42:
#line 236 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("+=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }
#line 897 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 43:
#line 237 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("-=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }
#line 903 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 44:
#line 241 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pCondStmt) = new IfElseStatement((yystack_[2].value.pExpr), (yystack_[0].value.pBlockStmt), NULL);
        }
#line 911 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 45:
#line 244 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pCondStmt) = new IfElseStatement((yystack_[4].value.pExpr), (yystack_[2].value.pBlockStmt), (yystack_[0].value.pBlockStmt));
    }
#line 919 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 46:
#line 250 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pLoopStmt) = new ForStatement(*(yystack_[5].value.pStrValue), (yystack_[3].value.pExpr), (yystack_[1].value.pExpr), (yystack_[0].value.pBlockStmt));
        }
#line 927 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 47:
#line 255 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pReturnStmt) = new ReturnStatement(NULL); }
#line 933 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 48:
#line 256 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pReturnStmt) = new ReturnStatement((yystack_[1].value.pExpr)); }
#line 939 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 49:
#line 260 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pMCall) = new UserDefinedMethodCall(*(yystack_[3].value.pStrValue), (yystack_[1].value.pExprList));
        }
#line 947 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 50:
#line 263 "./src/Driver/Parser.yy" // lalr1.cc:870
    {
            (yylhs.value.pMCall) = new CalloutMethodCall(*(yystack_[3].value.pStrValue), (yystack_[1].value.pCallArgList));
        }
#line 955 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 51:
#line 269 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExprList) = new ExpressionsList(); }
#line 961 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 52:
#line 270 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExprList)->add((yystack_[0].value.pExpr)); }
#line 967 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 53:
#line 271 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExprList)->add((yystack_[0].value.pExpr)); }
#line 973 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 54:
#line 275 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCallArgList) = new CalloutArgumentsList();}
#line 979 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 55:
#line 276 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCallArgList)->add((yystack_[0].value.pCallArg)); }
#line 985 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 56:
#line 277 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCallArgList)->add((yystack_[0].value.pCallArg)); }
#line 991 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 57:
#line 281 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCallArg) = new CalloutArgument((yystack_[0].value.pExpr)); }
#line 997 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 58:
#line 282 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCallArg) = new CalloutArgument(*(yystack_[0].value.pStrValue)); }
#line 1003 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 59:
#line 286 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = (yystack_[0].value.pLocation); }
#line 1009 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 60:
#line 287 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = (yystack_[0].value.pLit); }
#line 1015 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 61:
#line 288 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = (yystack_[0].value.pMCall); }
#line 1021 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 62:
#line 289 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = (yystack_[0].value.pBExpr); }
#line 1027 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 63:
#line 290 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = (yystack_[0].value.pUExpr); }
#line 1033 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 64:
#line 291 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pExpr) = new EnclosedExpression((yystack_[1].value.pExpr)); }
#line 1039 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 65:
#line 295 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLocation) = new VariableLocation(*(yystack_[0].value.pStrValue)); }
#line 1045 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 66:
#line 296 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLocation) = new VariableLocation(*(yystack_[3].value.pStrValue), (yystack_[1].value.pExpr)); }
#line 1051 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 67:
#line 300 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLit) = (yystack_[0].value.pIntLit); }
#line 1057 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 68:
#line 301 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLit) = (yystack_[0].value.pHexLit); }
#line 1063 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 69:
#line 302 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLit) = (yystack_[0].value.pBoolLit); }
#line 1069 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 70:
#line 303 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pLit) = (yystack_[0].value.pCharLit); }
#line 1075 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 71:
#line 307 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBoolLit) = new BooleanLiteral("true"); }
#line 1081 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 72:
#line 308 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBoolLit) = new BooleanLiteral("false"); }
#line 1087 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 73:
#line 309 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pIntLit) = new IntegerLiteral((yystack_[0].value.iValue)); }
#line 1093 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 74:
#line 310 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pHexLit) = new HexadecimalLiteral((yystack_[0].value.hexValue)); }
#line 1099 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 75:
#line 311 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pCharLit) = new CharacterLiteral((yystack_[0].value.cValue)); }
#line 1105 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 76:
#line 315 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("+", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1111 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 77:
#line 316 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("-", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1117 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 78:
#line 317 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("*", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1123 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 79:
#line 318 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("/", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1129 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 80:
#line 319 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("%", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1135 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 81:
#line 320 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("<", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1141 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 82:
#line 321 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression(">", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1147 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 83:
#line 322 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("==", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1153 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 84:
#line 323 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression(">=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1159 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 85:
#line 324 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("<=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1165 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 86:
#line 325 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("!=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1171 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 87:
#line 326 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("&&", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1177 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 88:
#line 327 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pBExpr) = new BinaryExpression("||", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }
#line 1183 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 89:
#line 331 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pUExpr) = new UnaryExpression("-", (yystack_[0].value.pExpr)); }
#line 1189 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;

  case 90:
#line 332 "./src/Driver/Parser.yy" // lalr1.cc:870
    { (yylhs.value.pUExpr) = new UnaryExpression("!", (yystack_[0].value.pExpr)); }
#line 1195 "./src/Driver/Parser.cc" // lalr1.cc:870
    break;


#line 1199 "./src/Driver/Parser.cc" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -84;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      22,    21,    84,    42,   -84,   -84,    -3,    77,    82,   104,
     -84,    74,    58,   -30,    -2,   -84,   -23,    17,   112,   -84,
     142,   143,   -84,    16,    99,   144,   -84,    99,   -84,    99,
     116,   117,   -84,   -84,    98,   120,   147,   163,   -22,   -84,
     137,   -84,   -21,   -20,   -84,   -84,   -84,   -84,    99,   172,
     172,   172,   -84,   -84,   -84,   -84,   -84,   126,   165,   165,
     -84,    78,   -84,    34,    35,   138,   139,   197,   218,   219,
     217,    26,   -84,   -84,   -84,   221,   -84,   -84,   223,   224,
      67,   248,   -84,   -84,   247,    23,   244,   -84,   -84,    23,
      23,    23,   -84,   -84,   -84,    23,    23,    23,   -84,   249,
     -84,   -84,   -84,    23,    23,    23,   -84,    75,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    23,    97,   141,   -16,
     190,   190,   190,   190,    54,   -84,   -84,   119,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,   172,   161,   -84,   -84,    23,   -84,   -84,   -15,   -84,
     190,   -84,   202,   213,   222,   222,   102,   102,   102,   102,
      60,    60,   -84,   -84,   -84,   265,    23,   190,    54,   -84,
     172,   174,   -84,   -84,   -84
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     3,    13,     7,     7,     0,
       4,     0,    13,    10,     0,     8,    10,     0,     0,     2,
       0,     0,    14,     0,    18,     0,     5,    18,     6,    18,
       0,     0,    73,    74,     0,     0,     0,     0,     0,    19,
      10,     9,     0,     0,    11,    12,    21,    22,     0,     0,
       0,     0,    20,    24,    16,    17,    15,    31,    28,    28,
      25,     0,    29,     0,     0,     0,     0,     0,     0,     0,
      47,    65,    23,    33,    32,     0,    34,    35,     0,     0,
       0,     0,    26,    27,     0,     0,     0,    39,    40,     0,
       0,    51,    36,    38,    37,     0,     0,     0,    30,     0,
      71,    72,    75,     0,     0,     0,    61,     0,    59,    60,
      69,    67,    68,    70,    62,    63,     0,     0,     0,     0,
      52,    42,    43,    41,    54,    89,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    66,     0,    49,    58,     0,    55,
      57,    64,    88,    87,    83,    86,    81,    85,    82,    84,
      76,    77,    78,    79,    80,    44,     0,    53,     0,    50,
       0,     0,    56,    45,    46
  };

  const short
  Parser::yypgoto_[] =
  {
     -84,   -84,   -84,   -84,   267,   251,   266,   -84,    37,   229,
     -50,   -84,   -84,   220,   -84,   -84,   -84,   -84,   -84,   -84,
     225,   -84,   -84,   113,   -83,   226,   -84,   -84,   257,   259,
     -84,   -84,   -84
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     2,     6,    10,    14,    15,    11,    12,    38,    39,
      54,    57,    60,    63,    61,    74,    75,    76,    77,    78,
     106,   119,   148,   149,   150,   108,   109,   110,   111,   112,
     113,   114,   115
  };

  const unsigned char
  Parser::yytable_[] =
  {
      55,    56,   107,    48,    48,    48,   117,   118,   120,   145,
     168,    73,   121,   122,   123,     7,     8,    23,     9,    24,
     125,   126,   127,    25,    23,     1,    27,    65,    49,    50,
      51,    32,    33,   142,   146,   169,   100,   101,    32,    33,
     102,     3,    25,    71,    26,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    65,    81,
      81,   103,   167,    28,    42,   104,    43,   100,   101,    32,
      33,   102,   105,    90,    71,    91,    20,    21,   147,     9,
      82,    83,    65,   171,     4,    66,     5,    67,    68,    69,
      70,   165,   103,    95,    96,    97,   104,    13,    71,   138,
     139,   140,    16,   105,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    36,    37,    19,
     173,   174,    53,    72,    18,   141,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   136,
     137,   138,   139,   140,    58,    59,    44,   143,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    29,    30,    31,    40,    24,    27,    46,    45,   151,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    47,    23,    62,   166,    84,    85,   144,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    53,    86,    53,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    87,    88,    89,    92,    98,    93,
      94,    99,   116,   170,   124,    17,    41,    52,    22,    64,
      34,   172,    35,     0,     0,     0,    79,    80
  };

  const short
  Parser::yycheck_[] =
  {
      50,    51,    85,    25,    25,    25,    89,    90,    91,    25,
      25,    61,    95,    96,    97,    18,    19,    47,    21,    49,
     103,   104,   105,    25,    47,     3,    49,     4,    50,    50,
      50,    15,    16,   116,    50,    50,    13,    14,    15,    16,
      17,    20,    25,    20,    46,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     4,    25,
      25,    38,   145,    46,    27,    42,    29,    13,    14,    15,
      16,    17,    49,    47,    20,    49,    18,    19,    24,    21,
      46,    46,     4,   166,     0,     7,    44,     9,    10,    11,
      12,   141,    38,    26,    27,    28,    42,    20,    20,    39,
      40,    41,    20,    49,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    18,    19,    45,
     170,   171,    44,    45,    20,    50,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    37,
      38,    39,    40,    41,    18,    19,    48,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    49,    20,    20,    20,    49,    49,    20,    48,    50,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    20,    47,    20,    25,    49,    49,    48,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    44,    20,    44,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    46,    46,    49,    46,    20,    46,
      46,    24,    28,     8,    25,     8,    25,    48,    12,    59,
      23,   168,    23,    -1,    -1,    -1,    61,    61
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,    52,    20,     0,    44,    53,    18,    19,    21,
      54,    57,    58,    20,    55,    56,    20,    55,    20,    45,
      18,    19,    57,    47,    49,    25,    46,    49,    46,    49,
      20,    20,    15,    16,    79,    80,    18,    19,    59,    60,
      20,    56,    59,    59,    48,    48,    20,    20,    25,    50,
      50,    50,    60,    44,    61,    61,    61,    62,    18,    19,
      63,    65,    20,    64,    64,     4,     7,     9,    10,    11,
      12,    20,    45,    61,    66,    67,    68,    69,    70,    71,
      76,    25,    46,    46,    49,    49,    20,    46,    46,    49,
      47,    49,    46,    46,    46,    26,    27,    28,    20,    24,
      13,    14,    17,    38,    42,    49,    71,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    28,    75,    75,    72,
      75,    75,    75,    75,    25,    75,    75,    75,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    50,    75,    50,    48,    25,    50,    24,    73,    74,
      75,    50,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    61,    25,    75,    25,    50,
       8,    75,    74,    61,    61
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    79,    80,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     3,     3,     0,     1,     3,
       1,     4,     4,     0,     2,     6,     6,     6,     0,     1,
       3,     2,     2,     4,     0,     2,     3,     3,     0,     1,
       3,     0,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     3,     3,     5,     7,     7,     1,     4,     4,
       6,     0,     1,     3,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "CLASS", "CALLOUT", "EOL", "END", "IF",
  "ELSE", "FOR", "BREAK", "CONTINUE", "RETURN", "TRUE", "FALSE", "NUMBER",
  "HEX_NUMBER", "CHAR", "INT", "BOOLEAN", "ID", "VOID", "ALPHA",
  "ALPHA_NUM", "STRING", "','", "OP_PLUS_EQ", "OP_MINUS_EQ", "'='",
  "OP_OR", "OP_AND", "OP_EEQ", "OP_NEQ", "'<'", "OP_LET", "'>'", "OP_GET",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "'{'", "'}'", "';'",
  "'['", "']'", "'('", "')'", "$accept", "program",
  "field_declaration_list", "field_declaration",
  "field_declaration_variables_list", "field_declaration_variable",
  "method_declaration_list", "method_declaration", "parameter_list",
  "parameter", "block_statement", "variable_declaration_list",
  "variable_declaration", "id_list", "statement_list", "statement",
  "assignment_operation", "if_conditional_statement", "for_loop_statement",
  "return_statement", "method_call", "expr_list", "callout_arg_list",
  "callout_arg", "expr", "location", "literal", "bool_literal",
  "int_literal", "hex_literal", "char_literal", "binary_operation",
  "unary_operation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   137,   137,   144,   145,   149,   152,   158,   159,   160,
     164,   165,   166,   171,   172,   176,   179,   182,   188,   189,
     190,   194,   195,   199,   204,   205,   209,   210,   213,   214,
     215,   219,   220,   224,   225,   226,   227,   228,   229,   230,
     231,   235,   236,   237,   241,   244,   250,   255,   256,   260,
     263,   269,   270,   271,   275,   276,   277,   281,   282,   286,
     287,   288,   289,   290,   291,   295,   296,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   331,
     332
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    41,     2,     2,
      49,    50,    39,    37,    25,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      33,    28,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      26,    27,    29,    30,    31,    32,    34,    36,    43
    };
    const unsigned user_token_number_max_ = 288;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // decaf
#line 1768 "./src/Driver/Parser.cc" // lalr1.cc:1181
#line 334 "./src/Driver/Parser.yy" // lalr1.cc:1182


void decaf::Parser::error(const Parser::location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
