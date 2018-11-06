
#include <string>
#include "BooleanLiteral.hh"
using namespace std;

BooleanLiteral::BooleanLiteral(string boolValueParm)
:mBoolValue(boolValueParm)
{
    mLiteralType = Literal::BOOLEAN;
}

bool BooleanLiteral::getValue()
{
    bool sBoolValue = false;
    if (mBoolValue == "true")
    {
        sBoolValue = true;
    }
    return sBoolValue;
}

void BooleanLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
