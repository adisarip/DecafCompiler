
#include <vector>
#include "VariablesList.hh"
using namespace std;


void VariablesList::add(class Variable* pVariableParm)
{
    mVariableList.push_back(pVariableParm);
}


vector<class Variable*> VariablesList::getVariablesList()
{
    return mVariableList;
}


void VariablesList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
