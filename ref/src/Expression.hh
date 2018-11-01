

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "Ast.hh"
#include "AstVisitor.hh"


class UnaryAstNode : public AstNode
{
    public:
    // Constructor to initialize unary operator
    // and right node of the unary expression.
    UnaryAstNode(std::string unaryOperatorParm,
                 AstNode* pRightParm);

    AstNode* getRight();
    std::string getUnaryOperator();
    void accept(AstVisitor& vParm);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base AstNode type
    std::string mUnaryOperator;
    AstNode*    pRight;
};


class BinaryAstNode : public AstNode
{
    public:
    // Constructor to initialize binary operator, 
    // left node and right node of the binary expression.
    BinaryAstNode(std::string binOperatorParm,
                  AstNode* pLeftParm,
                  AstNode* pRightParm);

    AstNode* getLeft();
    AstNode* getRight();
    std::string getBinOperator();
    virtual void accept(AstVisitor& vParm);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base AstNode type
    std::string mBinaryOperator;
    AstNode*    pLeft;
    AstNode*    pRight;
};

#endif /* EXPRESSION_H */