
#include <vector>
#include "MethodDeclarationsList.hh"
using namespace std;


void MethodDeclarationsList::add(class MethodDeclaration* pMethodDeclParm)
{
    mMethodDeclList.push_back(pMethodDeclParm);
}


void MethodDeclarationsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

