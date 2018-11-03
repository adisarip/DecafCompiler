
#include <string>
#include "UserDefinedMethodCall.hh"
using namespace std;


UserDefinedMethodCall::UserDefinedMethodCall(string methodNameParm,
                                             class ExpressionsList* pArgsListParm)
:mArgsListPtr(pArgsListParm)
{
    mMethodName = methodNameParm;
}


void UserDefinedMethodCall::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
