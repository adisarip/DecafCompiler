
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
using namespace std;


class Variable : public AstNode
{
  public:

    enum DeclarationType
    {
        NORMAL_DECLARATION = 1,
        ARRAY_DECLARATION  = 2
    };

    Variable(string variableNameParm);
    Variable(string variableNameParm,
             long int arraySizeParm);

    DeclarationType getDeclarationType();
    string getVariableName();
    int getArraySize();
    virtual void accept(Visitor& vParm);

  private:
    string mVariableName;
    int mArraySize; // if its an array
    DeclarationType mDeclType;
};

#endif /* VARIABLE_H */