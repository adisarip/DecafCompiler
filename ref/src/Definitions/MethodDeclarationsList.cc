
#include <vector>
#include "MethodDeclarationsList.hh"
using namespace std;


void MethodDeclarationsList::add(class MethodDeclaration* pMethodDeclParm)
{
    mMethodDeclList.push_back(pMethodDeclParm);
}


vector<class MethodDeclaration*>
MethodDeclarationsList::getMethodDeclList()
{
    return mMethodDeclList;
}


void MethodDeclarationsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

