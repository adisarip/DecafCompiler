
#ifndef METHOD_DECLARATION_LIST_H
#define METHOD_DECLARATION_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "MethodDeclaration.hh"
using namespace std;

class MethodDeclarationsList : public AstNode
{
  public:
    void add(class MethodDeclaration* pMethodDeclParm);
    vector<class MethodDeclaration*> getMethodDeclList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class MethodDeclaration*> mMethodDeclList;
};

#endif /* METHOD_DECLARATION_LIST_H */
