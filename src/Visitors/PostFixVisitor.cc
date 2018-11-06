
#include <iostream>
#include "PostFixVisitor.hh"


void PostFixVisitor::visit(UnaryExpression& node)
{
    node.getRight()->accept(*this);
    std::cout << node.getUnaryOperator() << " " << std::flush;
}

void PostFixVisitor::visit(BinaryExpression& node)
{
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    std::cout << node.getBinOperator() << " " << std::flush;
}

void PostFixVisitor::visit(IntegerLiteral& node)
{
    std::cout << node.getValue() << " " << std::flush;
}

void PostFixVisitor::visit(BooleanLiteral& node) 
{
    std::cout << node.getValue() << " " << std::flush;
}

