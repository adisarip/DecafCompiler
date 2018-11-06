
#include "BreakStatement.hh"
using namespace std;

BreakStatement::BreakStatement()
{
    mStmtType = Statement::NON_RETURNING;
}

void BreakStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
