
#include <string>
#include "CalloutMethodCall.hh"
using namespace std;


CalloutMethodCall:: CalloutMethodCall(string methodNameParm,
                                      class CalloutArgumentsList* pCalloutArgsListParm)
:mCalloutArgsListPtr(pCalloutArgsListParm)
{
}
    
void CalloutMethodCall::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

