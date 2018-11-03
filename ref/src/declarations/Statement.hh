
#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

class Statement : public AstNode
{
  public:

    enum StatementType
    {
        RETURNING     = 1,
        NON_RETURNING = 2
    };

    // Constructor
    Statement()
    :mStmtType(Statement::NON_RETURNING)
    {
    }

    // tell whether if the statement returns a value
    virtual bool hasReturnValue()
    {
        return false; // default
    }

    virtual void accept(Visitor& vParm)
    {
        vParm.visit(*this);
    }

  protected:
    StatementType mStmtType; // for the derived classes to access
};

#endif /* STATEMENT_H */