
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
    virtual void accept(Visitor& vParm);

  private:
    string mStringLiteral; // might not be needed => TODO
    class Expression* mCalloutExprPtr;
};

#endif /* CALLOUT_ARGUMENT_H */