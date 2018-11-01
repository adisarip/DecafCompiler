
#ifndef AST_H
#define AST_H

#include "AstVisitor.hh"


class AstNode
{
  public:
    virtual ~AstNode() {}
    virtual void accept(AstVisitor& vParm) = 0;
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