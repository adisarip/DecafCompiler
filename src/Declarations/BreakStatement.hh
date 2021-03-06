
#ifndef BREAK_STATEMENT_H
#define BREAK_STATEMENT_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
using namespace std;

class BreakStatement : public Statement
{
  public:
    BreakStatement();
    virtual void accept(Visitor& vParm);
};

#endif /* BREAK_STATEMENT_H */
