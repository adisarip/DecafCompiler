
#include <string>
#include "BlockStatement.hh"
using namespace std;


BlockStatement::BlockStatement(class VariableDeclarationsList* pVarDeclListParm,
                               class StatementsList* pStmtListParm)
:mVarDeclListPtr(pVarDeclListParm)
,mStmtListPtr(pStmtListParm)
{
    mStmtType = Statement::NON_RETURNING;
}


VariableDeclarationsList* BlockStatement::getVarDeclListPtr()
{
    return mVarDeclListPtr;
}


StatementsList* BlockStatement::getStmtListPtr()
{
    return mStmtListPtr;
}


bool BlockStatement::hasReturnValue()
{
    return mStmtListPtr->hasReturnValue();
}


void BlockStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
