
#include <string>
#include "MethodDeclaration.hh"
using namespace std;


MethodDeclaration::MethodDeclaration(string returnTypeParm,
                                     string methodNameParm,
                                     class ArgumentsList* pArgsListParm,
                                     class BlockStatement* pBlockStmtParm)
:mReturnType(returnTypeParm)
,mMethodName(methodNameParm)
,mArgsListPtr(pArgsListParm)
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


ArgumentsList* MethodDeclaration::getArgsListPtr()
{
    return mArgsListPtr;
}


BlockStatement* MethodDeclaration::getBlockStmtPtr()
{
    return mBlockStmtPtr;
}


void MethodDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
