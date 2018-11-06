// $Id$

#include <iostream>
#include <fstream>
#include "Driver.hh"
#include "Modules.hh"
#include "AstVisitor.hh"

int main()
{
    AstContext sAstCtx;
    decaf::Driver sDriver(sAstCtx);
    AstVisitor sVisitor;
    std::string sLine;
    Program* pProg;

    while(1)
    {
        std::cout << "Input: " << std::flush;
        getline(std::cin, sLine);
        if (!sLine.empty())
        {
            bool result = sDriver.parse_string(sLine, "Input");
            if (result)
            {
                if (sAstCtx.pRoot != NULL )
                {
                    std::cout << "Traversing the AST: " << std::endl;
                    pProg = dynamic_cast<Program*>(sAstCtx.pRoot);
                    pProg->accept(sVisitor);
                    std::cout << "Traverse AST Complete !!!" << std::endl; 
                }
                sAstCtx.clearAST();
            }
        }
	}
}

