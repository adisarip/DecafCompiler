
#ifndef CONTINUE_STATEMENT_H
#define CONTINUE_STATEMENT_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
using namespace std;

class ContinueStatement : public Statement
{
  public:
    ContinueStatement()
    {
        this->mStmtType = Statement::NON_RETURNING;
    }
};

#endif /* CONTINUE_STATEMENT_H */
