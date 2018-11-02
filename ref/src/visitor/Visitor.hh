

#ifndef VISITOR_H
#define VISITOR_H

class UnaryExpression;
class BinaryExpression;
class IntegerAstNode;
class BooleanAstNode;


class Visitor
{
  public:
    virtual void visit(UnaryExpression& node) = 0;
    virtual void visit(BinaryExpression& node) = 0;
    virtual void visit(IntegerAstNode& node) = 0;
    virtual void visit(BooleanAstNode& node) = 0;
};

#endif /* VISITOR_H */