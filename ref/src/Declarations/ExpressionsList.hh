
#ifndef EXPRESSIONS_LIST_H
#define EXPRESSIONS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"
using namespace std;

class ExpressionsList : public AstNode
{
  public:
    void add(class Expression* pExprParm);
    vector<class Expression*> getExpressionsList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class Expression*> mExprList; // list of all functional arguments
};

#endif /* EXPRESSIONS_LIST_H */