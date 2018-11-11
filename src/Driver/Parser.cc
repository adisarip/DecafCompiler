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

 /*** C/C++ Declarations ***/
#include <stdio.h>
#include <string>
#include <vector>

extern union Nodes yylval;

class Program* start = NULL;
int errors=0;




#include "Driver.hh"
#include "Scanner.hh"
#include "Modules.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "Parser.hh"

// User implementation prologue.




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
    
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}



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
            (yylhs.value.pMDecl) = new MethodDeclaration("void", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 15:

    {
            (yylhs.value.pMDecl) = new MethodDeclaration("int", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 16:

    {
            MethodDeclaration("boolean", *(yystack_[4].value.pStrValue), (yystack_[2].value.pArgList), (yystack_[0].value.pBlockStmt));
        }

    break;

  case 17:

    {
		(yylhs.value.pArgList) = new ArgumentsList();
	}

    break;

  case 18:

    {
			(yylhs.value.pArgList) = new ArgumentsList();
			(yylhs.value.pArgList)->add((yystack_[0].value.pArg));
		}

    break;

  case 19:

    {
			(yylhs.value.pArgList)->add((yystack_[0].value.pArg));
		}

    break;

  case 20:

    {
			(yylhs.value.pArg) = new Argument("int", *(yystack_[0].value.pStrValue));
		}

    break;

  case 21:

    {
			(yylhs.value.pArg) = new Argument("boolean", *(yystack_[0].value.pStrValue));
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

    { (yylhs.value.pVarDecl) = new VariableDeclaration("int", (yystack_[1].value.pIdList)); }

    break;

  case 26:

    { (yylhs.value.pVarDecl) = new VariableDeclaration("boolean", (yystack_[1].value.pIdList)); }

    break;

  case 27:

    { (yylhs.value.pIdList) = new IdentifiersList(); }

    break;

  case 28:

    { (yylhs.value.pIdList) = new IdentifiersList(); (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue)); }

    break;

  case 29:

    { (yylhs.value.pIdList)->add(*(yystack_[0].value.pStrValue)); }

    break;

  case 30:

    { (yylhs.value.pStmtList) = new StatementsList(); }

    break;

  case 31:

    { (yylhs.value.pStmtList)->add((yystack_[0].value.pStmt)); }

    break;

  case 32:

    { (yylhs.value.pStmt) = (yystack_[0].value.pBlockStmt); }

    break;

  case 33:

    { (yylhs.value.pStmt) = (yystack_[0].value.pCondStmt); }

    break;

  case 34:

    { (yylhs.value.pStmt) = (yystack_[0].value.pLoopStmt); }

    break;

  case 35:

    { (yylhs.value.pStmt) = (yystack_[1].value.pAssgnStmt); }

    break;

  case 36:

    { (yylhs.value.pStmt) = (yystack_[1].value.pMCall); }

    break;

  case 37:

    { (yylhs.value.pStmt) = (yystack_[1].value.pReturnStmt); }

    break;

  case 38:

    { (yylhs.value.pStmt) = new BreakStatement(); }

    break;

  case 39:

    { (yylhs.value.pStmt) = new ContinueStatement(); }

    break;

  case 40:

    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }

    break;

  case 41:

    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("+=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }

    break;

  case 42:

    { (yylhs.value.pAssgnStmt) = new AssignmentStatement("-=", (yystack_[2].value.pLocation), (yystack_[0].value.pExpr)); }

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

    { (yylhs.value.pReturnStmt) = new ReturnStatement(NULL); }

    break;

  case 47:

    { (yylhs.value.pReturnStmt) = new ReturnStatement((yystack_[1].value.pExpr)); }

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

    { (yylhs.value.pCallArg) = new CalloutArgument((yystack_[0].value.pExpr)); }

    break;

  case 57:

    { (yylhs.value.pCallArg) = new CalloutArgument(*(yystack_[0].value.pStrValue)); }

    break;

  case 58:

    { (yylhs.value.pExpr) = (yystack_[0].value.pLocation); }

    break;

  case 59:

    { (yylhs.value.pExpr) = (yystack_[0].value.pLit); }

    break;

  case 60:

    { (yylhs.value.pExpr) = (yystack_[0].value.pMCall); }

    break;

  case 61:

    { (yylhs.value.pExpr) = (yystack_[0].value.pBExpr); }

    break;

  case 62:

    { (yylhs.value.pExpr) = (yystack_[0].value.pUExpr); }

    break;

  case 63:

    { (yylhs.value.pExpr) = new EnclosedExpression((yystack_[1].value.pExpr)); }

    break;

  case 64:

    { (yylhs.value.pLocation) = new VariableLocation(*(yystack_[0].value.pStrValue)); }

    break;

  case 65:

    { (yylhs.value.pLocation) = new VariableLocation(*(yystack_[3].value.pStrValue), (yystack_[1].value.pExpr)); }

    break;

  case 66:

    { (yylhs.value.pLit) = (yystack_[0].value.pIntLit); }

    break;

  case 67:

    { (yylhs.value.pLit) = (yystack_[0].value.pHexLit); }

    break;

  case 68:

    { (yylhs.value.pLit) = (yystack_[0].value.pBoolLit); }

    break;

  case 69:

    { (yylhs.value.pLit) = (yystack_[0].value.pCharLit); }

    break;

  case 70:

    { (yylhs.value.pBoolLit) = new BooleanLiteral("true"); }

    break;

  case 71:

    { (yylhs.value.pBoolLit) = new BooleanLiteral("false"); }

    break;

  case 72:

    { (yylhs.value.pIntLit) = new IntegerLiteral((yystack_[0].value.iValue)); }

    break;

  case 73:

    { (yylhs.value.pHexLit) = new HexadecimalLiteral((yystack_[0].value.hexValue)); }

    break;

  case 74:

    { (yylhs.value.pCharLit) = new CharacterLiteral((yystack_[0].value.cValue)); }

    break;

  case 75:

    { (yylhs.value.pBExpr) = new BinaryExpression("+", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 76:

    { (yylhs.value.pBExpr) = new BinaryExpression("-", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 77:

    { (yylhs.value.pBExpr) = new BinaryExpression("*", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 78:

    { (yylhs.value.pBExpr) = new BinaryExpression("/", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 79:

    { (yylhs.value.pBExpr) = new BinaryExpression("%", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 80:

    { (yylhs.value.pBExpr) = new BinaryExpression("<", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 81:

    { (yylhs.value.pBExpr) = new BinaryExpression(">", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 82:

    { (yylhs.value.pBExpr) = new BinaryExpression("==", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 83:

    { (yylhs.value.pBExpr) = new BinaryExpression(">=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 84:

    { (yylhs.value.pBExpr) = new BinaryExpression("<=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 85:

    { (yylhs.value.pBExpr) = new BinaryExpression("!=", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 86:

    { (yylhs.value.pBExpr) = new BinaryExpression("&&", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 87:

    { (yylhs.value.pBExpr) = new BinaryExpression("||", (yystack_[2].value.pExpr), (yystack_[0].value.pExpr)); }

    break;

  case 88:

    { (yylhs.value.pUExpr) = new UnaryExpression("-", (yystack_[0].value.pExpr)); }

    break;

  case 89:

    { (yylhs.value.pUExpr) = new UnaryExpression("!", (yystack_[0].value.pExpr)); }

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
       6,    -2,    19,   -17,   -84,   -84,    65,    14,    82,    93,
     -84,    46,    98,   -21,   -13,   -84,    26,    -5,    72,   -84,
     122,   124,   -84,    47,    76,   142,   -84,    76,   -84,    76,
      88,   112,   -84,   -84,   115,   116,   145,   146,   -20,   -84,
     134,   -84,   -19,   -18,   -84,   -84,   -84,   -84,    76,   138,
     138,   138,   -84,   -84,   -84,   -84,   -84,   141,   163,   163,
     -84,    70,   -84,     0,    20,   135,   136,   166,   157,   158,
     156,    94,   -84,   -84,   -84,   162,   -84,   -84,   190,   191,
      61,   167,   -84,   -84,   164,    23,   179,   -84,   -84,    23,
      23,    23,   -84,   -84,   -84,    23,    23,    23,   -84,   250,
     -84,   -84,   -84,    23,    23,    23,   -84,    95,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    23,   117,   161,    -8,
     210,   210,   210,   210,    54,   -84,   -84,   139,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,   138,   181,   -84,   -84,    23,   -84,   -84,    -6,   -84,
     210,   -84,   222,   233,    71,    71,    60,    60,    60,    60,
      99,    99,   -84,   -84,   -84,   268,    23,   210,    54,   -84,
     138,   194,   -84,   -84,   -84
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
       0,     0,    25,    26,     0,     0,     0,    38,    39,     0,
       0,    50,    35,    37,    36,     0,     0,     0,    29,     0,
      70,    71,    74,     0,     0,     0,    60,     0,    58,    59,
      68,    66,    67,    69,    61,    62,     0,     0,     0,     0,
      51,    41,    42,    40,    53,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    65,     0,    48,    57,     0,    54,
      56,    63,    87,    86,    82,    85,    80,    84,    81,    83,
      75,    76,    77,    78,    79,    43,     0,    52,     0,    49,
       0,     0,    55,    44,    45
  };

  const short
  Parser::yypgoto_[] =
  {
     -84,   -84,   -84,   -84,   267,   251,   265,   -84,    89,   230,
     -50,   -84,   -84,   220,   -84,   -84,   -84,   -84,   -84,   -84,
     219,   -84,   -84,   113,   -83,   221,   -84,   -84,   260,   261,
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
      55,    56,   107,    48,    48,    48,   117,   118,   120,     1,
      25,    73,   121,   122,   123,   145,     3,   168,    25,     4,
     125,   126,   127,    81,    23,     5,    24,    65,    49,    50,
      51,    26,    13,   142,   100,   101,    32,    33,   102,    28,
     146,    71,   169,    81,    82,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    65,   103,
      32,    33,   167,   104,    83,   100,   101,    32,    33,   102,
     105,    23,    71,    27,    65,    66,   147,    67,    68,    69,
      70,     7,     8,   171,     9,    95,    96,    97,    71,    19,
     103,   165,    36,    37,   104,   136,   137,   138,   139,   140,
      16,   105,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    18,    53,    72,    20,    21,    42,     9,    43,    29,
     173,   174,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    24,   138,   139,   140,    90,
      30,    91,    31,   141,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    58,    59,    27,
      40,    44,    45,    46,    47,   143,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    23,
      53,    62,    84,    85,    86,    98,    99,   151,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    87,    88,    89,   166,   116,    92,   144,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    93,    94,    53,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   124,   170,    17,    41,    22,    52,    64,
      79,   172,    80,    34,    35
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      50,    51,    85,    23,    23,    23,    89,    90,    91,     3,
      23,    61,    95,    96,    97,    23,    18,    23,    23,     0,
     103,   104,   105,    23,    45,    42,    47,     4,    48,    48,
      48,    44,    18,   116,    11,    12,    13,    14,    15,    44,
      48,    18,    48,    23,    44,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     4,    36,
      13,    14,   145,    40,    44,    11,    12,    13,    14,    15,
      47,    45,    18,    47,     4,     5,    22,     7,     8,     9,
      10,    16,    17,   166,    19,    24,    25,    26,    18,    43,
      36,   141,    16,    17,    40,    35,    36,    37,    38,    39,
      18,    47,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    18,    42,    43,    16,    17,    27,    19,    29,    47,
     170,   171,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    47,    37,    38,    39,    45,
      18,    47,    18,    48,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    16,    17,    47,
      18,    46,    46,    18,    18,    48,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    45,
      42,    18,    47,    47,    18,    18,    22,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    44,    44,    47,    23,    26,    44,    46,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    44,    44,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    23,     6,     8,    25,    12,    48,    59,
      61,   168,    61,    23,    23
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
      74,    23,    44,    44,    47,    47,    18,    44,    44,    47,
      45,    47,    44,    44,    44,    24,    25,    26,    18,    22,
      11,    12,    15,    36,    40,    47,    69,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    26,    73,    73,    70,
      73,    73,    73,    73,    23,    73,    73,    73,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    48,    73,    48,    46,    23,    48,    22,    71,    72,
      73,    48,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    59,    23,    73,    23,    48,
       6,    73,    72,    59,    59
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
       3,     3,     3,     5,     7,     7,     1,     4,     4,     6,
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
       0,   138,   138,   146,   149,   156,   160,   167,   172,   179,
     180,   181,   186,   189,   197,   201,   205,   213,   216,   221,
     229,   233,   241,   247,   250,   257,   258,   261,   262,   263,
     267,   268,   272,   273,   274,   275,   276,   277,   278,   279,
     283,   284,   285,   289,   293,   300,   305,   306,   310,   314,
     321,   324,   329,   336,   339,   344,   351,   352,   356,   357,
     358,   359,   360,   361,   365,   366,   370,   371,   372,   373,
     377,   378,   379,   380,   381,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   401,   402
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
