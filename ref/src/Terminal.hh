

#ifndef TERMINAL_H
#define TERMINAL_H

#include "Ast.hh"
#include "AstVisitor.hh"

//class IntegerAstNode;

class IntegerAstNode: public AstNode
{
	public:
	IntegerAstNode(int intParm);

    int getInteger();
    virtual void accept(AstVisitor& vParm);

  private:
	int mInteger;
};

#endif /* TERMINAL_H */

