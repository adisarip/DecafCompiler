
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;

enum DeclarationType
{
    NORMAL_DECLARATION = 1,
    ARRAY_DECLARATION  = 2
};

class Variable : public AstNode
{
  public:
    Variable(string variableNameParm);
    Variable(string variableNameParm,
             unsigned int arraySizeParm);

  private:
    string mVariableName;
    DeclarationType mDeclType;
    unsigned int mArraySize; // if its an array
};

#endif /* VARIABLE_H */