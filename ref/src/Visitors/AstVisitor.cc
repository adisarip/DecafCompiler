
#include <iostream>
#include "AstVisitor.hh"


void AstVisitor::visit(UnaryAstNode& node)
{
    node.getRight()->accept(*this);
    std::cout << node.getUnaryOperator() << " " << std::flush;
}

void AstVisitor::visit(BinaryAstNode& node)
{
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    std::cout << node.getBinOperator() << " " << std::flush;
}

void AstVisitor::visit(IntegerAstNode& node)
{
    std::cout << node.getInteger() << " " << std::flush;
}

void AstVisitor::visit(BooleanAstNode& node) 
{
    std::cout << node.getBoolean() << " " << std::flush;
}

