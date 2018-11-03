
#ifndef ENCLOSED_EXPRESSION_H
#define ENCLOSED_EXPRESSION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"

class EnclosedExpression : public Expression
{
  public:
    EnclosedExpression(class Expression* pExprParm);
    virtual void accept(Visitor& vParm);

  private:
    class Expression* mExprPtr;
};

#endif /* ENCLOSED_EXPRESSION_H */