
#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "Modules.hh"

class PostFixVisitor: public Visitor
{
  public:
    virtual void visit(UnaryExpression& node);
    virtual void visit(BinaryExpression& node);
    virtual void visit(IntegerLiteral& node);
    virtual void visit(BooleanLiteral& node);
};

#endif /* POSTFIXVISITOR_H */

