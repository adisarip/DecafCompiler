#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"
using namespace std;

class AssignmentStatement : public Expression
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

#endif /* ASSIGNMENT_STATEMENT_H */