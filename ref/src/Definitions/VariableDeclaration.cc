
#include <string>
#include <vector>
#include "VariableDeclaration.hh"
using namespace std;


VariableDeclaration::VariableDeclaration(string declarationTypeParm,
                                         class IdentifiersList* pIdListParm)
:mDeclarationType(declarationTypeParm)
{
    vector<string> sVarList;
    for (auto& s : sVarList)
    {
        add(s);
    }
}


void VariableDeclaration::add(string variableParm)
{
    mVariablesList.push_back(variableParm);
}


void VariableDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
