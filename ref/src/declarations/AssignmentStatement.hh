#ifndef ASSIGNEMENT_STATEMENT_H
#define ASSIGNEMENT_STATEMENT_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Statement.hh"
#include "VariableLocation.hh"
#include "Expression.hh"
using namespace std;

class AssignmentStatement : public Statement
{
  public:
    AssignmentStatement(string assignmentTypeParm,
                        class Location* pLocationParm,
                        class Expression* pAssignmentExprParm);

  private:
    string mAssignmentType; // = OR += OR -=
    class VariableLocation* mLocationPtr; // location to which assignment is done
    class Expression* mAssignmentExprPtr; // expression assigned to location
};

#endif /* ASSIGNEMENT_STATEMENT_H */