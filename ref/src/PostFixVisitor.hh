
#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "Ast.hh"

class PostFixVisitor: public ASTvisitor
{
  public:
    virtual void visit(UnaryASTnode& node);
    virtual void visit(BinaryASTnode& node);
    virtual void visit(TernaryASTnode& node);
    virtual void visit(IntLitASTnode& node);
};

#endif /* POSTFIXVISITOR_H */

