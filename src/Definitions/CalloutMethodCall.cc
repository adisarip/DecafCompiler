
#include <string>
#include "CalloutMethodCall.hh"
using namespace std;


CalloutMethodCall:: CalloutMethodCall(string methodNameParm,
                                      CalloutArgumentsList* pCalloutArgsListParm)
:mCalloutArgsListPtr(pCalloutArgsListParm)
{
    mMethodName = methodNameParm.substr(1, methodNameParm.length()-2);
}


string CalloutMethodCall::getMethodName()
{
    return mMethodName;
}


CalloutArgumentsList* CalloutMethodCall::getCalloutArgsListPtr()
{
    return mCalloutArgsListPtr;
}

    
void CalloutMethodCall::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

