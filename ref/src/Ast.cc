// $Id$

#include "Driver.hh"
#include "Ast.hh"
#include "PostFixVisitor.hh"


/* UnaryASTnode - Definitions */

UnaryASTnode::UnaryASTnode(std::string unaryOperatorParm,
                           ASTnode* pRightParm)
:mUnaryOperator(unaryOperatorParm)
,pRight(pRightParm)
{
}

ASTnode* UnaryASTnode::getRight()
{
    return pRight;
}

std::string UnaryASTnode::getUnaryOperator()
{
    return mUnaryOperator;
}

void UnaryASTnode::accept(ASTvisitor& v)
{
    v.visit(*this);
}


/* BinaryASTnode - Definitions */

BinaryASTnode::BinaryASTnode(std::string binOperatorParm,
                             ASTnode* pLeftParm,
                             ASTnode* pRightParm)
:mBinaryOperator(binOperatorParm)
,pLeft(pLeftParm)
,pRight(pRightParm)
{
}

ASTnode* BinaryASTnode::getLeft()
{
    return pLeft;
}

ASTnode* BinaryASTnode::getRight()
{
    return pRight;
}

std::string BinaryASTnode::getBinOperator()
{
    return mBinaryOperator;
}

void BinaryASTnode::accept(ASTvisitor& v)
{
    v.visit(*this);
}


/* IntLitASTnode - Definitions */

IntLitASTnode::IntLitASTnode(int intlit)
:intlit(intlit)
{
}

int IntLitASTnode::getIntLit()
{
    return intlit;
}

void IntLitASTnode::accept(ASTvisitor& v) 
{
    v.visit(*this);
}

