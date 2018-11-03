
#ifndef METHOD_DECLARATION_H
#define METHOD_DECLARATION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "ArgumentsList.hh"
#include "BlockStatement.hh"
using namespace std;

class MethodDeclaration : public AstNode
{
  public:
    MethodDeclaration(string returnTypeParm,
                      string methodNameParm,
                      class ArgumentsList* pArgsListParm,
                      class BlockStatement* pBlockStmtParm);

    virtual void accept(Visitor& vParm);

  private:
    string mReturnType; // return type of the function
    string mMethodName; // Name of the function
    class ArgumentsList* mArgsListPtr; // Function Arguments List
    class BlockStatement* mBlockStmtPtr; // Block Statement / Function code block.
};

#endif /* METHOD_DECLARATION_H */