
#include "UnaryExpression.hh"

/* UnaryExpression - Definitions */

UnaryExpression::UnaryExpression(std::string unaryOperatorParm,
                           Expression* mRightExprParm)
:mUnaryOperator(unaryOperatorParm)
,mRightExprPtr(mRightExprParm)
{
    mExprType = Expression::UNARY;
}

Expression* UnaryExpression::getRightExprPtr()
{
    return mRightExprPtr;
}

std::string UnaryExpression::getUnaryOperator()
{
    return mUnaryOperator;
}

void UnaryExpression::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
