

#ifndef AST_VISITOR_H
#define AST_VISITOR_H

class UnaryAstNode;
class BinaryAstNode;
class IntegerAstNode;


class AstVisitor
{
  public:
    virtual void visit(UnaryAstNode& node) = 0;
    virtual void visit(BinaryAstNode& node) = 0;
    virtual void visit(IntegerAstNode& node) = 0;
};

#endif /* AST_VISITOR_H */