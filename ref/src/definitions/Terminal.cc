
#include "Terminal.hh"


/* IntegerAstNode - Definitions */
IntegerAstNode::IntegerAstNode(int intParm)
:mInteger(intParm)
{
}

int IntegerAstNode::getInteger()
{
    return mInteger;
}

void IntegerAstNode::accept(AstVisitor& vParm) 
{
    vParm.visit(*this);
}


/* BooleanAstNode - Definitions */
BooleanAstNode::BooleanAstNode(bool boolParm)
:mBoolean(boolParm)
{
}

bool BooleanAstNode::getBoolean()
{
    return mBoolean;
}

void BooleanAstNode::accept(AstVisitor& vParm)
{
    vParm.visit(*this);
}

