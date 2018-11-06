
#include "IntegerLiteral.hh"
using namespace std;


IntegerLiteral::IntegerLiteral(int intValueParm)
:mIntValue(intValueParm)
{
    mLiteralType = Literal::INTEGER;
}


int IntegerLiteral::getValue()
{
    return mIntValue;
}


void IntegerLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

