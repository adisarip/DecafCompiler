
#include <string>
#include "BooleanLiteral.hh"
using namespace std;

BooleanLiteral::BooleanLiteral(string boolValueParm)
:mBoolValue(boolValueParm)
{
    mLiteralType = Literal::BOOLEAN;
}

void BooleanLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
