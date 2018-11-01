
#ifndef AST_H
#define AST_H

#include <string>

class ASTvisitor;
class UnaryASTnode;
class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;


class ASTvisitor
{
  public:
    virtual void visit(UnaryASTnode& node) = 0;
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(TernaryASTnode& node) = 0;
    virtual void visit(IntLitASTnode& node) = 0;
};


class ASTnode
{
  public:
    virtual ~ASTnode() {}
    virtual void accept(ASTvisitor& V) = 0;
};


class ASTContext
{
  public:
    ASTnode* pRoot;
    ~ASTContext()
    {
	    clearAST();
    }

    // free all saved expression trees
    inline void clearAST()
    {
        delete pRoot;
    }
};


class UnaryASTnode : public ASTnode
{
    public:
    // Constructor to initialize unary operator
    // and right node of the unary expression.
    UnaryASTnode(std::string unaryOperatorParm,
                 ASTnode* pRightParm);

    ASTnode* getRight();
    std::string getUnaryOperator();
    void accept(ASTvisitor& v);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base ASTnode type
    std::string   mUnaryOperator;
    ASTnode* pRight;
};


class BinaryASTnode : public ASTnode
{
    public:
    // Constructor to initialize binary operator, 
    // left node and right node of the binary expression.
    BinaryASTnode(std::string binOperatorParm,
                  ASTnode* pLeftParm,
                  ASTnode* pRightParm);

    ASTnode* getLeft();
    ASTnode* getRight();
    std::string getBinOperator();
    virtual void accept(ASTvisitor& v);

  private:
    // left node and right node can be of any type. 
    // So we need to use Base ASTnode type
    std::string   mBinaryOperator;
    ASTnode* pLeft;
    ASTnode* pRight;
};


class TernaryASTnode : public ASTnode
{
    public:

    TernaryASTnode (ASTnode* pFirstParm,
                    ASTnode* pSecondParm,
                    ASTnode* pThirdParm)
    :pFirst(pFirstParm)
    ,pSecond(pSecondParm)
    ,pThird(pThirdParm) {}

    ASTnode* getFirst()
    {
        return pFirst;
    }

    ASTnode* getSecond()
    {
        return pSecond;
    }

    ASTnode* getThird()
    {
        return pThird;
    }

       virtual void accept(ASTvisitor& v) 
    {
      v.visit(*this);
    }

  private:
    ASTnode* pFirst;
    ASTnode* pSecond;
    ASTnode* pThird;
};


class IntLitASTnode: public ASTnode
{
	public:
	IntLitASTnode(int intlit);

    int getIntLit();
    virtual void accept(ASTvisitor& v);

  private:
	int intlit;
};

#endif /* End of AST_H */