
#include <string>
#include "ReturnStatement.hh"
using namespace std;


ReturnStatement::ReturnStatement(class Expression* pReturnExprParm)
:mReturnExprPtr(pReturnExprParm)
{
    mStmtType = Statement::RETURNING;
}


bool ReturnStatement::hasReturnValue()
{
    return true;
}


Expression* ReturnStatement::getReturnExprPtr()
{
    return mReturnExprPtr;
}


void ReturnStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
