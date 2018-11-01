
#include <iostream>
#include "PostFixVisitor.hh"


void PostFixVisitor::visit(UnaryAstNode& node)
{
    node.getRight()->accept(*this);
    std::cout << node.getUnaryOperator() << " " << std::flush;
}

void PostFixVisitor::visit(BinaryAstNode& node)
{
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    std::cout << node.getBinOperator() << " " << std::flush;
}

void PostFixVisitor::visit(IntegerAstNode& node) 
{
    std::cout << node.getInteger() << " " << std::flush;
}

