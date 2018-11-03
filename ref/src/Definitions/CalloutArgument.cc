
#include <string>
#include "CalloutArgument.hh"
using namespace std;


CalloutArgument::CalloutArgument(string stringLiteralParm)
:mStringLiteral(stringLiteralParm)
{
}


CalloutArgument::CalloutArgument(class Expression* pCalloutExprParm)
:mCalloutExprPtr(pCalloutExprParm)
{
}

void CalloutArgument::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
