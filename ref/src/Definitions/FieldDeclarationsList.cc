
#include <vector>
#include "FieldDeclarationsList.hh"
using namespace std;


void
FieldDeclarationsList::add(class FieldDeclaration* pFieldDeclParm)
{
    mFieldDeclList.push_back(pFieldDeclParm);
}


vector<class FieldDeclaration*>
FieldDeclarationsList::getFieldDeclarationsList()
{
    return mFieldDeclList;
}


void
FieldDeclarationsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

