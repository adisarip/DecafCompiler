
#include "HexadecimalLiteral.hh"
using namespace std;


HexadecimalLiteral::HexadecimalLiteral(long int hexValueParm)
:mHexValue(hexValueParm)
{
    mLiteralType = Literal::HEXADECIMAL;
}


long int HexadecimalLiteral::getHexValue()
{
    return mHexValue;
}


void HexadecimalLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

