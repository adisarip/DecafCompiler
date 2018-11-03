
#include "StringLiteral.hh"
using namespace std;


StringLiteral::StringLiteral(string stringValueParm)
:mStringValue(stringValueParm)
{
    mLiteralType = Literal::STRING;
}


void StringLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
