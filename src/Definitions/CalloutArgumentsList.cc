
#include <string>
#include "CalloutArgumentsList.hh"
using namespace std;


void CalloutArgumentsList::add(class CalloutArgument* pCalloutArgParm)
{
    mCalloutArgsList.push_back(pCalloutArgParm);
}


vector<class CalloutArgument*>
CalloutArgumentsList::getCalloutArgsList()
{
    return mCalloutArgsList;
}

void CalloutArgumentsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
