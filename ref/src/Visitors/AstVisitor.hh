
#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "Modules.hh"

class AstVisitor: public Visitor
{
  public:
    virtual void visit(Program& nodeParm);
    virtual void visit(FieldDeclaration& nodeParm);
    virtual void visit(FieldDeclarationsList& nodeParm);
    virtual void visit(MethodDeclaration& nodeParm);
    virtual void visit(MethodDeclarationsList& nodeParm);
    virtual void visit(Argument& nodeParm);
    virtual void visit(ArgumentsList& nodeParm);
    virtual void visit(StatementsList& nodeParm);
    virtual void visit(BlockStatement& nodeParm);
    virtual void visit(AssignmentStatement& nodeParm);
    virtual void visit(IfElseStatement& nodeParm);
    virtual void visit(ForStatement& nodeParm);
    virtual void visit(ReturnStatement& nodeParm);
    virtual void visit(BreakStatement& nodeParm);
    virtual void visit(ContinueStatement& nodeParm);
    virtual void visit(UserDefinedMethodCall& nodeParm);
    virtual void visit(CalloutMethodCall& nodeParm);
    virtual void visit(CalloutArgument& nodeParm);
    virtual void visit(CalloutArgumentsList& nodeParm);
    virtual void visit(Expression& nodeParm);
    virtual void visit(ExpressionsList& nodeParm);
    virtual void visit(UnaryExpression& nodeParm);
    virtual void visit(BinaryExpression& nodeParm);
    virtual void visit(EnclosedExpression& nodeParm);
    virtual void visit(Literal& nodeParm);
    virtual void visit(IntegerLiteral& nodeParm);
    virtual void visit(BooleanLiteral& nodeParm);
    virtual void visit(HexadecimalLiteral& nodeParm);
    virtual void visit(CharacterLiteral& nodeParm);
    virtual void visit(StringLiteral& nodeParm);
    virtual void visit(IdentifiersList& nodeParm);
    virtual void visit(Variable& nodeParm);
    virtual void visit(VariablesList& nodeParm);
    virtual void visit(VariableDeclaration& nodeParm);
    virtual void visit(VariableDeclarationsList& nodeParm);
    virtual void visit(VariableLocation& nodeParm);
};

#endif /* AST_VISITOR_H */

