
#include <vector>
#include "ParametersList.hh"
using namespace std;


void ParametersList::add(class Parameter* pParameterParm)
{
    mParmsList.push_back(pParameterParm);
}


vector<class Parameter*> ParametersList::getParametersList()
{
    return mParmsList;
}


void ParametersList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

