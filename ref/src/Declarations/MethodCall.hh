
#ifndef METHOD_CALL_H
#define METHOD_CALL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
#include "Expression.hh"
using namespace std;

class MethodCall : public Statement, public Expression
{
  public:
  /*
    virtual void accept(Visitor& vParm)
    {
        vParm.visit(*this);
    }
    */

  protected:
    string mMethodName;
};

#endif /* METHOD_CALL_H */
