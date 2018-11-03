
#include <vector>
#include "IfElseStatement.hh"
using namespace std;

IfElseStatement::IfElseStatement(class Expression* pCondExprParm,
                                 class BlockStatement* pIfBlockParm,
                                 class BlockStatement* pElseBlockParm)
:mCondExprPtr(pCondExprParm)
,mIfBlockPtr(pIfBlockParm)
,mElseBlockPtr(pElseBlockParm)
{
    mStmtType = Statement::NON_RETURNING;
}


bool IfElseStatement::hasReturnValue()
{
    bool sStatus = false;

    if ((mIfBlockPtr != NULL && mIfBlockPtr->hasReturnValue() == true) ||
        (mElseBlockPtr != NULL && mElseBlockPtr->hasReturnValue() == true))
    {
        sStatus = true;
    }

    return sStatus;
}


void IfElseStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
