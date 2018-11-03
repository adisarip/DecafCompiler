
#include <string>
#include "ForStatement.hh"
using namespace std;


ForStatement::ForStatement(string initValueParm,
                           class Expression* pInitExprParm,
                           class Expression* pCondExprParm,
                           class BlockStatement* pForBlockParm)
:mInitValue(initValueParm)
,mInitExprPtr(pInitExprParm)
,mCondExprPtr(pCondExprParm)
,mForBlockPtr(pForBlockParm)
{
    mStmtType = Statement::NON_RETURNING;
}


bool ForStatement::hasReturnValue()
{
    return mForBlockPtr->hasReturnValue();
}


void ForStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
