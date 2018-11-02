
#include "UnaryExpression.hh"

/* UnaryExpression - Definitions */

UnaryExpression::UnaryExpression(std::string unaryOperatorParm,
                           Expression* mRightPtrParm)
:mUnaryOperator(unaryOperatorParm)
,mRightPtr(mRightPtrParm)
{
}

Expression* UnaryExpression::getRight()
{
    return mRightPtr;
}

std::string UnaryExpression::getUnaryOperator()
{
    return mUnaryOperator;
}

void UnaryExpression::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
