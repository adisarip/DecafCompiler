
#ifndef FIELD_DECLARATION_LIST_H
#define FIELD_DECLARATION_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "FieldDeclaration.hh"
using namespace std;


class FieldDeclarationsList : public AstNode
{
  public:
    void add(class FieldDeclaration* pFieldDeclParm);
    vector<class FieldDeclaration*> getFieldDeclarationsList();
    virtual void accept(Visitor& vParm);
    
  private:
    vector<class FieldDeclaration*> mFieldDeclList;
};

#endif /* FIELD_DECLARATION_LIST_H */