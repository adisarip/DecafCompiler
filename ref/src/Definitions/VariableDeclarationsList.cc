
#include <vector>
#include "VariableDeclarationsList.hh"
using namespace std;


void VariableDeclarationsList::add(class VariableDeclaration* pVariableDeclParm)
{
    mVariableDeclList.push_back(pVariableDeclParm);
}


vector<class VariableDeclaration*>
VariableDeclarationsList::getVariableDeclList()
{
    return mVariableDeclList;
}


void VariableDeclarationsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
