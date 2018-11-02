
// similar to Variables.h

#ifndef FIELD_DECLARATION_BLOCKS_LIST_H
#define FIELD_DECLARATION_BLOCKS_LIST_H

#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
#include "FieldDeclarationBlock.hh"
using namespace std;

class FieldDeclarationBlocksList : public AstNode
{
  public:
    void add(class FieldDeclarationBlock* pFieldDeclBlockParm);

  private:
    vector<class FieldDeclarationBlock*> mFieldDeclBlocksList;
};

#endif /* FIELD_DECLARATION_BLOCKS_LIST_H */