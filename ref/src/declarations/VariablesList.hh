
#ifndef VARIABLES_LIST_H
#define VARIABLES_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Variable.hh"
using namespace std;

class VariablesList : public AstNode
{
  public:
    void add(class Variable* pVariableParm);
    vector<class Variable*> getVariablesList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class Variable*> mVariableList;
};

#endif /* VARIABLES_LIST_H */