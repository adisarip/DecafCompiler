
#include <string>
#include <vector>
#include "FieldDeclaration.hh"
using namespace std;


FieldDeclaration::FieldDeclaration(string dataTypeParm,
                                   class VariablesList* pVariablesListParm)
:mDataType(dataTypeParm)
{
    mVariablesList = pVariablesListParm->getVariablesList();
}


void FieldDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
