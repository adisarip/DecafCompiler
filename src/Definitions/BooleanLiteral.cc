
#include <string>
#include "BooleanLiteral.hh"
using namespace std;

BooleanLiteral::BooleanLiteral(string boolValueParm)
:mBoolValue(boolValueParm)
{
    mLiteralType = Literal::BOOLEAN;
}

string BooleanLiteral::getBoolValue()
{
    return mBoolValue;
}

void BooleanLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
