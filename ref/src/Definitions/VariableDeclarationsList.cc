
#include <vector>
#include "VariableDeclarationsList.hh"
using namespace std;


void VariableDeclarationsList::add(class VariableDeclaration* pVariableDeclParm)
{
    mVariableDeclList.push_back(pVariableDeclParm);
}


void VariableDeclarationsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
