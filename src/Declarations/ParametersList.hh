
#ifndef PARAMETERS_LIST_H
#define PARAMETERS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Parameter.hh"
using namespace std;

class ParametersList : public AstNode
{
  public:
    void add(class Parameter* pParameterParm);
    vector<class Parameter*> getParametersList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class Parameter*> mParmsList; // list of all arguments
};

#endif /* PARAMETERS_LIST_H */