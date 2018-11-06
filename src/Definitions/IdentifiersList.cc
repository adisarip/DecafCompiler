
#include <string>
#include <vector>
#include "IdentifiersList.hh"
using namespace std;


void IdentifiersList::add(string idParm)
{
    mIdList.push_back(idParm);
}


vector<string> IdentifiersList::getIdList()
{
    return mIdList;
}


void IdentifiersList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

