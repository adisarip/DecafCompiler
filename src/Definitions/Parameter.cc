
#include <string>
#include "Parameter.hh"
using namespace std;


Parameter::Parameter(string typeParm,
                     string nameParm)
:mType(typeParm)
,mName(nameParm)
{
}


string Parameter::getType()
{
    return mType;
}


string Parameter::getName()
{
    return mName;
}


void Parameter::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

