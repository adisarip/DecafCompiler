
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


void Program::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

