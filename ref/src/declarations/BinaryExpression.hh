

#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"


class BinaryExpression : public Expression
{
  public:
    // Constructor to initialize binary operator, 
    // left node and right node of the binary expression.
    BinaryExpression(std::string binOperatorParm,
                     Expression* pLeftParm,
                     Expression* pRightParm);

    Expression* getLeft();
    Expression* getRight();
    std::string getBinOperator();
    virtual void accept(Visitor& vParm);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base AstNode type
    std::string mBinaryOperator;
    Expression* mLeftPtr;
    Expression* mRightPtr;
};

#endif /* BINARY_EXPRESSION_H */