// A Bison parser, made by GNU Bison 3.2.2.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.


// Take the name prefix into account.
#define yylex   decaflex

// First part of user prologue.

 /*** C/C++ Declarations ***/
#include <stdio.h>
#include <string>
#include <vector>

extern union Nodes yylval;

class Program* program = NULL;
int errors=0;




#include "Driver.hh"
#include "Scanner.hh"
#include "Modules.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex




#include "Parser.hh"




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
  Parser::basic_symbol<Base>::basic_symbol (YY_RVREF (basic_symbol) other)
    : Base (YY_MOVE (other))
    , value (YY_MOVE (other.value))
    , location (YY_MOVE (other.location))
  {
  }


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
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
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
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

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

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
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
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
  Parser::operator() ()
  {
    return parse ();
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

{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}



    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
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

    {
        (yylhs.value.pProgram) = new Program(*(yystack_[4].value.pStrValue), (yystack_[2].value.pFieldList), (yystack_[1].value.pMDeclList));
        driver.mAstCtx.pRoot = (yylhs.value.pProgram);
    }

    break;

  case 3:

    {
        (yylhs.value.pFieldList) = new FieldDeclarationsList();
    }

    break;

  case 4:

    {
            (yylhs.value.pFieldList)->add((yystack_[0].value.pField));
        }

    break;

  case 5:

    {
            (yylhs.value.pField) = new FieldDeclaration("int", (yystack_[1].value.pFieldVarList));
        }

    break;

  case 6:

    {
            (yylhs.value.pField) = new FieldDeclaration("boolean", (yystack_[1].value.pFieldVarList));
        }

    break;

  case 7:

    {
            (yylhs.value.pFieldVarList) = new VariablesList();
            (yylhs.value.pFieldVarList)->add((yystack_[0].value.pFieldVar));
        }

    break;

  case 8:

    {
            (yylhs.value.pFieldVarList)->add((yystack_[0].value.pFieldVar));
        }

    break;

  case 9:

    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[0].value.pStrValue)); }

    break;

  case 10:

    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[3].value.pStrValue), (yystack_[1].value.pIntLit)->getValue()); }

    break;

  case 11:

    { (yylhs.value.pFieldVar) = new Variable(*(yystack_[3].value.pStrValue), (yystack_[1].value.pHexLit)->getHexValue()); }

    break;

  case 12:

    {
        (yylhs.value.pMDeclList) = new MethodDeclarationsList();
    }

    break;

  case 13:

    {
            (yystack_[0].value.pMDeclList)->add((yystack_[1].value.pMDecl));
            (yylhs.value.pMDeclList) = (yystack_[0].value.pMDeclList);
        }

    break;

  case 14:

    {
            (yylhs.value.pMDecl) = new MethodDeclaration("void", *(yystack_[4].value.pStrValue), (yystack_[2].value.pParmList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 15:

    {
            (yylhs.value.pMDecl) = new MethodDeclaration("int", *(yystack_[4].value.pStrValue), (yystack_[2].value.pParmList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 16:

    {
            MethodDeclaration("boolean", *(yystack_[4].value.pStrValue), (yystack_[2].value.pParmList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 17:

    {
        (yylhs.value.pParmList) = new ParametersList();
    }

    break;

  case 18:

    {
            (yylhs.value.pParmList) = new ParametersList();
            (yylhs.value.pParmList)->add((yystack_[0].value.pParm));
        }

    break;

  case 19:

    {
            (yylhs.value.pParmList)->add((yystack_[0].value.pParm));
        }

    break;

  case 20:

    {
            (yylhs.value.pParm) = new Parameter("int", *(yystack_[0].value.pStrValue));
        }

    break;

  case 21:

    {
            (yylhs.value.pParm) = new Parameter("boolean", *(yystack_[0].value.pStrValue));
        }

    break;

  case 22:

    {
        (yylhs.value.pBlockStmt) = new BlockStatement((yystack_[2].value.pVarDeclList), (yystack_[1].value.pStmtList));
    }

    break;

  case 23:

    {
        (yylhs.value.pVarDeclList) = new VariableDeclarationsList();
    }

    break;

  case 24:

    {
            (yylhs.value.pVarDeclList)->add((yystack_[0].value.pVarDecl));
        }

    break;

  case 25:

    {
            (yylhs.value.pVarDecl) = new VariableDeclaration("int", (yystack_[1].value.pIdList));
        }

    break;

  case 26:

    {
            (yylhs.value.pVarDecl) = new VariableDeclaration("boolean", (yystack_[1].value.pIdList));
        }

    break;

  case 27:

    {
        (yylhs.value.pIdList) = new IdentifiersList();
    }

    break;

  case 28:

    {
            (yylhs.value.pIdList) = new IdentifiersList(); (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue));
        }

    break;

  case 29:

    {
            (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue));
        }

    break;

  case 30:

    {
        (yylhs.value.pStmtList) = new StatementsList();
    }

    break;

  case 31:

    {
            (yylhs.value.pStmtList)->add((yystack_[0].value.pStmt));
        }

    break;

  case 32:

    {
            (yylhs.value.pStmt) = (yystack_[0].value.pBlockStmt);
        }

    break;

  case 33:

    {
            (yylhs.value.pStmt) = (yystack_[0].value.pCondStmt);
        }

    break;

  case 34:

    {
            (yylhs.value.pStmt) = (yystack_[0].value.pLoopStmt);
        }

    break;

  case 35:

    {
            (yylhs.value.pStmt) = (yystack_[1].value.pAssgnStmt);
        }

    break;

  case 36:

    {
            (yylhs.value.pStmt) = (yystack_[1].value.pMCall);
        }

    break;

  case 37:

    {
            (yylhs.value.pStmt) = (yystack_[1].value.pReturnStmt);
        }

    break;

  case 38:

    {
            (yylhs.value.pStmt) = new BreakStatement();
        }

    break;

  case 39:

    {
            (yylhs.value.pStmt) = new ContinueStatement();
        }

    break;

  case 40:

    {
            (yylhs.value.pAssgnStmt) = new AssignmentStatement("=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr));
        }

    break;

  case 41:

    {
            (yylhs.value.pAssgnStmt) = new AssignmentStatement("+=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr));
        }

    break;

  case 42:

    {
            (yylhs.value.pAssgnStmt) = new AssignmentStatement("-=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr));
        }

    break;

  case 43:

    {
            (yylhs.value.pCondStmt) = new IfElseStatement((yystack_[2].value.pExpr), (yystack_[0].value.pBlockStmt), NULL);
        }

    break;

  case 44:

    {
            (yylhs.value.pCondStmt) = new IfElseStatement((yystack_[4].value.pExpr), (yystack_[2].value.pBlockStmt), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 45:

    {
            (yylhs.value.pLoopStmt) = new ForStatement(*(yystack_[5].value.pStrValue), (yystack_[3].value.pExpr), (yystack_[1].value.pExpr), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 46:

    {
            (yylhs.value.pReturnStmt) = new ReturnStatement(NULL);
        }

    break;

  case 47:

    {
            (yylhs.value.pReturnStmt) = new ReturnStatement((yystack_[0].value.pExpr));
        }

    break;

  case 48:

    {
            (yylhs.value.pMCall) = new UserDefinedMethodCall(*(yystack_[3].value.pStrValue), (yystack_[1].value.pExprList));
        }

    break;

  case 49:

    {
            (yylhs.value.pMCall) = new CalloutMethodCall(*(yystack_[3].value.pStrValue), (yystack_[1].value.pCallArgList));
        }

    break;

  case 50:

    {
        (yylhs.value.pExprList) = new ExpressionsList();
    }

    break;

  case 51:

    {
            (yylhs.value.pExprList) = new ExpressionsList();
            (yylhs.value.pExprList)->add((yystack_[0].value.pExpr));
        }

    break;

  case 52:

    {
            (yylhs.value.pExprList)->add((yystack_[0].value.pExpr));
        }

    break;

  case 53:

    {
        (yylhs.value.pCallArgList) = new CalloutArgumentsList();
    }

    break;

  case 54:

    {
            (yylhs.value.pCallArgList) = new CalloutArgumentsList();
            (yylhs.value.pCallArgList)->add((yystack_[0].value.pCallArg));
        }

    break;

  case 55:

    {
            (yylhs.value.pCallArgList)->add((yystack_[0].value.pCallArg));
        }

    break;

  case 56:

    {
            (yylhs.value.pCallArg) = new CalloutArgument((yystack_[0].value.pExpr));
        }

    break;

  case 57:

    {
            (yylhs.value.pCallArg) = new CalloutArgument(*(yystack_[0].value.pStrValue));
        }

    break;

  case 58:

    {
            (yylhs.value.pExpr) = (yystack_[0].value.pLocation);
        }

    break;

  case 59:

    {
            (yylhs.value.pExpr) = (yystack_[0].value.pLit);
        }

    break;

  case 60:

    {
            (yylhs.value.pExpr) = (yystack_[0].value.pMCall);
        }

    break;

  case 61:

    {
            (yylhs.value.pExpr) = (yystack_[0].value.pBExpr);
        }

    break;

  case 62:

    {
            (yylhs.value.pExpr) = (yystack_[0].value.pUExpr);
        }

    break;

  case 63:

    {
            (yylhs.value.pExpr) = new EnclosedExpression((yystack_[1].value.pExpr));
        }

    break;

  case 64:

    {
            (yylhs.value.pLocation) = new VariableLocation(*(yystack_[0].value.pStrValue));
        }

    break;

  case 65:

    {
            (yylhs.value.pLocation) = new VariableLocation(*(yystack_[3].value.pStrValue), (yystack_[1].value.pExpr));
        }

    break;

  case 66:

    {
            (yylhs.value.pLit) = (yystack_[0].value.pIntLit);
        }

    break;

  case 67:

    {
            (yylhs.value.pLit) = (yystack_[0].value.pHexLit);
        }

    break;

  case 68:

    {
            (yylhs.value.pLit) = (yystack_[0].value.pBoolLit);
        }

    break;

  case 69:

    {
            (yylhs.value.pLit) = (yystack_[0].value.pCharLit);
        }

    break;

  case 70:

    {
            (yylhs.value.pBoolLit) = new BooleanLiteral("true");
        }

    break;

  case 71:

    {
            (yylhs.value.pBoolLit) = new BooleanLiteral("false");
        }

    break;

  case 72:

    {
        (yylhs.value.pIntLit) = new IntegerLiteral((yystack_[0].value.iValue));
    }

    break;

  case 73:

    {
        (yylhs.value.pHexLit) = new HexadecimalLiteral((yystack_[0].value.hexValue));
    }

    break;

  case 74:

    {
        (yylhs.value.pCharLit) = new CharacterLiteral((yystack_[0].value.cValue));
    }

    break;

  case 75:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("+", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 76:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("-", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 77:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("*", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 78:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("/", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 79:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("%", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 80:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("<", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 81:

    {
            (yylhs.value.pBExpr) = new BinaryExpression(">", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 82:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("==", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 83:

    {
            (yylhs.value.pBExpr) = new BinaryExpression(">=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 84:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("<=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 85:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("!=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 86:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("&&", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 87:

    {
            (yylhs.value.pBExpr) = new BinaryExpression("||", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr));
        }

    break;

  case 88:

    {
            (yylhs.value.pUExpr) = new UnaryExpression("-", (yystack_[0].value.pExpr));
        }

    break;

  case 89:

    {
            (yylhs.value.pUExpr) = new UnaryExpression("!", (yystack_[0].value.pExpr));
        }

    break;



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
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
      yypush_ ("Shifting", YY_MOVE (error_token));
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


  const signed char Parser::yypact_ninf_ = -69;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      13,     5,    27,     3,   -69,   -69,     2,    53,    84,    85,
     -69,    57,    30,   -25,   -11,   -69,    33,   -10,    58,   -69,
      86,    88,   -69,    37,    65,    89,   -69,    65,   -69,    65,
      63,    74,   -69,   -69,    76,    77,   106,   121,   -20,   -69,
      95,   -69,   -19,   -18,   -69,   -69,   -69,   -69,    65,   100,
     100,   100,   -69,   -69,   -69,   -69,   -69,    82,   123,   123,
     -69,   107,   -69,    -9,    -8,    96,    97,   127,   102,   104,
      73,    47,   -69,   -69,   -69,   120,   -69,   -69,   122,   125,
      15,   147,   -69,   -69,   145,    73,   142,   -69,   -69,   -69,
     -69,   -69,    73,    73,    73,   -69,   195,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,    73,    73,   -69,   -69,   -69,
      73,    73,    73,   -69,   148,    99,    73,   -69,   -69,   124,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,   146,   -17,   195,   195,   195,   195,    61,
     100,   166,   -69,   207,   218,   227,   227,    31,    31,    31,
      31,   -29,   -29,   -69,   -69,   -69,   -69,    73,   -69,   -69,
     -16,   -69,   195,   164,    73,   195,    61,   -69,   100,   179,
     -69,   -69,   -69
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     3,    12,     0,     0,     0,
       4,     0,    12,     9,     0,     7,     9,     0,     0,     2,
       0,     0,    13,     0,    17,     0,     5,    17,     6,    17,
       0,     0,    72,    73,     0,     0,     0,     0,     0,    18,
       9,     8,     0,     0,    10,    11,    20,    21,     0,     0,
       0,     0,    19,    23,    15,    16,    14,    30,    27,    27,
      24,     0,    28,     0,     0,     0,     0,     0,     0,     0,
      46,    64,    22,    32,    31,     0,    33,    34,     0,     0,
       0,     0,    25,    26,     0,     0,     0,    38,    39,    70,
      71,    74,     0,     0,     0,    60,    47,    58,    59,    68,
      66,    67,    69,    61,    62,     0,    50,    35,    37,    36,
       0,     0,     0,    29,     0,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    41,    42,    40,    53,
       0,     0,    63,    87,    86,    82,    85,    80,    84,    81,
      83,    75,    76,    77,    78,    79,    65,     0,    48,    57,
       0,    54,    56,    43,     0,    52,     0,    49,     0,     0,
      55,    44,    45
  };

  const short
  Parser::yypgoto_[] =
  {
     -69,   -69,   -69,   -69,   178,   162,   176,   -69,    66,   143,
     -50,   -69,   -69,   131,   -69,   -69,   -69,   -69,   -69,   -69,
     158,   -69,   -69,    54,   -68,   206,   -69,   -69,   245,   246,
     -69,   -69,   -69
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     2,     6,    10,    14,    15,    11,    12,    38,    39,
      54,    57,    60,    63,    61,    74,    75,    76,    77,    78,
      95,   134,   160,   161,   162,    97,    98,    99,   100,   101,
     102,   103,   104
  };

  const unsigned char
  Parser::yytable_[] =
  {
      55,    56,    96,    48,    48,    48,   157,   166,   130,   131,
     132,    73,    25,    25,    81,    81,     1,   115,     7,     8,
      23,     9,    24,     3,   117,   118,   119,     4,    49,    50,
      51,   158,   167,    26,    28,    82,    83,   133,   135,   110,
     111,   112,   136,   137,   138,     5,    20,    21,   141,     9,
      32,    33,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    65,   128,   129,   130,   131,
     132,    13,    89,    90,    32,    33,    91,    65,    23,    71,
      27,    36,    37,   159,    89,    90,    32,    33,    91,   165,
     163,    71,   105,    42,   106,    43,   169,    92,    58,    59,
      19,    93,    16,    18,    30,    29,    31,    40,    94,    92,
      24,    65,    66,    93,    67,    68,    69,    70,   171,   172,
      94,    27,    44,    45,    46,    71,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    47,
      23,    62,    53,    84,    85,    86,    87,   140,    88,    53,
      72,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   107,   113,   108,   114,   116,   109,
     168,   139,   142,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    17,    41,    22,   164,
      64,    52,   156,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    79,
     170,    53,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    80,    34,    35
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      50,    51,    70,    23,    23,    23,    23,    23,    37,    38,
      39,    61,    23,    23,    23,    23,     3,    85,    16,    17,
      45,    19,    47,    18,    92,    93,    94,     0,    48,    48,
      48,    48,    48,    44,    44,    44,    44,   105,   106,    24,
      25,    26,   110,   111,   112,    42,    16,    17,   116,    19,
      13,    14,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     4,    35,    36,    37,    38,
      39,    18,    11,    12,    13,    14,    15,     4,    45,    18,
      47,    16,    17,    22,    11,    12,    13,    14,    15,   157,
     140,    18,    45,    27,    47,    29,   164,    36,    16,    17,
      43,    40,    18,    18,    18,    47,    18,    18,    47,    36,
      47,     4,     5,    40,     7,     8,     9,    10,   168,   169,
      47,    47,    46,    46,    18,    18,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    18,
      45,    18,    42,    47,    47,    18,    44,    48,    44,    42,
      43,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    44,    18,    44,    22,    26,    44,
       6,    23,    48,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     8,    25,    12,    23,
      59,    48,    46,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    61,
     166,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    61,    23,    23
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,    50,    18,     0,    42,    51,    16,    17,    19,
      52,    55,    56,    18,    53,    54,    18,    53,    18,    43,
      16,    17,    55,    45,    47,    23,    44,    47,    44,    47,
      18,    18,    13,    14,    77,    78,    16,    17,    57,    58,
      18,    54,    57,    57,    46,    46,    18,    18,    23,    48,
      48,    48,    58,    42,    59,    59,    59,    60,    16,    17,
      61,    63,    18,    62,    62,     4,     5,     7,     8,     9,
      10,    18,    43,    59,    64,    65,    66,    67,    68,    69,
      74,    23,    44,    44,    47,    47,    18,    44,    44,    11,
      12,    15,    36,    40,    47,    69,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    45,    47,    44,    44,    44,
      24,    25,    26,    18,    22,    73,    26,    73,    73,    73,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    73,    70,    73,    73,    73,    73,    23,
      48,    73,    48,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    46,    23,    48,    22,
      71,    72,    73,    59,    23,    73,    23,    48,     6,    73,
      72,    59,    59
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    57,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    77,    78,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     3,     3,     1,     3,     1,
       4,     4,     0,     2,     6,     6,     6,     0,     1,     3,
       2,     2,     4,     0,     2,     3,     3,     0,     1,     3,
       0,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       3,     3,     3,     5,     7,     7,     1,     2,     4,     6,
       0,     1,     3,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "$undefined", "CLASS", "CALLOUT", "IF", "ELSE", "FOR",
  "BREAK", "CONTINUE", "RETURN", "TRUE", "FALSE", "NUMBER", "HEX_NUMBER",
  "CHAR", "INT", "BOOLEAN", "ID", "VOID", "ALPHA", "ALPHA_NUM", "STRING",
  "','", "OP_PLUS_EQ", "OP_MINUS_EQ", "'='", "OP_OR", "OP_AND", "OP_EEQ",
  "OP_NEQ", "'<'", "OP_LET", "'>'", "OP_GET", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "UMINUS", "'{'", "'}'", "';'", "'['", "']'", "'('", "')'",
  "$accept", "program", "field_declaration_list", "field_declaration",
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
       0,   138,   138,   145,   148,   154,   158,   164,   169,   176,
     177,   178,   182,   185,   192,   196,   200,   206,   209,   214,
     220,   224,   230,   236,   239,   245,   249,   255,   258,   262,
     268,   271,   277,   281,   285,   289,   293,   297,   301,   305,
     311,   315,   319,   325,   329,   335,   341,   345,   351,   355,
     361,   364,   369,   375,   378,   383,   389,   393,   399,   403,
     407,   411,   415,   419,   425,   429,   435,   439,   443,   447,
     453,   457,   463,   469,   475,   481,   485,   489,   493,   497,
     501,   505,   509,   513,   517,   521,   525,   529,   535,   539
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
       2,     2,     2,    40,     2,     2,     2,    39,     2,     2,
      47,    48,    37,    35,    23,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      31,    26,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    24,    25,
      27,    28,    29,    30,    32,    34,    41
    };
    const unsigned user_token_number_max_ = 286;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // decaf





void decaf::Parser::error(const Parser::location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}
