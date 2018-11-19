
#include <string>
#include "Parameter.hh"
using namespace std;


Parameter::Parameter(string nameParm,
                   string typeParm)
:mName(nameParm)
,mType(typeParm)
{
}


string Parameter::getName()
{
    return mName;
}


string Parameter::getType()
{
    return mType;
}


void Parameter::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

