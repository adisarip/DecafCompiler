// $Id$

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Driver.hh"
#include "Modules.hh"
#include "LLVMIRGenerator.hh"
using namespace std;

#define MAX_ARG_COUNT 4

void printUsageAndExit()
{
    cout << "Decaf Compiler Usage:" << endl;
    cout << "=====================" << endl;
    cout << "decaf -i <InputFile> [-o <OutputFile>] [-h]\n" << endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printUsageAndExit();
    }

    string sInputFileName = "";
    string sOutputFileName = "";
    
    // Validating Input Arguments - START
    int sOpt;
    opterr = 0;
    char* pInputFileName = NULL;
    char* pOutputFileName = NULL;
    while ((sOpt = getopt(argc, argv, "i:o:h")) != -1)
    {
        switch(sOpt)
        {
            case 'h':
                printUsageAndExit();
                break;
            case 'i':
                pInputFileName = optarg;
                break;
            case 'o':
                pOutputFileName = optarg;
                break;
            case '?':
                if (optopt != 'o' && optopt != 'i' )
                {
                    cerr << "[ERROR] Unknown Option: " << (char)optopt << endl;
                }
                else
                {
                    cerr << "[ERROR] Missing Argument for -" << (char)optopt << endl;
                }
                printUsageAndExit();
                break;
            default:
                printUsageAndExit();
        }
    }

    if (pInputFileName)
    {
        sInputFileName = string(pInputFileName);
    }
    else
    {
        cerr << "[ERROR] Input File Missing." << endl;
        printUsageAndExit();
    }

    if (pOutputFileName)
    {
        sOutputFileName = string(pOutputFileName);
    }
    else
    {
        sOutputFileName = sInputFileName.substr(sInputFileName.find_last_of("/")+1) + ".ir";
    }

    fstream sInputFile(sInputFileName);
    if (!sInputFile.good())
    {
        if (sInputFileName[0] == '-')
        {
            cerr << "[ERROR] Missing Argument for -i." << endl;
        }
        else
        {
            cerr << "[ERROR] Could not open file: " << sInputFileName << endl;
        }
        return 0;
    }
    // Validating Input Arguments - END


    AstContext sAstCtx;
    decaf::Driver sDriver(sAstCtx);
    LLVMIRGenerator sIRGenerator;

    bool result = sDriver.parse_stream(sInputFile, sInputFileName);

    if (result)
    {
        if (sAstCtx.pRoot != NULL )
        {
            sAstCtx.pRoot->accept(sIRGenerator);
            sIRGenerator.dumpIRCode(sOutputFileName);
        }
    }
    else
    {
        cerr << "[ERROR] Parsing Failed." << endl;
    }
}

