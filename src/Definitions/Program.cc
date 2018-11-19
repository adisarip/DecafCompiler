
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
    //mllvmConstructsPtr = new LLVMConstructs();
}

string Program::getProgamName()
{
    return mProgamName;
}

FieldDeclarationsList* Program::getFieldDeclarationsListPtr()
{
    return mFieldsDeclListPtr;
}

MethodDeclarationsList* Program::getMethodDeclarationsListPtr()
{
    return mMethodsDeclListPtr;
}

void Program::accept(Visitor& vParm)
{
    vParm.visit(*this);
}

