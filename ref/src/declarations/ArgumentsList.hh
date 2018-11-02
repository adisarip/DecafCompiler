
#ifndef ARGUMENTS_LIST_H
#define ARGUMENTS_LIST_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Argument.hh"
using namespace std;

class ArgumentsList : public AstNode
{
  public:
    void add(class Argument*);

  private:
    vector<class Argument*> mArgsListPtr; // list of all arguments
};

#endif /* ARGUMENTS_LIST_H */