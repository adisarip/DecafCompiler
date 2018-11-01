
#include <iostream>
#include "Ast.hh"
#include "PostFixVisitor.hh"


void PostFixVisitor::visit(UnaryASTnode& node)
{
    node.getRight()->accept(*this);
    std::cout << node.getUnaryOperator() << " " << std::flush;
}

void PostFixVisitor::visit(BinaryASTnode& node)
{
    node.getLeft()->accept(*this);
    node.getRight()->accept(*this);
    std::cout << node.getBinOperator() << " " << std::flush;
}

void PostFixVisitor::visit(TernaryASTnode& node)
{
    node.getFirst()->accept(*this);
    node.getSecond()->accept(*this);
    node.getThird()->accept(*this);
    std::cout << "? " << std::flush;
}

void PostFixVisitor::visit(IntLitASTnode& node) 
{
    std::cout << node.getIntLit() << " " << std::flush;
}

