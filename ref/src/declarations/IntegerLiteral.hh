
#ifndef INTEGER_LITERAL_H
#define INTEGER_LITERAL_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Literal.hh"
using namespace std;

class IntegerLiteral : public Literal
{
  public:
    IntegerLiteral(int intValueParm);
    int getValue();

  private:
    int mIntValue;
};

#endif /* INTEGER_LITERAL_H */
