
#include <map>
#include <string>
#include "LLVMConstructs.hh"
using namespace std;


// Constructor
LLVMConstructs::LLVMConstructs()
{
    mErrors = 0;
    mBuilderPtr = new llvm::IRBuilder<>(mContext);
    mModulePtr = new llvm::Module("Decaf", mContext);
    mFPMPtr = new llvm::legacy::FunctionPassManager(mModulePtr);
    mFPMPtr->doInitialization();
}
