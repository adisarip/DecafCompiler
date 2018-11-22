
#ifndef LLVM_CONSTRUCTS_H
#define LLVM_CONSTRUCTS_H

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "llvm/IR/Module.h"
#include <llvm/IR/Value.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/CFG.h>
#include <llvm/IR/Instructions.h>
#include <string>
#include <map>
#include <stack>
using namespace std;
using namespace llvm;


// Hold the data of one loop instance
class LoopInfo
{
  public:
    LoopInfo(BasicBlock* pAfterBBParm,
             BasicBlock* pCheckBBParm,
             Value* pCondValueParm,
             PHINode* pPhiNodeParm,
             string loopVariableParm)
    :mAfterBBPtr(pAfterBBParm)
    ,mCheckBBPtr(pCheckBBParm)
    ,mCondValuePtr(pCondValueParm)
    ,mPhiNodePtr(pPhiNodeParm)
    ,mLoopVariable(loopVariableParm) {}

    inline BasicBlock* getAfterBBPtr()
    {
        return mAfterBBPtr;
    }

    inline BasicBlock* getCheckBBPtr()
    {
        return mCheckBBPtr;
    }

    inline Value*  getCondValuePtr()
    {
        return mCondValuePtr;
    }

    inline PHINode* getPhiNodePtr()
    {
        return mPhiNodePtr;
    }

    inline string getLoopVariable()
    {
        return mLoopVariable;
    }

  private:
    BasicBlock* mAfterBBPtr;
    BasicBlock* mCheckBBPtr;
    Value* mCondValuePtr;
    PHINode* mPhiNodePtr;
    string mLoopVariable;
};


class LLVMConstructs
{
  public:
    
    // Constructor
    LLVMConstructs();

    // Create stack allocation instructions for function parameters
    AllocaInst* CreateFunctionStack(Function* pFuncParm,
                                    string varNameParm,
                                    string varTypeParm);

    // DATA SECTION
    int mErrors;              // Number of errors occured during IR generation
    LLVMContext mContext;     // Context owns core LLVM data structures
                              // such as the type and constant value tables.
    Module* mModulePtr;       // Module is an LLVM construct that contains functions and global
                              // variables. In many ways, it is the top-level structure that the
                              // LLVM IR uses to contain code. It will own the memory for all of
                              // the IR that we generate.
    IRBuilder<>* mBuilderPtr; // The Builder object is a helper object that makes it easy to
                              // generate LLVM instructions. Instances of the IRBuilder class
                              // template keep track of the current place to insert instructions
                              // and has methods to create new instructions.
    legacy::FunctionPassManager* mFPMPtr;     // A FunctionPassManager to hold and organize the
                                              // LLVM optimizations that we want to run
    map<string, AllocaInst*> mNamedValuesMap; // The NamedValues map keeps track of which values
                                              // are defined in the current scope and what their
                                              // LLVM representation is. (In other words, it is
                                              // a symbol table for the code).
    stack<LoopInfo*>* mLoopsListPtr; // A Stack DS to maintain all the instances of a loop statement
};

#endif /* LLVM_CONSTRUCTS_H */
