
#ifndef STRING_LITERAL_H
#define STRING_LITERAL_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Literal.hh"
using namespace std;

class StringLiteral : public Literal
{
  public:
    StringLiteral(string stringValueParm);

  private:
    string mStringValue;
};

#endif /* STRING_LITERAL_H */
