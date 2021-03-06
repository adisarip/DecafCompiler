
#ifndef CHARACTER_LITERAL_H
#define CHARACTER_LITERAL_H

#include "Ast.hh"
#include "Visitor.hh"
#include "Literal.hh"
using namespace std;

class CharacterLiteral : public Literal
{
  public:
    CharacterLiteral(char charValueParm);
    char getCharValue();
    virtual void accept(Visitor& vParm);

  private:
    char mCharValue;
};

#endif /* CHARACTER_LITERAL_H */
