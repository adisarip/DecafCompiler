
#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "FieldDeclarationsList.hh"
#include "MethodDeclarationsList.hh"
using namespace std;

class Program : public AstNode
{
  public:
    Program(string programNameParm,
            FieldDeclarationsList* pFieldsListParm,
            MethodDeclarationsList* pMethodsListParm);
    
  private:
    string mProgamName;
    class FieldDeclarationsList*  mFieldsDeclListPtr;
    class MethodDeclarationsList* mMethodsDeclListPtr;
};

#endif /* PROGRAM_H */
