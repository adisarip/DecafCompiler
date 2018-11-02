
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
    
    void add(string variableParm);

  private:
    string mDeclarationType; // INT or BOOLEAN
    vector<string> mVariablesList;
};

#endif /* VARIABLE_DECLARATION_H */