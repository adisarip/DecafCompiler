
#ifndef CALLOUT_ARGUMENT_H
#define CALLOUT_ARGUMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"
using namespace std;

class CalloutArgument : public AstNode
{
  public:
    CalloutArgument(string stringLiteralParm);
    CalloutArgument(class Expression* pCalloutExprParm);
    string getCalloutArgString();
    Expression* getCalloutExprPtr();
    virtual void accept(Visitor& vParm);

  private:
    string mCalloutArgString;
    class Expression* mCalloutExprPtr;
};

#endif /* CALLOUT_ARGUMENT_H */