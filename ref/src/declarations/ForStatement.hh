#ifndef FOR_STATEMENT_H
#define FOR_STATEMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
#include "BlockStatement.hh"
#include "Expression.hh"
using namespace std;

class ForStatement : public Statement
{
  public:
    ForStatement(string initValueParm,
                 class Expression* pInitExprParm,
                 class Expression* pCondExprParm,
                 class BlockStatement* pForBlockParm);
    virtual bool hasReturnValue();
    virtual void accept(Visitor& vParm);

  private:
    string mInitValue;
    class Expression* mInitExprPtr;
    class Expression* mCondExprPtr;
    class BlockStatement* mForBlockPtr;
};

#endif /* FOR_STATEMENT_H */