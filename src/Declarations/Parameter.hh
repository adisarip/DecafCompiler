
#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

class Parameter : public AstNode
{
  public:
    Parameter(string nameParm,
             string typeParm);
    string getName();
    string getType();
    virtual void accept(Visitor& vParm);

  private:
    string mName;
    string mType;
};

#endif /* PARAMETER_H */