
#include <string>
#include "CalloutArgument.hh"
using namespace std;


CalloutArgument::CalloutArgument(string calloutArgStringParm)
:mCalloutArgString(calloutArgStringParm)
{
    mArgType = CalloutArgument::STRING;
}


CalloutArgument::CalloutArgument(class Expression* pCalloutExprParm)
:mCalloutExprPtr(pCalloutExprParm)
{
    mArgType = CalloutArgument::EXPRESSION;
}


string CalloutArgument::getCalloutArgString()
{
    return mCalloutArgString;
}


Expression* CalloutArgument::getCalloutExprPtr()
{
    return mCalloutExprPtr;
}

CalloutArgument::CalloutArgumentType
CalloutArgument::getArgType()
{
    return mArgType;
}


void CalloutArgument::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
