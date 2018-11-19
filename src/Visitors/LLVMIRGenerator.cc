
#include <iostream>
#include <string>
#include <vector>
#include "LLVMIRGenerator.hh"
using namespace std;
using namespace llvm;

/* All the visit() functions in this class is for LLVM IR generation */

LLVMIRGenerator::LLVMIRGenerator()
{
    mLlvmConstructsPtr = new LLVMConstructs();
}

void LLVMIRGenerator::visit(Program& nodeParm)
{
    cout << "IR: Program" << endl;

    //cout << "Program Name: " << nodeParm.getProgamName() << endl;
    class FieldDeclarationsList* pFieldsList = nodeParm.getFieldDeclarationsListPtr();
    class MethodDeclarationsList* pMethodsList = nodeParm.getMethodDeclarationsListPtr();

    if (pFieldsList)
    {
        pFieldsList->accept(*this);
    }
    else
    {
        logError("FieldDeclarationsList Pointer in NULL");
    }

    if (pMethodsList)
    {
        pMethodsList->accept(*this);
    }
    else
    {
        logError("MethodDeclarationsList Pointer in NULL");
    }
}


void LLVMIRGenerator::visit(FieldDeclarationsList& nodeParm)
{
    cout << "IR: Field Declaration List" << endl;
    typedef vector<class FieldDeclaration*> FDList;
    FDList sFieldDeclList = nodeParm.getFieldDeclarationsList();

    for (FDList::iterator it = sFieldDeclList.begin();
         it != sFieldDeclList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void LLVMIRGenerator::visit(FieldDeclaration& nodeParm)
{
    cout << "IR:    Field Declaration:" << endl;

    mDeclTypePtr = NULL;
    class VariablesList* pVariablesList = NULL;
    string sDataType = nodeParm.getDataType();

    if (sDataType == "int")
    {
        mDeclTypePtr = Type::getInt32Ty(mLlvmConstructsPtr->mContext);
    }
    else if (sDataType == "boolean")
    {
        mDeclTypePtr = Type::getInt1Ty(mLlvmConstructsPtr->mContext);
    }
    else
    {
        logError("[ERROR] Invalid Type. Supported Types: 'int' and 'boolean' only.");
    }

    pVariablesList = nodeParm.getVariablesListPtr();
    if (pVariablesList)
    {
        pVariablesList->accept(*this);
    }
}


void LLVMIRGenerator::visit(VariablesList& nodeParm)
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


void LLVMIRGenerator::visit(Variable& nodeParm)
{
    cout << "IR:    Field Declaration Variable" << endl;

    ArrayType* pArrType = NULL;
    GlobalVariable* pGVar = NULL;

    if (Variable::ARRAY_DECLARATION == nodeParm.getDeclarationType())
    {
        pArrType = ArrayType::get(mDeclTypePtr,
                                  nodeParm.getArraySize());
        pGVar = new GlobalVariable(*mLlvmConstructsPtr->mModulePtr,
                                    pArrType,
                                    false,
                                    GlobalValue::ExternalLinkage,
                                    NULL,
                                    nodeParm.getVariableName());
        pGVar->setInitializer(ConstantAggregateZero::get(pArrType));
    }
    else
    {
        pGVar = new GlobalVariable(*mLlvmConstructsPtr->mModulePtr,
                                    mDeclTypePtr,
                                    false,
                                    GlobalValue::ExternalLinkage,
                                    NULL,
                                    nodeParm.getVariableName());
        pGVar->setInitializer(Constant::getNullValue(mDeclTypePtr));
    }
}


void LLVMIRGenerator::visit(MethodDeclarationsList& nodeParm)
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


void LLVMIRGenerator::visit(MethodDeclaration& nodeParm)
{
    cout << "    Method Declaration: " << nodeParm.getReturnType()
         << ":" << nodeParm.getMethodName() << endl;
    nodeParm.getParmsListPtr()->accept(*this);
    nodeParm.getBlockStmtPtr()->accept(*this);
}


void LLVMIRGenerator::visit(ParametersList& nodeParm)
{
    typedef vector<class Parameter*> Parm;
    Parm sParmsList = nodeParm.getParametersList();

    for (Parm::iterator it = sParmsList.begin();
         it != sParmsList.end();
         it++)
    {
        (*it)->accept(*this);
    }
}


void LLVMIRGenerator::visit(Parameter& nodeParm)
{
    cout << "      Parameter:" << nodeParm.getType()
         << ":" <<  nodeParm.getName() << endl;
}


void LLVMIRGenerator::visit(BlockStatement& nodeParm)
{
    cout << "      Block Statement: " << endl;
    nodeParm.getVarDeclListPtr()->accept(*this);
    nodeParm.getStmtListPtr()->accept(*this);
}


void LLVMIRGenerator::visit(VariableDeclarationsList& nodeParm)
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


void LLVMIRGenerator::visit(VariableDeclaration& nodeParm)
{
    cout << "          Type: " << nodeParm.getDeclarationType() << endl;
    nodeParm.getIdListPtr()->accept(*this);
}


void LLVMIRGenerator::visit(IdentifiersList& nodeParm)
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


void LLVMIRGenerator::visit(StatementsList& nodeParm)
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


void LLVMIRGenerator::visit(AssignmentStatement& nodeParm)
{
    cout << "      Assignment Stmt: " << nodeParm.getAssignmentOp() << endl;
    nodeParm.getLocationPtr()->accept(*this);
    nodeParm.getAssignmentExprPtr()->accept(*this);
}


void LLVMIRGenerator::visit(VariableLocation& nodeParm)
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


void LLVMIRGenerator::visit(IfElseStatement& nodeParm)
{
    cout << "    If Else Statement:" << endl;
    nodeParm.getCondExprPtr()->accept(*this);
    if (nodeParm.getCondExprPtr())
    {
        nodeParm.getCondExprPtr()->accept(*this);
    }
    if (nodeParm.getIfBlockPtr())
    {
        nodeParm.getIfBlockPtr()->accept(*this);
    }
    if (nodeParm.getElseBlockPtr())
    {
        nodeParm.getElseBlockPtr()->accept(*this);
    }
}


void LLVMIRGenerator::visit(ForStatement& nodeParm)
{
    cout << "    For Statement:" << endl;
    cout << "      Init Value: " << nodeParm.getInitValue() << endl;

    if (nodeParm.getInitExprPtr())
    {
        nodeParm.getInitExprPtr()->accept(*this);
    }
    if (nodeParm.getCondExprPtr())
    {
        nodeParm.getCondExprPtr()->accept(*this);
    }
    if (nodeParm.getForBlockPtr())
    {
        nodeParm.getForBlockPtr()->accept(*this);
    }
}


void LLVMIRGenerator::visit(ReturnStatement& nodeParm)
{
    cout << "      RETURN:" << nodeParm.hasReturnValue() << endl;
    //nodeParm.getReturnExprPtr()->accept(*this);
}


void LLVMIRGenerator::visit(BreakStatement& nodeParm)
{
    cout << "     BREAK: " << nodeParm.hasReturnValue() << endl;
}


void LLVMIRGenerator::visit(ContinueStatement& nodeParm)
{
    cout << "     CONTINUE:" << nodeParm.hasReturnValue() << endl;
}


void LLVMIRGenerator::visit(UserDefinedMethodCall& nodeParm)
{
    cout << "    User Defined Function: " << nodeParm.getMethodName() << endl;
    nodeParm.getArgsListPtr()->accept(*this);
}


void LLVMIRGenerator::visit(ExpressionsList& nodeParm)
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


void LLVMIRGenerator::visit(CalloutMethodCall& nodeParm)
{
    cout << "      Callout : " << nodeParm.getMethodName() << endl;
    nodeParm.getCalloutArgsListPtr()->accept(*this);
}


void LLVMIRGenerator::visit(CalloutArgumentsList& nodeParm)
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


void LLVMIRGenerator::visit(CalloutArgument& nodeParm)
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


void LLVMIRGenerator::visit(UnaryExpression& nodeParm)
{
    cout << "      Unary Expression:" << nodeParm.getUnaryOperator() << endl;
    nodeParm.getRightExprPtr()->accept(*this);
}


void LLVMIRGenerator::visit(BinaryExpression& nodeParm)
{
    cout << "      Binary Expression:" << nodeParm.getBinOperator() << endl;
    nodeParm.getLeftExprPtr()->accept(*this);
    nodeParm.getRightExprPtr()->accept(*this);
}


void LLVMIRGenerator::visit(EnclosedExpression& nodeParm)
{
    cout << "      Enclosed Expression:" << endl;
    nodeParm.getExprPtr()->accept(*this);
}


void LLVMIRGenerator::visit(IntegerLiteral& nodeParm)
{
    cout << "        Integer Literal: " << nodeParm.getValue() << endl;
}


void LLVMIRGenerator::visit(BooleanLiteral& nodeParm)
{
    cout << "        Boolean Literal:" << nodeParm.getValue() << endl;
}


void LLVMIRGenerator::visit(HexadecimalLiteral& nodeParm)
{
    cout << "        Hexadecimal Literal:" << nodeParm.getHexValue() << endl;
}


void LLVMIRGenerator::visit(CharacterLiteral& nodeParm)
{
    cout << "        Character Literal:" << nodeParm.getCharValue() << endl;
}

