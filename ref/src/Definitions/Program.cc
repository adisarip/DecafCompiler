
#include <string>
#include "Program.hh"
using namespace std;


Program::Program(string programNameParm,
                 FieldDeclarationsList* pFieldsListParm,
                 MethodDeclarationsList* pMethodsListParm)
:mProgamName(programNameParm)
,mFieldsDeclListPtr(pFieldsListParm)
,mMethodsDeclListPtr(pMethodsListParm)
{
}

string Program::getProgamName()
{
    return mProgamName;
}

FieldDeclarationsList* Program::getFieldDeclarationsList()
{
    return mFieldsDeclListPtr;
}

MethodDeclarationsList* Program::getMethodDeclarationsList()
{
    return mMethodsDeclListPtr;
}

void Program::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

