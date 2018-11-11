
#include <iostream>
#include <string>
#include <vector>
#include "AstVisitor.hh"
using namespace std;


void AstVisitor::visit(Program& nodeParm)
{
    cout << "================= Program Info =================\n" << endl;
    cout << "Program Name: " << nodeParm.getProgamName() << endl;
    nodeParm.getFieldDeclarationsList()->accept(*this);
    nodeParm.getMethodDeclarationsList()->accept(*this);
}


void AstVisitor::visit(FieldDeclarationsList& nodeParm)
{
    cout << "  Field Declaration List" << endl;
    typedef vector<class FieldDeclaration*> FDList;
    FDList sFieldDeclList = nodeParm.getFieldDeclarationsList();

    for (FDList::iterator it = sFieldDeclList.begin();
         it != sFieldDeclList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(FieldDeclaration& nodeParm)
{
    cout << "    Field Declaration: " << nodeParm.getDataType() << endl;
    nodeParm.getVariablesListPtr()->accept(*this);
}


void AstVisitor::visit(VariablesList& nodeParm)
{
    typedef vector<class Variable*> VList;
    VList sVariablesList = nodeParm.getVariablesList();

    for (VList::iterator it = sVariablesList.begin();
         it != sVariablesList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(Variable& nodeParm)
{
    cout << "    Field Declaration Variable: " << nodeParm.getVariableName() << endl;
    if (nodeParm.getDeclarationType() == Variable::ARRAY_DECLARATION)
    {
        cout << "      Array Size: " << nodeParm.getArraySize() << endl;
    }
}


void AstVisitor::visit(MethodDeclarationsList& nodeParm)
{
    cout << "  Method Declaration List" << endl;
    typedef vector<class MethodDeclaration*> MDList;
    MDList sMethodDeclList = nodeParm.getMethodDeclList();

    for (MDList::iterator it = sMethodDeclList.begin();
         it != sMethodDeclList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(MethodDeclaration& nodeParm)
{
    cout << "    Method Declaration: " << nodeParm.getReturnType()
         << ":" << nodeParm.getMethodName() << endl;
    nodeParm.getArgsListPtr()->accept(*this);
    nodeParm.getBlockStmtPtr()->accept(*this);
}


void AstVisitor::visit(ArgumentsList& nodeParm)
{
    typedef vector<class Argument*> Arg;
    Arg sArgsList = nodeParm.getArgumentsList();

    for (Arg::iterator it = sArgsList.begin();
         it != sArgsList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(Argument& nodeParm)
{
    cout << "      Argument:" << nodeParm.getArgType()
         << ":" <<  nodeParm.getArgName() << endl;
}


void AstVisitor::visit(BlockStatement& nodeParm)
{
    cout << "      Block Statement: " << endl;
    nodeParm.getVarDeclListPtr()->accept(*this);
    nodeParm.getStmtListPtr()->accept(*this);
}


void AstVisitor::visit(VariableDeclarationsList& nodeParm)
{
    cout << "        Variables Declarations List:" << endl;
    typedef vector<class VariableDeclaration*> VDecl;
    VDecl sVariableDeclList = nodeParm.getVariableDeclList();

    for (VDecl::iterator it = sVariableDeclList.begin();
         it != sVariableDeclList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(VariableDeclaration& nodeParm)
{
    cout << "          Type: " << nodeParm.getDeclarationType() << endl;
    nodeParm.getIdListPtr()->accept(*this);
}


void AstVisitor::visit(IdentifiersList& nodeParm)
{
    cout << "          Identifiers: " << flush;
    vector<string> sIdList = nodeParm.getIdList();
    for (vector<string>::iterator it = sIdList.begin();
         it != sIdList.end();
         it++)
    {
        cout << *it << ", " << flush;
    }
    cout << endl;
}


void AstVisitor::visit(StatementsList& nodeParm)
{
    cout << "    Statements List:" << endl;
    typedef vector<class Statement*> StmtList;
    StmtList sStmtPtrList = nodeParm.getStmtPtrList();
    for (StmtList::iterator it = sStmtPtrList.begin();
         it != sStmtPtrList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(AssignmentStatement& nodeParm)
{
    cout << "      Assignment Stmt: " << nodeParm.getAssignmentOp() << endl;
    nodeParm.getLocationPtr()->accept(*this);
    nodeParm.getAssignmentExprPtr()->accept(*this);
}


void AstVisitor::visit(VariableLocation& nodeParm)
{
    cout << "      Location: " << nodeParm.getVariableName() << flush;
    if (VariableLocation::VARIABLE == nodeParm.getLocationType())
    {
        cout << " : VARIABLE" << endl;
    }
    else
    {
        cout << " : ARRAY" << endl;
        nodeParm.getArrayIndexPtr()->accept(*this);
    }
}


void AstVisitor::visit(IfElseStatement& nodeParm)
{
    cout << "    If Else Statement:" << endl;
    nodeParm.getCondExprPtr()->accept(*this);
    nodeParm.getIfBlockPtr()->accept(*this);
    nodeParm.getElseBlockPtr()->accept(*this);
}


void AstVisitor::visit(ForStatement& nodeParm)
{
    cout << "    For Statement:" << endl;
    cout << "      Init Value: " << nodeParm.getInitValue() << endl;
    nodeParm.getInitExprPtr()->accept(*this);
    nodeParm.getCondExprPtr()->accept(*this);
    nodeParm.getForBlockPtr()->accept(*this);
}


void AstVisitor::visit(ReturnStatement& nodeParm)
{
    cout << "      RETURN:" << endl;
    nodeParm.getReturnExprPtr()->accept(*this);
}


void AstVisitor::visit(BreakStatement& nodeParm)
{
    cout << "     BREAK: " << nodeParm.hasReturnValue() << endl;
}


void AstVisitor::visit(ContinueStatement& nodeParm)
{
    cout << "     CONTINUE:" << nodeParm.hasReturnValue() << endl;
}


void AstVisitor::visit(UserDefinedMethodCall& nodeParm)
{
    cout << "    User Defined Function: " << nodeParm.getMethodName() << endl;
    nodeParm.getArgsListPtr()->accept(*this);
}


void AstVisitor::visit(ExpressionsList& nodeParm)
{
    cout << "      Expr List:" << endl;
    typedef vector<class Expression*> ExprList;
    ExprList sExprList = nodeParm.getExpressionsList();
    for (ExprList::iterator it = sExprList.begin();
         it != sExprList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(CalloutMethodCall& nodeParm)
{
    cout << "      Callout : " << nodeParm.getMethodName() << endl;
    nodeParm.getCalloutArgsListPtr()->accept(*this);
}


void AstVisitor::visit(CalloutArgumentsList& nodeParm)
{
    cout << "        Callout Args List:" << endl;
    typedef vector<class CalloutArgument*> CAList;
    CAList sCArgsList = nodeParm.getCalloutArgsList();
    for (CAList::iterator it = sCArgsList.begin();
         it != sCArgsList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void AstVisitor::visit(CalloutArgument& nodeParm)
{
    cout << "          Callout Arg:" <<  nodeParm.getCalloutArgString() << flush;
    if (CalloutArgument::STRING == nodeParm.getArgType())
    {
        cout << " : STRING" << endl;
    }
    else
    {
        cout << " : EXPRESSION" << endl;
        nodeParm.getCalloutExprPtr()->accept(*this);
    }
    
}


void AstVisitor::visit(UnaryExpression& nodeParm)
{
    cout << "      Unary Expression:" << nodeParm.getUnaryOperator() << endl;
    nodeParm.getRightExprPtr()->accept(*this);
}


void AstVisitor::visit(BinaryExpression& nodeParm)
{
    cout << "      Binary Expression:" << nodeParm.getBinOperator() << endl;
    nodeParm.getLeftExprPtr()->accept(*this);
    nodeParm.getRightExprPtr()->accept(*this);
}


void AstVisitor::visit(EnclosedExpression& nodeParm)
{
    cout << "      Enclosed Expression:" << endl;
    nodeParm.getExprPtr()->accept(*this);
}


void AstVisitor::visit(IntegerLiteral& nodeParm)
{
    cout << "        Integer Literal: " << nodeParm.getValue() << endl;
}


void AstVisitor::visit(BooleanLiteral& nodeParm)
{
    cout << "        Boolean Literal:" << nodeParm.getValue() << endl;
}


void AstVisitor::visit(HexadecimalLiteral& nodeParm)
{
    cout << "        Hexadecimal Literal:" << nodeParm.getHexValue() << endl;
}


void AstVisitor::visit(CharacterLiteral& nodeParm)
{
    cout << "        Character Literal:" << nodeParm.getCharValue() << endl;
}

