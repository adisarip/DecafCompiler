
#include <vector>
#include "MethodDeclarationsList.hh"
using namespace std;


void MethodDeclarationsList::add(class MethodDeclaration* pMethodDeclParm)
{
    mMethodDeclList.insert(mMethodDeclList.begin(), pMethodDeclParm);
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

