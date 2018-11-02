
#include "BinaryExpression.hh"


/* BinaryExpression - Definitions */

BinaryExpression::BinaryExpression(std::string binOperatorParm,
                             Expression* mLeftPtrParm,
                             Expression* mRightPtrParm)
:mBinaryOperator(binOperatorParm)
,mLeftPtr(mLeftPtrParm)
,mRightPtr(mRightPtrParm)
{
}

Expression* BinaryExpression::getLeft()
{
    return mLeftPtr;
}

Expression* BinaryExpression::getRight()
{
    return mRightPtr;
}

std::string BinaryExpression::getBinOperator()
{
    return mBinaryOperator;
}

void BinaryExpression::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

