// $Id$

#include <iostream>
#include <fstream>
#include "Driver.hh"
#include "Ast.hh"
#include "PostFixVisitor.hh"

int main()
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor pfv;
    
    std::string line;
    while(1)
    {
        std::cout << "Input: " << std::flush;
        getline(std::cin, line);
        if (!line.empty())
        {
            bool result = driver.parse_string(line, "Input");

            if (result)
            {
                if (ast.pRoot != NULL )
                {
                    UnaryASTnode *unode;
                    BinaryASTnode *bnode;
                    TernaryASTnode *tnode;
                    IntLitASTnode *inode;

                    std::cout << "Postfix Form: " << std::endl;

                    unode = dynamic_cast<UnaryASTnode*>(ast.pRoot);
                    if (unode != NULL)
                    {
                        pfv.visit(*unode);
                    }

                    bnode = dynamic_cast<BinaryASTnode*>(ast.pRoot);
                    if (bnode != NULL)
                    {
                        pfv.visit(*bnode);
                    }

                    tnode = dynamic_cast<TernaryASTnode*>(ast.pRoot);
                    if (tnode != NULL)
                    {
                        pfv.visit(*tnode);
                    }

                    inode = dynamic_cast<IntLitASTnode*>(ast.pRoot);
                    if (inode != NULL)
                    {
                        pfv.visit(*inode);
                    }
                    std::cout <<  std::endl; 
                }
                ast.clearAST();
            }
        }
	}
}

