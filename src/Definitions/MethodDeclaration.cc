
#include <string>
#include "MethodDeclaration.hh"
using namespace std;


MethodDeclaration::MethodDeclaration(string returnTypeParm,
                                     string methodNameParm,
                                     class ParametersList* pArgsListParm,
                                     class BlockStatement* pBlockStmtParm)
:mReturnType(returnTypeParm)
,mMethodName(methodNameParm)
,mParmsListPtr(pArgsListParm)
,mBlockStmtPtr(pBlockStmtParm)
{
}

string MethodDeclaration::getReturnType()
{
    return mReturnType;
}


string MethodDeclaration::getMethodName()
{
    return mMethodName;
}


ParametersList* MethodDeclaration::getParmsListPtr()
{
    return mParmsListPtr;
}


BlockStatement* MethodDeclaration::getBlockStmtPtr()
{
    return mBlockStmtPtr;
}


void MethodDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
