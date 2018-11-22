// $Id$

#include <iostream>
#include <fstream>
#include "Driver.hh"
#include "Modules.hh"
#include "LLVMIRGenerator.hh"
using namespace std;

int main(int argc, char *argv[])
{
    AstContext sAstCtx;
    decaf::Driver sDriver(sAstCtx);
    LLVMIRGenerator sIRGenerator;

    for(int index = 1; index < argc; index++)
    {
	    // read a decaf program
	    fstream infile(argv[index]);
	    if (!infile.good())
	    {
		    cerr << "Could not open file: " << argv[index] << endl;
		    return 0;
	    }
	    
        bool result = sDriver.parse_stream(infile, argv[index]);
        if (result)
        {
            if (sAstCtx.pRoot != NULL )
            {
                sAstCtx.pRoot->accept(sIRGenerator);
                sIRGenerator.dumpIRCode();
            }
        }
        else
        {
            cout << "Result FALSE" << endl;
        }
	}
}

