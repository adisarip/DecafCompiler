
#include <string>
#include <vector>
#include "FieldDeclaration.hh"
using namespace std;


FieldDeclaration::FieldDeclaration(string dataTypeParm,
                                   class VariablesList* pVariablesListParm)
:mDataType(dataTypeParm)
,mVariablesListPtr(pVariablesListParm)
{
}


string FieldDeclaration::getDataType()
{
    return mDataType;
}


class VariablesList* FieldDeclaration::getVariablesListPtr()
{
    return mVariablesListPtr;
}


void FieldDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
