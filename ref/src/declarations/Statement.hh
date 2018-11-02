
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

  protected:
    StatementType mStmtType; // for the derived classes to access
};

#endif /* STATEMENT_H */