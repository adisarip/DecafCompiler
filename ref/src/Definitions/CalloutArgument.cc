
#include <string>
#include "CalloutArgument.hh"
using namespace std;


CalloutArgument::CalloutArgument(string calloutArgStringParm)
:mCalloutArgString(calloutArgStringParm)
{
}


CalloutArgument::CalloutArgument(class Expression* pCalloutExprParm)
:mCalloutExprPtr(pCalloutExprParm)
{
}


string CalloutArgument::getCalloutArgString()
{
    return mCalloutArgString;
}


Expression* CalloutArgument::getCalloutExprPtr()
{
    return mCalloutExprPtr;
}


void CalloutArgument::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
