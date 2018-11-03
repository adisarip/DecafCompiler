#ifndef VARIABLE_LOCATION_H
#define VARIABLE_LOCATION_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"
using namespace std;

class VariableLocation : public Expression
{
  public:

    enum LocationType
    {
        VARIABLE = 1,
        ARRAY    = 2
    };

    VariableLocation(string variableNameParm);
    VariableLocation(string variableNameParm,
                     class Expression* pArrayIndexParm);
    virtual void accept(Visitor& vParm);

  private:
    LocationType mLocationType; // INT or ARRAY
    string mVariableName;
    class Expression* mArrayIndexPtr; // expression pointed to array index
};

#endif /* VARIABLE_LOCATION_H */