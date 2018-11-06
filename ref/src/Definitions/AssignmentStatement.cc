
#include <string>
#include "AssignmentStatement.hh"
using namespace std;


AssignmentStatement::AssignmentStatement(string assignmentOpParm,
                                         class VariableLocation* pLocationParm,
                                         class Expression* pAssignmentExprParm)
:mAssignmentOp(assignmentOpParm)
,mLocationPtr(pLocationParm)
,mAssignmentExprPtr(pAssignmentExprParm)
{
    mStmtType = Statement::NON_RETURNING;
}


string AssignmentStatement::getAssignmentOp()
{
    return mAssignmentOp;
}


VariableLocation* AssignmentStatement::getLocationPtr()
{
    return mLocationPtr;
}


Expression* AssignmentStatement::getAssignmentExprPtr()
{
    return mAssignmentExprPtr;
}


void AssignmentStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
