
#include "CharacterLiteral.hh"
using namespace std;


CharacterLiteral::CharacterLiteral(char charValueParm)
:mCharValue(charValueParm)
{
    mLiteralType = Literal::CHARACTER;
}

void CharacterLiteral::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
