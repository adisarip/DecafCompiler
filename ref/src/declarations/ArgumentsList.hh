
#ifndef ARGUMENTS_LIST_H
#define ARGUMENTS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Argument.hh"
using namespace std;

class ArgumentsList : public AstNode
{
  public:
    void add(class Argument* pArgumentParm);
    vector<class Argument*> getArgumentsList();
    virtual void accept(Visitor& vParm);

  private:
    vector<class Argument*> mArgsList; // list of all arguments
};

#endif /* ARGUMENTS_LIST_H */