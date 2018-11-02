
#ifndef CALLOUT_METHOD_CALL_H
#define CALLOUT_METHOD_CALL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "MethodCall.hh"
#include "CalloutArgumentsList.hh"
using namespace std;

class CalloutMethodCall : public MethodCall
{
  public:
    CalloutMethodCall(string methodNameParm,
                      class CalloutArgumentsList* pCalloutArgsListParm);

  private:
    class CalloutArgumentsList* mCalloutArgsListPtr;
};

#endif /* CALLOUT_METHOD_CALL_H */
