
#ifndef LITERAL_H
#define LITERAL_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "Expression.hh"
using namespace std;

class Literal : public Expression
{
  public:

    enum LiteralType
    {
        INTEGER     = 1,
        BOOLEAN     = 2,
        CHARACTER   = 3,
        STRING      = 4,
        HEXADECIMAL = 5
    };

    /*virtual void accept(Visitor& vParm)
    {
        vParm.visit(*this);
    };*/

  protected:
    LiteralType mLiteralType; // for the derived classes to access
};

#endif /* LITERAL_H */