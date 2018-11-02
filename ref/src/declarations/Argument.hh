
#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

class Argument : public AstNode
{
  public:
    Argument(string argNameParm,
             string argTypeParm);
    void getArgName();
    void getArgType();

  private:
    string mArgName;
    string mArgType;
};

#endif /* ARGUMENT_H */