
#include "CharacterLiteral.hh"
using namespace std;


CharacterLiteral::CharacterLiteral(char charValueParm)
:mCharValue(charValueParm)
{
    mLiteralType = Literal::CHARACTER;
}


char CharacterLiteral::getCharValue()
{
    return mCharValue;
}


void CharacterLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
