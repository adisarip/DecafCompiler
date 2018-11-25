
#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

class Parameter : public AstNode
{
  public:
    Parameter(string typeParm,
              string nameParm);
    string getType();
    string getName();
    virtual void accept(Visitor& vParm);

  private:
    string mType;
    string mName;
    
};

#endif /* PARAMETER_H */