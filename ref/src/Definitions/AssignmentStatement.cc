
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

void AssignmentStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
