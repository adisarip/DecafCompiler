
#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "Ast.hh"
#include "Visitor.hh"
#include "FieldDeclarationsList.hh"
#include "MethodDeclarationsList.hh"
#include "LLVMConstructs.hh"
using namespace std;

class Program : public AstNode
{
  public:
    Program(string programNameParm,
            FieldDeclarationsList* pFieldsListParm,
            MethodDeclarationsList* pMethodsListParm);

    string getProgamName();
    FieldDeclarationsList* getFieldDeclarationsListPtr();
    MethodDeclarationsList* getMethodDeclarationsListPtr();
    
    virtual void accept(Visitor& vParm); // visitor

  private:
    string mProgamName;
    class FieldDeclarationsList*  mFieldsDeclListPtr;
    class MethodDeclarationsList* mMethodsDeclListPtr;
    //class LLVMConstructs* mllvmConstructsPtr;
};

#endif /* PROGRAM_H */
