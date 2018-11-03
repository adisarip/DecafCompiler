
#ifndef IF_ELSE_STATEMENT_H
#define IF_ELSE_STATEMENT_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
#include "BlockStatement.hh"
#include "Expression.hh"
using namespace std;

class IfElseStatement : public Statement
{
  public:
    IfElseStatement(class Expression* pCondExprParm,
                    class BlockStatement* pIfBlockParm,
                    class BlockStatement* pElseBlockParm);
    virtual bool hasReturnValue();
    virtual void accept(Visitor& vParm);

  private:
    class Expression* mCondExprPtr;
    class BlockStatement* mIfBlockPtr;
    class BlockStatement* mElseBlockPtr;
};

#endif /* IF_ELSE_STATEMENT_H */