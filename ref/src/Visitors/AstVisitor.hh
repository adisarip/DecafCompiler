
#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "Modules.hh"

class AstVisitor: public Visitor
{
  public:
    virtual void visit(UnaryAstNode& node);
    virtual void visit(BinaryAstNode& node);
    virtual void visit(IntegerAstNode& node);
    virtual void visit(BooleanAstNode& node);
};

#endif /* AST_VISITOR_H */

