
/* All the Terminal nodes supported by decaf language to be added here */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "Ast.hh"
#include "Visitor.hh"

// Integer Type
class IntegerAstNode: public AstNode
{
	public:
	IntegerAstNode(int intParm);

    int getInteger();
    virtual void accept(Visitor& vParm);

  private:
	int mInteger;
};


// Boolean Type
class BooleanAstNode: public AstNode
{
	public:
	BooleanAstNode(bool boolParm);

    bool getBoolean();
    virtual void accept(Visitor& vParm);

  private:
	bool mBoolean;
};

#endif /* TERMINAL_H */

