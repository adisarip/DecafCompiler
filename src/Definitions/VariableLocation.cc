
#include <string>
#include "VariableLocation.hh"
using namespace std;


VariableLocation::VariableLocation(string variableNameParm)
:mVariableName(variableNameParm)
{
    mLocationType = VariableLocation::VARIABLE;
    mExprType = Expression::LOCATION;
}


VariableLocation::VariableLocation(string variableNameParm,
                                    class Expression* pArrayIndexParm)
:mVariableName(variableNameParm)
,mArrayIndexPtr(pArrayIndexParm)
{
    mLocationType = VariableLocation::ARRAY;
    mExprType = Expression::LOCATION;
}


VariableLocation::LocationType
VariableLocation::getLocationType()
{
    return mLocationType;
}


string VariableLocation::getVariableName()
{
    return mVariableName;
}


Expression* VariableLocation::getArrayIndexPtr()
{
    return mArrayIndexPtr;
}


void VariableLocation::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
