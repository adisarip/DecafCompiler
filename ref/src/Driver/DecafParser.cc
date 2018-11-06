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
                    UnaryExpression *unode;
                    BinaryExpression *bnode;
                    IntegerLiteral *inode;

                    std::cout << "Postfix Form: " << std::endl;

                    unode = dynamic_cast<UnaryExpression*>(sAstCtx.pRoot);
                    if (unode != NULL)
                    {
                        sVisitor.visit(*unode);
                    }

                    bnode = dynamic_cast<BinaryExpression*>(sAstCtx.pRoot);
                    if (bnode != NULL)
                    {
                        sVisitor.visit(*bnode);
                    }

                    inode = dynamic_cast<IntegerLiteral*>(sAstCtx.pRoot);
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

