
#ifndef VARIABLE_DECLARATIONS_LIST_H
#define VARIABLE_DECLARATIONS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "VariableDeclaration.hh"
using namespace std;

class VariableDeclarationsList : public AstNode
{
  public:
    void add(class VariableDeclaration* pVariableDeclParm);
    vector<class VariableDeclaration*> getVariableDeclList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class VariableDeclaration*> mVariableDeclList;
};

#endif /* VARIABLE_DECLARATIONS_LIST_H */
