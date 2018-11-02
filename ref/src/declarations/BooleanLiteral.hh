
#ifndef BOOLEAN_LITERAL_H
#define BOOLEAN_LITERAL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Literal.hh"
using namespace std;

class BooleanLiteral : public Literal
{
  public:
    BooleanLiteral(string boolValueParm);

  private:
    string mBoolValue;
};

#endif /* BOOLEAN_LITERAL_H */
