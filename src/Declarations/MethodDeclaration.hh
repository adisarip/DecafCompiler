
#ifndef METHOD_DECLARATION_H
#define METHOD_DECLARATION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "ParametersList.hh"
#include "BlockStatement.hh"
using namespace std;

class MethodDeclaration : public AstNode
{
  public:
    MethodDeclaration(string returnTypeParm,
                      string methodNameParm,
                      class ParametersList* pArgsListParm,
                      class BlockStatement* pBlockStmtParm);

    string getReturnType();
    string getMethodName();
    ParametersList* getParmsListPtr();
    BlockStatement* getBlockStmtPtr();
    virtual void accept(Visitor& vParm);

  private:
    string mReturnType; // return type of the function
    string mMethodName; // Name of the function
    class ParametersList* mParmsListPtr; // Function Arguments List
    class BlockStatement* mBlockStmtPtr; // Block Statement / Function code block.
};

#endif /* METHOD_DECLARATION_H */