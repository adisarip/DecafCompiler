
#include <string>
#include "EnclosedExpression.hh"


EnclosedExpression::EnclosedExpression(class Expression* pExprParm)
:mExprPtr(pExprParm)
{
    mExprType = Expression::ENCLOSED_EXPR;
}


Expression* EnclosedExpression::getExprPtr()
{
    return mExprPtr;
}


void EnclosedExpression::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
