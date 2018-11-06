
#ifndef CONTINUE_STATEMENT_H
#define CONTINUE_STATEMENT_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
using namespace std;

class ContinueStatement : public Statement
{
  public:
    ContinueStatement();
    virtual void accept(Visitor& vParm);
};

#endif /* CONTINUE_STATEMENT_H */
