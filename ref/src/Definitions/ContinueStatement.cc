
#include "ContinueStatement.hh"
using namespace std;


ContinueStatement::ContinueStatement()
{
    mStmtType = Statement::NON_RETURNING;
}

void ContinueStatement::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
