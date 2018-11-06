// $Id$

#include <iostream>
#include <fstream>
#include "Driver.hh"
#include "Modules.hh"
#include "AstVisitor.hh"
using namespace std;

int main(int argc, char *argv[])
{
    AstContext sAstCtx;
    decaf::Driver sDriver(sAstCtx);
    AstVisitor sVisitor;

    for(int index = 1; index < argc; index++)
    {
	    // read a decaf program
	    fstream infile(argv[index]);
	    if (!infile.good())
	    {
		    cerr << "Could not open file: " << argv[index] << endl;
		    return 0;
	    }

        cout << "Parsing " << argv[index] << " Started" << endl;

	    //sAstCtx.clearAST();
        //cout << "AST Cleared." << endl;

	    bool result = sDriver.parse_stream(infile, argv[index]);
        if (result)
        {
            cout << "Parsing " << argv[index] << " Successful" << endl;
            if (sAstCtx.pRoot != NULL )
            {
                cout << "Traversing the AST ..." << endl;
                sAstCtx.pRoot->accept(sVisitor);
                cout << "Traverse AST Complete !!!" << endl; 
            }
        }
	}
    //sAstCtx.clearAST();
}

