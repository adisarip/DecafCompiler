
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"

class Expression : public AstNode
{
  public:

    enum ExpressionType
    {
        UNARY         = 1,
        BINARY        = 2,
        LITERAL       = 3,
        LOCATION      = 4,
        METHOD_CALL   = 5,
        ENCLOSED_EXPR = 6
    };

    ExpressionType getExpressionType()
    {
        return mExprType;
    }
    
    virtual void accept(Visitor& vParm)
    {
        vParm.visit(*this);
    };

  protected:
    ExpressionType mExprType;
};

#endif /* EXPRESSION_H */