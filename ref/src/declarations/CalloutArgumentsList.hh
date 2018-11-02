
#ifndef CALLOUT_ARGUMENTS_LIST_H
#define CALLOUT_ARGUMENTS_LIST_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "CalloutArgument.hh"
using namespace std;

class CalloutArgumentsList : public AstNode
{
  public:
    void add(class CalloutArgument*);

  private:
    // list of all Callout arguments
    vector<class CalloutArgument*> mCalloutArgsListPtr;
};

#endif /* CALLOUT_ARGUMENTS_LIST_H */