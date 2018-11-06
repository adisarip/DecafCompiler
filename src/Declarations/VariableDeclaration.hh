
#ifndef VARIABLE_DECLARATION_H
#define VARIABLE_DECLARATION_H

#include <string>
#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "IdentifiersList.hh"
using namespace std;

class VariableDeclaration : public AstNode
{
  public:
    VariableDeclaration(string declarationTypeParm,
                        class IdentifiersList* pIdListParm);

    string getDeclarationType();
    IdentifiersList* getIdListPtr();
    virtual void accept(Visitor& vParm);

  private:
    string mDeclarationType; // INT or BOOLEAN
    class IdentifiersList* mIdListPtr;
};

#endif /* VARIABLE_DECLARATION_H */