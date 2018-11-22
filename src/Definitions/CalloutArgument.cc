
#include <string>
#include "CalloutArgument.hh"
using namespace std;


CalloutArgument::CalloutArgument(string calloutArgStringParm)
:mCalloutExprPtr(NULL)
{
    mArgType = CalloutArgument::STRING;
    mCalloutArgString = calloutArgStringParm.substr(1, calloutArgStringParm.length()-2);
}


CalloutArgument::CalloutArgument(class Expression* pCalloutExprParm)
:mCalloutArgString("")
,mCalloutExprPtr(pCalloutExprParm)
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
