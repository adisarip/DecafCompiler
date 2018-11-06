
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
    string getArgName();
    string getArgType();
    virtual void accept(Visitor& vParm);

  private:
    string mArgName;
    string mArgType;
};

#endif /* ARGUMENT_H */