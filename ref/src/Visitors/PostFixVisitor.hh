
#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "Modules.hh"

class PostFixVisitor: public Visitor
{
  public:
    virtual void visit(UnaryAstNode& node);
    virtual void visit(BinaryAstNode& node);
    virtual void visit(IntegerAstNode& node);
    virtual void visit(BooleanAstNode& node);
};

#endif /* POSTFIXVISITOR_H */

