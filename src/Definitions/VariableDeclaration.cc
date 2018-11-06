
#include <string>
#include <vector>
#include "VariableDeclaration.hh"
using namespace std;


VariableDeclaration::VariableDeclaration(string declarationTypeParm,
                                         class IdentifiersList* pIdListParm)
:mDeclarationType(declarationTypeParm)
{
    vector<string> sVarList = pIdListParm->getIdList();
    for (auto& s : sVarList)
    {
        add(s);
    }
}


string VariableDeclaration::getDeclarationType()
{
    return mDeclarationType;
}


vector<string> VariableDeclaration::getVariablesList()
{
    return mVariablesList;
}


void VariableDeclaration::add(string variableParm)
{
    mVariablesList.push_back(variableParm);
}


void VariableDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
