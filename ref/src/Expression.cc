
#include "Expression.hh"

/* UnaryAstNode - Definitions */

UnaryAstNode::UnaryAstNode(std::string unaryOperatorParm,
                           AstNode* pRightParm)
:mUnaryOperator(unaryOperatorParm)
,pRight(pRightParm)
{
}

AstNode* UnaryAstNode::getRight()
{
    return pRight;
}

std::string UnaryAstNode::getUnaryOperator()
{
    return mUnaryOperator;
}

void UnaryAstNode::accept(AstVisitor& vParm)
{
    vParm.visit(*this);
}


/* BinaryAstNode - Definitions */

BinaryAstNode::BinaryAstNode(std::string binOperatorParm,
                             AstNode* pLeftParm,
                             AstNode* pRightParm)
:mBinaryOperator(binOperatorParm)
,pLeft(pLeftParm)
,pRight(pRightParm)
{
}

AstNode* BinaryAstNode::getLeft()
{
    return pLeft;
}

AstNode* BinaryAstNode::getRight()
{
    return pRight;
}

std::string BinaryAstNode::getBinOperator()
{
    return mBinaryOperator;
}

void BinaryAstNode::accept(AstVisitor& vParm)
{
    vParm.visit(*this);
}

