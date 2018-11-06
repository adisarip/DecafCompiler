
#include <string>
#include "Variable.hh"
using namespace std;


Variable::Variable(string variableNameParm)
:mVariableName(variableNameParm)
{
    mDeclType = Variable::NORMAL_DECLARATION;
}


Variable::Variable(string variableNameParm,
                   long int arraySizeParm)
:mVariableName(variableNameParm)
,mArraySize(arraySizeParm)
{
    mDeclType = Variable::ARRAY_DECLARATION;
}


Variable::DeclarationType
Variable::getDeclarationType()
{
    return mDeclType;
}


string Variable::getVariableName()
{
    return mVariableName;
}


int Variable::getArraySize()
{
    return mArraySize;
}


void Variable::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
