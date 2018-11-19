
#ifndef LLVM_CONSTRUCTS_H
#define LLVM_CONSTRUCTS_H


#include <map>
#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "llvm/IR/Module.h"
#include <llvm/IR/Value.h>
#include <llvm/IR/LegacyPassManager.h>
using namespace std;


class LLVMConstructs
{
  public:
    
    // Constructor
    LLVMConstructs();
    
    
    // Data
    int mErrors;                // Number of errors occured during IR generation
    llvm::LLVMContext mContext; // Context owns core LLVM data structures
                                // such as the type and constant value tables.
    llvm::Module* mModulePtr;   // Module is an LLVM construct that contains functions and global
                                // variables. In many ways, it is the top-level structure that the
                                // LLVM IR uses to contain code. It will own the memory for all of
                                // the IR that we generate.

    // The Builder object is a helper object that makes it easy to generate LLVM instructions. Instances of the
    // IRBuilder class template keep track of the current place to insert instructions and has methods
    // to create new instructions.
    llvm::IRBuilder<>* mBuilderPtr;

    // The NamedValues map keeps track of which values are defined in the current scope and what their
    // LLVM representation is. (In other words, it is a symbol table for the code).
    map<string, llvm::AllocaInst*> mNamedValuesMap;

    // A FunctionPassManager to hold and organize the LLVM optimizations that we want to run
    llvm::legacy::FunctionPassManager* mFPMPtr;

    // Data
    

};

#endif /* LLVM_CONSTRUCTS_H */
