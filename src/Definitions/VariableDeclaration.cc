
#include <string>
#include <vector>
#include "VariableDeclaration.hh"
using namespace std;


VariableDeclaration::VariableDeclaration(string declarationTypeParm,
                                         class IdentifiersList* pIdListParm)
:mDeclarationType(declarationTypeParm)
,mIdListPtr(pIdListParm)
{
}


string VariableDeclaration::getDeclarationType()
{
    return mDeclarationType;
}


IdentifiersList* VariableDeclaration::getIdListPtr()
{
    return mIdListPtr;
}


void VariableDeclaration::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
