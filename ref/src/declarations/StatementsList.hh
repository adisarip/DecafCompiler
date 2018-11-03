
#ifndef STATEMENT_LIST_H
#define STATEMENT_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
using namespace std;

class StatementsList : public AstNode
{
  public:
    void add(class Statement* pStmtParm);
    virtual bool hasReturnValue();
    virtual void accept(Visitor& vParm);

  private:
    vector<class Statement*> mStmtPtrList;
};

#endif /* STATEMENT_LIST_H */