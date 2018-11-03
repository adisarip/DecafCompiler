
#include <vector>
#include "ArgumentsList.hh"
using namespace std;


void ArgumentsList::add(class Argument* pArgumentParm)
{
    mArgsList.push_back(pArgumentParm);
}


vector<class Argument*> ArgumentsList::getArgumentsList()
{
    return mArgsList;
}


void ArgumentsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

