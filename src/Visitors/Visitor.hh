

#ifndef VISITOR_H
#define VISITOR_H

class Program;
class FieldDeclaration;
class FieldDeclarationsList;
class MethodDeclaration;
class MethodDeclarationsList;
class Parameter;
class ParametersList;
class StatementsList;
class BlockStatement;
class AssignmentStatement;
class IfElseStatement;
class ForStatement;
class ReturnStatement;
class BreakStatement;
class ContinueStatement;
class UserDefinedMethodCall;
class CalloutMethodCall;
class CalloutArgument;
class CalloutArgumentsList;
class ExpressionsList;
class UnaryExpression;
class BinaryExpression;
class EnclosedExpression;
//class Literal;
class IntegerLiteral;
class BooleanLiteral;
class HexadecimalLiteral;
class CharacterLiteral;
class IdentifiersList;
class Variable;
class VariablesList;
class VariableDeclaration;
class VariableDeclarationsList;
class VariableLocation;


class Visitor
{
  public:
    virtual void visit(Program& nodeParm) = 0;
    virtual void visit(FieldDeclaration& nodeParm) = 0;
    virtual void visit(FieldDeclarationsList& nodeParm) = 0;
    virtual void visit(MethodDeclaration& nodeParm) = 0;
    virtual void visit(MethodDeclarationsList& nodeParm) = 0;
    virtual void visit(Parameter& nodeParm) = 0;
    virtual void visit(ParametersList& nodeParm) = 0;
    virtual void visit(StatementsList& nodeParm) = 0;
    virtual void visit(BlockStatement& nodeParm) = 0;
    virtual void visit(AssignmentStatement& nodeParm) = 0;
    virtual void visit(IfElseStatement& nodeParm) = 0;
    virtual void visit(ForStatement& nodeParm) = 0;
    virtual void visit(ReturnStatement& nodeParm) = 0;
    virtual void visit(BreakStatement& nodeParm) = 0;
    virtual void visit(ContinueStatement& nodeParm) = 0;
    virtual void visit(UserDefinedMethodCall& nodeParm) = 0;
    virtual void visit(CalloutMethodCall& nodeParm) = 0;
    virtual void visit(CalloutArgument& nodeParm) = 0;
    virtual void visit(CalloutArgumentsList& nodeParm) = 0;
    virtual void visit(ExpressionsList& nodeParm) = 0;
    virtual void visit(UnaryExpression& nodeParm) = 0;
    virtual void visit(BinaryExpression& nodeParm) = 0;
    virtual void visit(EnclosedExpression& nodeParm) = 0;
    //virtual void visit(Literal& nodeParm) = 0;
    virtual void visit(IntegerLiteral& nodeParm) = 0;
    virtual void visit(BooleanLiteral& nodeParm) = 0;
    virtual void visit(HexadecimalLiteral& nodeParm) = 0;
    virtual void visit(CharacterLiteral& nodeParm) = 0;
    virtual void visit(IdentifiersList& nodeParm) = 0;
    virtual void visit(Variable& nodeParm) = 0;
    virtual void visit(VariablesList& nodeParm) = 0;
    virtual void visit(VariableDeclaration& nodeParm) = 0;
    virtual void visit(VariableDeclarationsList& nodeParm) = 0;
    virtual void visit(VariableLocation& nodeParm) = 0;
};

#endif /* VISITOR_H */