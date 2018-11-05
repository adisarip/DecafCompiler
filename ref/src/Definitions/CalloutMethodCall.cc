
#include <string>
#include "CalloutMethodCall.hh"
using namespace std;


CalloutMethodCall:: CalloutMethodCall(string methodNameParm,
                                      class CalloutArgumentsList* pCalloutArgsListParm)
:mCalloutArgsListPtr(pCalloutArgsListParm)
{
    mMethodName = methodNameParm;
}
    
void CalloutMethodCall::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

