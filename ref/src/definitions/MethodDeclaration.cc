
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


void MethodDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
