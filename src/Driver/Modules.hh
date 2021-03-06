
/* Contains includes of all the modules implemented under decaf compiler */

#ifndef MODULES_H
#define MODULES_H

#include <string>

#include "Ast.hh"
#include "Program.hh"
#include "FieldDeclaration.hh"
#include "FieldDeclarationsList.hh"
#include "MethodDeclaration.hh"
#include "MethodDeclarationsList.hh"
#include "Parameter.hh"
#include "ParametersList.hh"
#include "Statement.hh"
#include "StatementsList.hh"
#include "BlockStatement.hh"
#include "AssignmentStatement.hh"
#include "IfElseStatement.hh"
#include "ForStatement.hh"
#include "ReturnStatement.hh"
#include "BreakStatement.hh"
#include "ContinueStatement.hh"
#include "MethodCall.hh"
#include "UserDefinedMethodCall.hh"
#include "CalloutMethodCall.hh"
#include "CalloutArgument.hh"
#include "CalloutArgumentsList.hh"
#include "Expression.hh"
#include "ExpressionsList.hh"
#include "UnaryExpression.hh"
#include "BinaryExpression.hh"
#include "EnclosedExpression.hh"
#include "Literal.hh"
#include "IntegerLiteral.hh"
#include "BooleanLiteral.hh"
#include "HexadecimalLiteral.hh"
#include "CharacterLiteral.hh"
#include "IdentifiersList.hh"
#include "Variable.hh"
#include "VariablesList.hh"
#include "VariableDeclaration.hh"
#include "VariableDeclarationsList.hh"
#include "VariableLocation.hh"


union Nodes
{
    int                             iValue;
    long int                        hexValue;
    char                            cValue;
    std::string*                    pStrValue;
    class Program*                  pProgram;
    class FieldDeclaration*         pField;
    class FieldDeclarationsList*    pFieldList;
    class Variable*                 pFieldVar;
    class VariablesList*            pFieldVarList;
    class MethodDeclaration*        pMDecl;
    class MethodDeclarationsList*   pMDeclList;
    class Parameter*                pParm;
    class ParametersList*           pParmList;
    class VariableDeclaration*      pVarDecl;
    class VariableDeclarationsList* pVarDeclList;
    class IdentifiersList*          pIdList;
    class Statement*                pStmt;
    class StatementsList*           pStmtList;
    class BlockStatement*           pBlockStmt;
    class IfElseStatement*          pCondStmt;
    class ForStatement*             pLoopStmt;
    class AssignmentStatement*      pAssgnStmt;
    class ReturnStatement*          pReturnStmt;
    class VariableLocation*         pLocation;
    class Expression*               pExpr;
    class ExpressionsList*          pExprList;
    class BinaryExpression*         pBExpr;
    class UnaryExpression*          pUExpr;
    class MethodCall*               pMCall;
    class CalloutArgument*          pCallArg;
    class CalloutArgumentsList*     pCallArgList;
    class Literal*                  pLit;
    class IntegerLiteral*           pIntLit;
    class BooleanLiteral*           pBoolLit;
    class HexadecimalLiteral*       pHexLit;
    class CharacterLiteral*         pCharLit;
};


#ifndef YYSTYPE
#define YYSTYPE Nodes
#endif


#endif /* MODULES_H */
