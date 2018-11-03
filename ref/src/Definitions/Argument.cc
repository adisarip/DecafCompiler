
#include <string>
#include "Argument.hh"
using namespace std;


Argument::Argument(string argNameParm,
                   string argTypeParm)
:mArgName(argNameParm)
,mArgType(argTypeParm)
{
}


string Argument::getArgName()
{
    return mArgName;
}


string Argument::getArgType()
{
    return mArgType;
}


void Argument::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

