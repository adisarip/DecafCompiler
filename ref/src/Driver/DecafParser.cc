// $Id$

#include <iostream>
#include <fstream>
#include "Driver.hh"
#include "Modules.hh"
#include "PostFixVisitor.hh"

int main()
{
    AstContext sAstCtx;
    decaf::Driver sDriver(sAstCtx);
    PostFixVisitor sVisitor;
    std::string sLine;

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
                    UnaryAstNode *unode;
                    BinaryAstNode *bnode;
                    IntegerAstNode *inode;

                    std::cout << "Postfix Form: " << std::endl;

                    unode = dynamic_cast<UnaryAstNode*>(sAstCtx.pRoot);
                    if (unode != NULL)
                    {
                        sVisitor.visit(*unode);
                    }

                    bnode = dynamic_cast<BinaryAstNode*>(sAstCtx.pRoot);
                    if (bnode != NULL)
                    {
                        sVisitor.visit(*bnode);
                    }

                    inode = dynamic_cast<IntegerAstNode*>(sAstCtx.pRoot);
                    if (inode != NULL)
                    {
                        sVisitor.visit(*inode);
                    }
                    std::cout <<  std::endl; 
                }
                sAstCtx.clearAST();
            }
        }
	}
}

