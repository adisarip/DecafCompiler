
#ifndef USER_DEFINED_METHOD_CALL_H
#define USER_DEFINED_METHOD_CALL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "MethodCall.hh"
#include "ExpressionsList.hh"
using namespace std;

class UserDefinedMethodCall : public MethodCall
{
  public:
    UserDefinedMethodCall(string methodNameParm,
                          class ExpressionsList* pArgsListParm);
    
    virtual void accept(Visitor& vParm);

  private:
    class ExpressionsList* mArgsListPtr;
};

#endif /* USER_DEFINED_METHOD_CALL_H */
