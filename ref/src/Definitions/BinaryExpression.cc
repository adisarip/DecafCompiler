
#include "BinaryExpression.hh"


/* BinaryExpression - Definitions */

BinaryExpression::BinaryExpression(std::string binOperatorParm,
                                   Expression* pLeftExprParm,
                                   Expression* pRighExprParm)
:mBinaryOperator(binOperatorParm)
,mLeftExprPtr(pLeftExprParm)
,mRightExprPtr(pRighExprParm)
{
    mExprType = Expression::BINARY;
}

Expression* BinaryExpression::getLeftExprPtr()
{
    return mLeftExprPtr;
}

Expression* BinaryExpression::getRightExprPtr()
{
    return mRightExprPtr;
}

std::string BinaryExpression::getBinOperator()
{
    return mBinaryOperator;
}

void BinaryExpression::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

