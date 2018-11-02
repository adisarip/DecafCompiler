
#ifndef USER_DEFINED_METHOD_CALL_H
#define USER_DEFINED_METHOD_CALL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "MethodCall.hh"
using namespace std;

class UserDefinedMethodCall : public MethodCall
{
  public:
    UserDefinedMethodCall(string methodNameParm,
                          class ArgumentsList* pArgsListParm);

  private:
    class ArgumentsList* mArgsListPtr;
};

#endif /* USER_DEFINED_METHOD_CALL_H */
