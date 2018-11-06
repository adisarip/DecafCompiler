
#ifndef IDENTIFIERS_LIST_H
#define IDENTIFIERS_LIST_H

#include <string>
#include <vector>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

class IdentifiersList : public AstNode
{
  public:
    void add(string IdParm);
    vector<string> getIdList();
    virtual void accept(Visitor& vParm);

  private:
    vector<string> mIdList;
};

#endif /* IDENTIFIERS_LIST_H */
