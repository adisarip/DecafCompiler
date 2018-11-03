
#ifndef RETURN_STATEMENT_H
#define RETURN_STATEMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
#include "Expression.hh"
using namespace std;

class ReturnStatement : public Statement
{
  public:
    ReturnStatement(class Expression* pReturnExprParm);
    virtual bool hasReturnValue();
    virtual void accept(Visitor& vParm);

  private:
    class Expression* mReturnExprPtr; // list of statements
};

#endif /* RETURN_STATEMENT_H */
