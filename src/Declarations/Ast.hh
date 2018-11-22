
#ifndef AST_H
#define AST_H

#include <iostream>
#include "Visitor.hh"


class AstNode
{
  public:
    virtual ~AstNode() {}
    virtual void accept(Visitor& vParm) = 0;
};


class AstContext
{
  public:
    AstNode* pRoot;
    ~AstContext()
    {
	      clearAST();
    }

    // free all saved expression trees
    inline void clearAST()
    {
        delete pRoot;
    }
};

#endif /* End of AST_H */