
#include <map>
#include <string>
#include "LLVMConstructs.hh"
using namespace std;
using namespace llvm;


// Constructor
LLVMConstructs::LLVMConstructs()
{
    mErrors = 0;
    mLoopsListPtr = new std::stack<LoopInfo*>();
    mBuilderPtr = new IRBuilder<>(mContext);
    mModulePtr = new Module("Decaf", mContext);
    mFPMPtr = new legacy::FunctionPassManager(mModulePtr);
    mFPMPtr->doInitialization();
}


AllocaInst*
LLVMConstructs::CreateFunctionStack(Function* pFuncParm,
                                    string varNameParm,
                                    string varTypeParm)
{
    IRBuilder<> sBuilder(&pFuncParm->getEntryBlock(),
                         pFuncParm->getEntryBlock().begin());
    
    AllocaInst *pAInst = NULL;
    if (varTypeParm == "int")
    {
        pAInst = sBuilder.CreateAlloca(Type::getInt32Ty(mContext),
                                       0,
                                       varNameParm);
    }
    else if (varTypeParm == "boolean")
    {
        pAInst = sBuilder.CreateAlloca(Type::getInt1Ty(mContext),
                                       0,
                                       varNameParm);
    }

    return pAInst;
}
