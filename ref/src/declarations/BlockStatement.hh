
#ifndef BLOCK_STATEMENT_H
#define BLOCK_STATEMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "StatementsList.hh"
using namespace std;

class BlockStatement : public Statement
{
  public:
    BlockStatement(class VariableDeclarationsList* pVarDeclListParm,
                   class StatementsList* pStmtListParm);

  private:
    class VariableDeclarationsList* mVarDeclListPtr; // list of variables declarations
    class StatementsList* mStmtListPtr; // list of statements
};

#endif /* BLOCK_STATEMENT_H */
