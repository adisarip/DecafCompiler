
#ifndef FIELD_DECLARATION_H
#define FIELD_DECLARATION_H

#include <string>
#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "VariablesList.hh"
using namespace std;

class FieldDeclaration : public AstNode
{
  public:
    FieldDeclaration(string dataTypeParm,
                     class VariablesList* pVariablesListParm);
    
    string getDataType();
    VariablesList* getVariablesListPtr();
    virtual void accept(Visitor& vParm);
    
  private:
    string mDataType;
    class VariablesList* mVariablesListPtr;
};

#endif /* FIELD_DECLARATION_H */