

#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"

class UnaryExpression : public Expression
{
  public:
    // Constructor to initialize unary operator
    // and right node of the unary expression.
    UnaryExpression(std::string unaryOperatorParm,
                    Expression* pRightParm);

    Expression* getRight();
    std::string getUnaryOperator();
    void accept(Visitor& vParm);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base AstNode type
    std::string mUnaryOperator;
    Expression* mRightPtr;
};

#endif /* UNARY_EXPRESSION_H */