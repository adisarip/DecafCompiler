
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


void Variable::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
