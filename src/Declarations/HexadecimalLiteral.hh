
#ifndef HEXADECIMAL_LITERAL_H
#define HEXADECIMAL_LITERAL_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "Literal.hh"
using namespace std;

class HexadecimalLiteral : public Literal
{
  public:
    HexadecimalLiteral(long int hexValueParm);
    long int getHexValue();
    virtual void accept(Visitor& vParm);

  private:
    long int mHexValue;
};

#endif /* HEXADECIMAL_LITERAL_H */
