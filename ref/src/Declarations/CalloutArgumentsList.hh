
#ifndef CALLOUT_ARGUMENTS_LIST_H
#define CALLOUT_ARGUMENTS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "CalloutArgument.hh"
using namespace std;

class CalloutArgumentsList : public AstNode
{
  public:
    void add(class CalloutArgument*);
    vector<class CalloutArgument*> getCalloutArgsList();
    virtual void accept(Visitor& vParm);

  private:
    // list of all Callout arguments
    vector<class CalloutArgument*> mCalloutArgsList;
};

#endif /* CALLOUT_ARGUMENTS_LIST_H */