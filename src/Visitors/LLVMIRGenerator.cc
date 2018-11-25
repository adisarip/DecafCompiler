
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "LLVMIRGenerator.hh"
using namespace std;
using namespace llvm;

/* All the visit() functions in this class is for LLVM IR generation */

LLVMIRGenerator::LLVMIRGenerator()
{
    mLlvmConstructsPtr = new LLVMConstructs();
}

void LLVMIRGenerator::dumpIRCode()
{
    mLlvmConstructsPtr->mModulePtr->print(llvm::outs(), NULL);
}

void LLVMIRGenerator::visit(Program& nodeParm)
{
    FieldDeclarationsList* pFieldsList = nodeParm.getFieldDeclarationsListPtr();
    MethodDeclarationsList* pMethodsList = nodeParm.getMethodDeclarationsListPtr();

    if (pFieldsList)
    {
        pFieldsList->accept(*this);
    }

    if (pMethodsList)
    {
        pMethodsList->accept(*this);
    }
}


void LLVMIRGenerator::visit(FieldDeclarationsList& nodeParm)
{
    typedef vector<class FieldDeclaration*> FDList;
    FDList sFieldDeclList = nodeParm.getFieldDeclarationsList();

    for (FDList::iterator it = sFieldDeclList.begin(); it != sFieldDeclList.end(); it++)
    {
        (*it)->accept(*this);
    }

    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
}


void LLVMIRGenerator::visit(FieldDeclaration& nodeParm)
{
    llvm::Type* pDeclType = NULL; // int or boolean
    VariablesList* pVariablesList = NULL;
    string sDataType = nodeParm.getDataType();

    if (sDataType == "int")
    {
        pDeclType = Type::getInt32Ty(mLlvmConstructsPtr->mContext);
    }
    else if (sDataType == "boolean")
    {
        pDeclType = Type::getInt1Ty(mLlvmConstructsPtr->mContext);
    }
    else
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Type. Supported Types: 'int' and 'boolean' only.");
    }

    // IR Generation for Global Variables
    ArrayType* pArrType = NULL;
    GlobalVariable* pGVar = NULL;
    pVariablesList = nodeParm.getVariablesListPtr();
    if (pVariablesList)
    {
        typedef vector<class Variable*> VList;
        VList sVariablesList = pVariablesList->getVariablesList();
        for (VList::iterator it = sVariablesList.begin(); it != sVariablesList.end(); it++)
        {
            Variable* pVar = (*it);
            pVar->getDeclarationType();
            if (Variable::ARRAY_DECLARATION == pVar->getDeclarationType())
            {
                pArrType = ArrayType::get(pDeclType,
                                          pVar->getArraySize());
                pGVar = new GlobalVariable(*mLlvmConstructsPtr->mModulePtr,
                                            pArrType,
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            NULL,
                                            pVar->getVariableName());
                pGVar->setInitializer(ConstantAggregateZero::get(pArrType));
            }
            else
            {
                pGVar = new GlobalVariable(*mLlvmConstructsPtr->mModulePtr,
                                            pDeclType,
                                            false,
                                            GlobalValue::ExternalLinkage,
                                            NULL,
                                            pVar->getVariableName());
                pGVar->setInitializer(Constant::getNullValue(pDeclType));
            }
        }
    }

    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
}


void LLVMIRGenerator::visit(VariablesList& nodeParm)
{
    // IR Generated as part of "FieldDeclaration"
}


void LLVMIRGenerator::visit(Variable& nodeParm)
{
    // IR Generated as part of "FieldDeclaration"
}


void LLVMIRGenerator::visit(MethodDeclarationsList& nodeParm)
{
    Value* pValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 0));
    typedef vector<class MethodDeclaration*> MDList;
    MDList sMethodDeclList = nodeParm.getMethodDeclList();

    for (MDList::iterator it = sMethodDeclList.begin(); it != sMethodDeclList.end(); it++)
    {
        MethodDeclaration* pMDecl = (*it);
        pMDecl->accept(*this); // fills mValuePtr
        pValue = mValuePtr;
        if (NULL == pValue)
        {
            break;
        }
    }
    mValuePtr = pValue;
}   


void LLVMIRGenerator::visit(MethodDeclaration& nodeParm)
{
    vector<string> sMethodParmNamesList;
    vector<string> sMethodParmTypesList;
    vector<Type *> sTypeList;
    
    // Create the Parameters list
    ParametersList* pParmsListPtr = nodeParm.getParmsListPtr();
    if (pParmsListPtr)
    {
        typedef vector<class Parameter*> Parm;
        Parm pParmsList = pParmsListPtr->getParametersList();
        for (Parm::iterator it = pParmsList.begin(); it != pParmsList.end(); it++)
        {
            Parameter* pParm = (*it);
            string sParmName = pParm->getName();
            string sParmType = pParm->getType();
            if (sParmType == "int")
            {
                Type* pType = Type::getInt32Ty(mLlvmConstructsPtr->mContext);
                sTypeList.push_back(pType);
            }
            else if (sParmType == "boolean")
            {
                Type* pType = Type::getInt1Ty(mLlvmConstructsPtr->mContext);
                sTypeList.push_back(pType);
            }
            else
            {
                mLlvmConstructsPtr->mErrors++;
                logError("Parameters can only be 'int' or 'boolean' : " + sParmType);
            }
            sMethodParmNamesList.push_back(sParmName);
            sMethodParmTypesList.push_back(sParmType);
        }
    }

    // Create Return Type
    Type* pReturnType = NULL;
    string sReturnType = nodeParm.getReturnType();
    string sMethodName = nodeParm.getMethodName();
    if (sReturnType == "int")
    {
        pReturnType = Type::getInt32Ty(mLlvmConstructsPtr->mContext);
    }
    else if (sReturnType == "boolean")
    {
        pReturnType = Type::getInt1Ty(mLlvmConstructsPtr->mContext);
    }
    else if (sReturnType == "void")
    {
        pReturnType = Type::getVoidTy(mLlvmConstructsPtr->mContext);
    }
    else
    {
        // Increment error count
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid return type " + sReturnType + " for " + sMethodName + "." +
                 "Return type can only be 'int', 'boolean' or 'void'.");
        mValuePtr = NULL;
        return;
    }

    // Create Method/Function
    FunctionType* pFuncType = FunctionType::get(pReturnType,
                                                sTypeList,
                                                false);
    Function* pFunc = Function::Create(pFuncType,
                                       Function::ExternalLinkage,
                                       sMethodName,
                                       mLlvmConstructsPtr->mModulePtr);
    
    // set the argument names
    unsigned int sIndex = 0;
    unsigned int sSize = sMethodParmNamesList.size();
    for (Function::arg_iterator it = pFunc->arg_begin();
         sIndex != sSize && it != pFunc->arg_end();
         sIndex++, it++)
    {
        it->setName(sMethodParmNamesList[sIndex]);
    }

    // Assign a new basic block for this function/method
    BasicBlock* pBB = BasicBlock::Create(mLlvmConstructsPtr->mContext,
                                         "Start",
                                         pFunc);
    mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pBB);

    // Allocating memory for function parameters
    sIndex = 0;
    for (auto &sParm : pFunc->args())
    {
        AllocaInst* pA = mLlvmConstructsPtr->CreateFunctionStack(pFunc,
                                                                 sMethodParmNamesList[sIndex],
                                                                 sMethodParmTypesList[sIndex]);
        mLlvmConstructsPtr->mBuilderPtr->CreateStore(&sParm, pA);
        mLlvmConstructsPtr->mNamedValuesMap[sMethodParmNamesList[sIndex]] = pA;
        sIndex++;
    }

    Value* pRetValue = NULL;
    BlockStatement* pBlockStmt = nodeParm.getBlockStmtPtr();
    if (pBlockStmt)
    {
        pBlockStmt->accept(*this); // fills mValuePtr
        pRetValue = mValuePtr;
        if (pRetValue)
        {
            if (sReturnType != "void")
            {
                mLlvmConstructsPtr->mBuilderPtr->CreateRet(pRetValue);
            }
            else
            {
                mLlvmConstructsPtr->mBuilderPtr->CreateRetVoid();
            }
            
            //@TODO : Removal of Dead Code

            // Verify the Function
            verifyFunction(*pFunc);
            mLlvmConstructsPtr->mFPMPtr->run(*pFunc);
            pRetValue = pFunc;
        }
    }
    mValuePtr = pRetValue;

    // Remove the function in case of errors
    if (mLlvmConstructsPtr->mErrors > 0)
    {
        pFunc->eraseFromParent();
    }
}


void LLVMIRGenerator::visit(ParametersList& nodeParm)
{
    // IR Generated as part of "MethodDeclaration"
}


void LLVMIRGenerator::visit(Parameter& nodeParm)
{
    // IR Generated as part of "MethodDeclaration"
}


void LLVMIRGenerator::visit(BlockStatement& nodeParm)
{
    Value* pValue = NULL;
    // list to store scoped variables when switching between block scopes
    std::map<std::string, llvm::AllocaInst*> sOldValues;

    VariableDeclarationsList* pVarDeclListPtr = nodeParm.getVarDeclListPtr();
    if (pVarDeclListPtr)
    {
        Value* pDeclListValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));

        typedef vector<class VariableDeclaration*> VDecl;
        VDecl sVariableDeclList = pVarDeclListPtr->getVariableDeclList();
        for (VDecl::iterator it = sVariableDeclList.begin(); it != sVariableDeclList.end(); it++)
        {
            VariableDeclaration* pVarDecl = (*it);
            Function* pFunc = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock()->getParent();
            vector<string> sVarList = pVarDecl->getIdListPtr()->getIdList();

            for (vector<string>::iterator ik = sVarList.begin(); ik != sVarList.end(); ik++)
            {
                string sVar = (*ik);
                Value* pDeclValue = NULL;
                AllocaInst* pAI = NULL;

                if ("int" == pVarDecl->getDeclarationType())
                {
                    pDeclValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 0));
                    pAI = mLlvmConstructsPtr->CreateFunctionStack(pFunc, sVar, "int");
                }
                else if ("boolean" == pVarDecl->getDeclarationType())
                {
                    pDeclValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(1, 0));
                    pAI = mLlvmConstructsPtr->CreateFunctionStack(pFunc, sVar, "boolean");  
                }

                mLlvmConstructsPtr->mBuilderPtr->CreateStore(pDeclValue, pAI);
                
                // Store the old value to sOldValues and new value to named values map
                sOldValues[sVar] = mLlvmConstructsPtr->mNamedValuesMap[sVar];
                mLlvmConstructsPtr->mNamedValuesMap[sVar] = pAI;
            }
            pDeclListValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
            if (NULL == pDeclListValue)
            {
                break;
            }
        }
        pValue = pDeclListValue;
    }

    if (NULL == pValue)
    {
        mValuePtr = pValue;
        return;
    }

    if (nodeParm.getStmtListPtr())
    {
        nodeParm.getStmtListPtr()->accept(*this); // fills mValuePtr
    }

    /* Restore the old values */
    for (auto it = sOldValues.begin(); it != sOldValues.end(); it++)
    {
        mLlvmConstructsPtr->mNamedValuesMap[it->first] = sOldValues[it->first];
    }
}


void LLVMIRGenerator::visit(VariableDeclarationsList& nodeParm)
{
    // IR Generated as part of "BlockStatement"
}


void LLVMIRGenerator::visit(VariableDeclaration& nodeParm)
{
    // IR Generated as part of "BlockStatement"
}


void LLVMIRGenerator::visit(IdentifiersList& nodeParm)
{
    // IR Generated as part of "BlockStatement"
}


void LLVMIRGenerator::visit(StatementsList& nodeParm)
{
    Value* pValue = NULL;
    typedef vector<class Statement*> StmtList;
    StmtList sStmtPtrList = nodeParm.getStmtPtrList();
    
    pValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
    for (StmtList::iterator it = sStmtPtrList.begin(); it != sStmtPtrList.end(); it++)
    {
        (*it)->accept(*this); // fills mValuePtr
        pValue = mValuePtr;
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(AssignmentStatement& nodeParm)
{
    string sVarName = nodeParm.getLocationPtr()->getVariableName();
    Value* pCurValue = mLlvmConstructsPtr->mNamedValuesMap[sVarName];
    if (NULL == pCurValue)
    {
        pCurValue = mLlvmConstructsPtr->mModulePtr->getGlobalVariable(sVarName);
        if (NULL == pCurValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Unknown Variable Name: " + sVarName);
            mValuePtr = pCurValue;
            return;
        }
    }

    Value* pValue = NULL;
    Expression* pExpr = nodeParm.getAssignmentExprPtr();
    if (pExpr)
    {
        pExpr->accept(*this); // fills mValuePtr
        pValue = mValuePtr;

        if (Expression::LOCATION == pExpr->getExpressionType())
        {
            pValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pValue); // Load
        }

        if (NULL == pValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Error in RHS of Assignment Expression.");
            mValuePtr = pValue;
            return;
        }
    }

    Value* pLhsValue = NULL;
    VariableLocation* pLoc = nodeParm.getLocationPtr();
    if (pLoc)
    {
        pLoc->accept(*this); // fills mValuePtr
        pLhsValue = mValuePtr;
    }
    pCurValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pLhsValue); // Load

    string sOp = nodeParm.getAssignmentOp();
    if (sOp == "+=")
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateAdd(pCurValue,
                                                            pValue,
                                                            "PlusEqualTo");
    }
    else if (sOp == "-=")
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateAdd(pCurValue,
                                                            pValue,
                                                            "MinusEqualTo");
    }

    // Store
    mValuePtr = mLlvmConstructsPtr->mBuilderPtr->CreateStore(pValue, pLhsValue);

}


void LLVMIRGenerator::visit(VariableLocation& nodeParm)
{
    mValuePtr = NULL;
    string sVarName = nodeParm.getVariableName();
    Value* pCurValue = mLlvmConstructsPtr->mNamedValuesMap[sVarName];
    if (NULL == pCurValue)
    {
        pCurValue = mLlvmConstructsPtr->mModulePtr->getNamedGlobal(sVarName);
        if (NULL == pCurValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Unknown Variable: " + sVarName);
            return;
        }
    }

    // If location is variable fill the code generated
    if (VariableLocation::VARIABLE == nodeParm.getLocationType())
    {
        mValuePtr = pCurValue;
        return;
    }

    // If we have an index for array
    Expression* pArrIdxExpr = nodeParm.getArrayIndexPtr();
    if (pArrIdxExpr == NULL)
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Array Index");
        return;
    }

    // Generate the code for array index
    pArrIdxExpr->accept(*this); // this fills mValuePtr
    Value* pArrIdxValue = mValuePtr;
    if (Expression::LOCATION == pArrIdxExpr->getExpressionType())
    {
        pArrIdxValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pArrIdxValue);
        if (pArrIdxValue == NULL)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Invalid Array Index.");
            return;
        }
    }

    // code to access array - given array index
    vector<Value*> sArrIdxList;
    sArrIdxList.push_back(mLlvmConstructsPtr->mBuilderPtr->getInt32(0));
    sArrIdxList.push_back(pArrIdxValue);
    mValuePtr = mLlvmConstructsPtr->mBuilderPtr->CreateGEP(pCurValue,
                                                           sArrIdxList,
                                                           sVarName + "_idx");
}


void LLVMIRGenerator::visit(IfElseStatement& nodeParm)
{
    Expression* pCondExpr  = nodeParm.getCondExprPtr();
    if (pCondExpr)
    {
        pCondExpr->accept(*this); // fills the mValuePtr
        if (NULL == mValuePtr)
        {
            logError("IF Condition Expression Invalid.");
            return;
        }
    }

    Function* pFunc = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock()->getParent();
    BasicBlock* pllvmIfBlock = BasicBlock::Create(mLlvmConstructsPtr->mContext, "If", pFunc);
    BasicBlock* pllvmElseBlock = BasicBlock::Create(mLlvmConstructsPtr->mContext, "Else");
    BasicBlock* pllvmNextBlock = BasicBlock::Create(mLlvmConstructsPtr->mContext, "IfNext");
    BasicBlock* pllvmOtherBlock = pllvmElseBlock;

    // Creating conditional break and an insert point
    BlockStatement* pElseBlock = nodeParm.getElseBlockPtr();
    if (NULL == pElseBlock)
    {
        pllvmOtherBlock = pllvmNextBlock;
    }

    mLlvmConstructsPtr->mBuilderPtr->CreateCondBr(mValuePtr,
                                                  pllvmIfBlock,
                                                  pllvmOtherBlock);
    mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pllvmIfBlock);

    // generate code for IF Block
    BlockStatement* pIfBlock   = nodeParm.getIfBlockPtr();
    if (pIfBlock)
    {
        pIfBlock->accept(*this); // fills mValuePtr
        if (NULL == mValuePtr)
        {
            return;
        }
    }

    bool sRetIf = pIfBlock->hasReturnValue();
    bool sRetElse = false;

    if (false == sRetIf)
    {
        mLlvmConstructsPtr->mBuilderPtr->CreateBr(pllvmNextBlock);
    }
    pllvmIfBlock = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock();

    // Create Else Block insert point.
    if (pElseBlock)
    {
        pFunc->getBasicBlockList().push_back(pllvmElseBlock);
        mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pllvmElseBlock);

        pElseBlock->accept(*this); // fills mValuePtr
        if (NULL == mValuePtr)
        {
            return;
        }
    }

    sRetElse = pElseBlock->hasReturnValue();
    if (false == sRetElse)
    {
        mLlvmConstructsPtr->mBuilderPtr->CreateBr(pllvmNextBlock);
    }

    // Create entry for next part of the code
    pFunc->getBasicBlockList().push_back(pllvmNextBlock);
    mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pllvmNextBlock);
    if (true == sRetIf && true == sRetElse)
    {
        // If IF and ELSE blocks have a return statement,
        // then create a temporary instruction to hold the next block
        Type* pRetType = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock()->getParent()->getReturnType();
        if (pRetType == Type::getVoidTy(mLlvmConstructsPtr->mContext))
        {
            mLlvmConstructsPtr->mBuilderPtr->CreateRetVoid();
        }
        else
        {
            Value* pV = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 0));
            mLlvmConstructsPtr->mBuilderPtr->CreateRet(pV);
        }
    }

    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 0));
}


void LLVMIRGenerator::visit(ForStatement& nodeParm)
{
    Expression* pInitExpr = nodeParm.getInitExprPtr();
    Value* pStartValue = NULL;
    if (pInitExpr)
    {
        pInitExpr->accept(*this);
        pStartValue = mValuePtr;
        if (NULL == pStartValue)
        {
            return;
        }

        if (Expression::LOCATION == pInitExpr->getExpressionType())
        {
            pStartValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pStartValue);
        }
    }

    // Get the parent function
    Function* pFunc = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock()->getParent();
    
    // creating stack memory for loop variables
    string sInitValue = nodeParm.getInitValue();
    AllocaInst* pAI = mLlvmConstructsPtr->CreateFunctionStack(pFunc,
                                                              sInitValue,
                                                              "int");
    mLlvmConstructsPtr->mBuilderPtr->CreateStore(pStartValue, pAI);
    
    Value* pStepValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
    BasicBlock* pPrevBB = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock();
    BasicBlock* pLoopBB = BasicBlock::Create(mLlvmConstructsPtr->mContext,
                                             "Loop",
                                             pFunc);
    BasicBlock* pAfterBB = BasicBlock::Create(mLlvmConstructsPtr->mContext,
                                              "AfterLoop",
                                              pFunc);
    mLlvmConstructsPtr->mBuilderPtr->CreateBr(pLoopBB);
    mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pLoopBB);

    PHINode* pPhiNodeVariable = 
    mLlvmConstructsPtr->mBuilderPtr->CreatePHI(Type::getInt32Ty(mLlvmConstructsPtr->mContext),
                                               2,
                                               sInitValue);
    pPhiNodeVariable->addIncoming(pStartValue, pPrevBB);
    
    // Condition Expression
    Expression* pCondExpr = nodeParm.getCondExprPtr();
    Value* pCondValue = NULL;
    if (pCondExpr)
    {
        pCondExpr->accept(*this); // fills mValuePtr
        pCondValue = mValuePtr;
        if (NULL == pCondValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Invalid Condition");
            return;
        }
        if (Expression::LOCATION == pCondExpr->getExpressionType())
        {
            pCondValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pCondValue);
        }
    }

    LoopInfo* pLI = new LoopInfo(pAfterBB,
                                 pLoopBB,
                                 pCondValue,
                                 pPhiNodeVariable,
                                 sInitValue);
    mLlvmConstructsPtr->mLoopsListPtr->push(pLI);
    AllocaInst* pOldValue = mLlvmConstructsPtr->mNamedValuesMap[sInitValue];
    mLlvmConstructsPtr->mNamedValuesMap[sInitValue] = pAI;

    // Loop body - Code generation
    BlockStatement* pForBlock = nodeParm.getForBlockPtr();
    if (pForBlock)
    {
        pForBlock->accept(*this); // fills mValuePtr
        if (NULL == mValuePtr)
        {
            return;
        }
    }

    Value* pCurValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pAI,
                                                                   sInitValue);
    Value* pNextValue = mLlvmConstructsPtr->mBuilderPtr->CreateAdd(pCurValue,
                                                                   pStepValue,
                                                                   "NextValue");
    mLlvmConstructsPtr->mBuilderPtr->CreateStore(pNextValue, pAI);
    pCondValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpSLT(pNextValue,
                                                                pCondValue,
                                                                "LoopCondition");
    BasicBlock* pLoopEndBB = mLlvmConstructsPtr->mBuilderPtr->GetInsertBlock();
    mLlvmConstructsPtr->mBuilderPtr->CreateCondBr(pCondValue,
                                                  pLoopBB,
                                                  pAfterBB);
    mLlvmConstructsPtr->mBuilderPtr->SetInsertPoint(pAfterBB);
    pPhiNodeVariable->addIncoming(pNextValue, pLoopEndBB);

    if (pOldValue)
    {
        mLlvmConstructsPtr->mNamedValuesMap[sInitValue] = pOldValue;
    }
    else
    {
        mLlvmConstructsPtr->mNamedValuesMap.erase(sInitValue);
    }

    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
}


void LLVMIRGenerator::visit(ReturnStatement& nodeParm)
{
    Expression* pRetExpr = nodeParm.getReturnExprPtr();
    Value* pValue = NULL;
    if (pRetExpr)
    {
        pRetExpr->accept(*this);
        pValue = mValuePtr;
        if (Expression::LOCATION == pRetExpr->getExpressionType())
        {
            pValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pValue);
        }
        mLlvmConstructsPtr->mBuilderPtr->CreateRet(pValue);
    }
    else
    {
        mLlvmConstructsPtr->mBuilderPtr->CreateRetVoid();
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(BreakStatement& nodeParm)
{
    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
    LoopInfo* pCurLoop = mLlvmConstructsPtr->mLoopsListPtr->top();
    mLlvmConstructsPtr->mBuilderPtr->CreateBr(pCurLoop->getAfterBBPtr());
}


void LLVMIRGenerator::visit(ContinueStatement& nodeParm)
{
    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
    LoopInfo* pCurLoop = mLlvmConstructsPtr->mLoopsListPtr->top();
    string sLoopVariable = pCurLoop->getLoopVariable();
    AllocaInst* pAI = mLlvmConstructsPtr->mNamedValuesMap[sLoopVariable];
    Value* pStepValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(32, 1));
    Value* pCurValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pAI, sLoopVariable);
    Value* pNextValue = mLlvmConstructsPtr->mBuilderPtr->CreateAdd(pCurValue,
                                                                   pStepValue,
                                                                   "NextValue");
    mLlvmConstructsPtr->mBuilderPtr->CreateStore(pNextValue, pAI);
    Value* pCondValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpULE(pNextValue,
                                                                       pCurLoop->getCondValuePtr(),
                                                                       "LoopCondition");
    mLlvmConstructsPtr->mBuilderPtr->CreateCondBr(pCondValue,
                                                  pCurLoop->getCheckBBPtr(),
                                                  pCurLoop->getAfterBBPtr());
}


void LLVMIRGenerator::visit(UserDefinedMethodCall& nodeParm)
{
    Value* pValue = NULL;
    string sMethodName = nodeParm.getMethodName();
    ExpressionsList* pArgListPtr = nodeParm.getArgsListPtr();
    
    // Get reference to the function to be called
    Function* pUserFunc = mLlvmConstructsPtr->mModulePtr->getFunction(sMethodName);
    if (NULL == pUserFunc)
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Unknown Function Name: " + sMethodName);
        mValuePtr = NULL;
        return;
    }

    vector<Expression*> sArgExprList = pArgListPtr->getExpressionsList();
    vector<Value*> sArgValuesList;
    // Check if required number of parameters are passed
    if (sArgExprList.size() != pUserFunc->arg_size())
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Incorrect Number Of Parameters Passed For Function: " + sMethodName);
        mValuePtr = NULL;
        return;
    }
    // Generating IR for arguments
    Value* pExprValue = NULL;
    for (auto it = sArgExprList.begin(); it != sArgExprList.end(); it++)
    {
        Expression* pArgExpr = (*it);
        pArgExpr->accept(*this); // fills mValuePtr
        pExprValue = mValuePtr;
        
        if (Expression::LOCATION == pArgExpr->getExpressionType())
        {
            pExprValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pExprValue);
        }

        if (NULL == pExprValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Argument Invalid in Function: " + sMethodName);
            break;
        }
        sArgValuesList.push_back(pExprValue);
    }

    if (pExprValue)
    {
        // Parser parses the arguments in reverse order
        // Thus we reverse the arguments order
        reverse(sArgValuesList.begin(), sArgValuesList.end());

        // Generate the IR for Function Call
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateCall(pUserFunc, sArgValuesList);
    }
    else
    {
        pValue = pExprValue;
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(CalloutMethodCall& nodeParm)
{
    vector<Type*> sArgTypesList;
    vector<Value*> sArgValuesList;
    Value* pValue = NULL;
    CalloutArgumentsList* pCalloutArgListPtr = nodeParm.getCalloutArgsListPtr();

    if (pCalloutArgListPtr)
    {
        Value* pArgValue = NULL;
        typedef vector<class CalloutArgument*> CAList;
        CAList sCArgsList = pCalloutArgListPtr->getCalloutArgsList();
        for (CAList::iterator it = sCArgsList.begin(); it != sCArgsList.end(); it++)
        {
            CalloutArgument* pCalloutArg = (*it);
            pCalloutArg->accept(*this); // fills mValuePtr
            pArgValue = mValuePtr;
            if (NULL == pArgValue)
            {
                return;
            }
            sArgValuesList.push_back(pArgValue);
            sArgTypesList.push_back(pArgValue->getType());
        }

        // IR Generation for Function Execution
        ArrayRef<Type*> sArgsTypesRef(sArgTypesList);
        ArrayRef<Value*> sArgsValuesRef(sArgValuesList);
        FunctionType* pFuncType = FunctionType::get(Type::getInt32Ty(mLlvmConstructsPtr->mContext),
                                                    sArgsTypesRef,
                                                    false);
        string sMethodName = nodeParm.getMethodName();
        Constant* pFuncConst = mLlvmConstructsPtr->mModulePtr->getOrInsertFunction(sMethodName,
                                                                                   pFuncType);
        if (pFuncConst)
        {
            pValue = mLlvmConstructsPtr->mBuilderPtr->CreateCall(pFuncConst,
                                                                 sArgsValuesRef);
        }
        else
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Unknown Function Name: " + sMethodName);
        }
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(CalloutArgumentsList& nodeParm)
{
    // IR Generated as part of CalloutMethodCall
}


void LLVMIRGenerator::visit(CalloutArgument& nodeParm)
{
    Value* pValue = NULL;
    Expression* pCalloutExpr = nodeParm.getCalloutExprPtr();
    string sCalloutArgString = nodeParm.getCalloutArgString();

    if (pCalloutExpr)
    {
        pCalloutExpr->accept(*this); // fills mValuePtr
        pValue = mValuePtr;
        
        if (Expression::LOCATION == pCalloutExpr->getExpressionType())
        {
            pValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pValue);
        }
    }
    else if (sCalloutArgString != "")
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateGlobalStringPtr(sCalloutArgString);
    }
    else
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Callout Argument");
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(ExpressionsList& nodeParm)
{
    // IR generated as part of UserDefinedMethodCall
}


void LLVMIRGenerator::visit(UnaryExpression& nodeParm)
{
    nodeParm.getRightExprPtr()->accept(*this);

    string sUnOp = nodeParm.getUnaryOperator();
    Expression* pRightExpr = nodeParm.getRightExprPtr();
    Value* pRightValue = NULL;

    if (pRightExpr)
    {
        pRightExpr->accept(*this); // fills mValueptr
        pRightValue = mValuePtr;

        if (Expression::LOCATION == pRightExpr->getExpressionType())
        {
            pRightValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pRightValue);
        }

        if (NULL == pRightValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Invalid Right Operand of " + sUnOp);
            return;
        }
    }

    // generate the code based on operator
    Value* pValue = NULL;
    if ("-" == sUnOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateNeg(pRightValue, "NEG");
    }
    else if ("!" == sUnOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateNot(pRightValue, "NOT");
    }
    else
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Unary Operator " + sUnOp);
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(BinaryExpression& nodeParm)
{
    string sBinOp = nodeParm.getBinOperator();
    Expression* pLeftExpr = nodeParm.getLeftExprPtr();
    Expression* pRightExpr = nodeParm.getRightExprPtr();
    Value* pLeftValue = NULL;
    Value* pRightValue = NULL;

    if (pLeftExpr)
    {
        pLeftExpr->accept(*this); // fill mValuePtr
        pLeftValue = mValuePtr;

        if (Expression::LOCATION == pLeftExpr->getExpressionType())
        {
            pLeftValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pLeftValue);
        }

        if (NULL == pLeftValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Invalid Left Operand of " + sBinOp);
            return;
        }
    }

    if (pRightExpr)
    {
        pRightExpr->accept(*this);
        pRightValue = mValuePtr;

        if (Expression::LOCATION == pRightExpr->getExpressionType())
        {
            pRightValue = mLlvmConstructsPtr->mBuilderPtr->CreateLoad(pRightValue);
        }

        if (NULL == pRightValue)
        {
            mLlvmConstructsPtr->mErrors++;
            logError("Invalid Right Operand of " + sBinOp);
            return;
        }
    }

    Value* pValue = NULL;
    if ("+" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateAdd(pLeftValue,
                                                            pRightValue,
                                                            "ADD");
    }
    else if ("-" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateSub(pLeftValue,
                                                            pRightValue,
                                                            "SUB");
    }
    else if ("*" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateMul(pLeftValue,
                                                            pRightValue,
                                                            "MUL");
    }
    else if ("/" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateSDiv(pLeftValue,
                                                            pRightValue,
                                                            "DIV");
    }
    else if ("%" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateSRem(pLeftValue,
                                                            pRightValue,
                                                            "MOD");
    }
    else if ("<" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpSLT(pLeftValue,
                                                                pRightValue,
                                                                "CLT");
    }
    else if (">" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpSGT(pLeftValue,
                                                                pRightValue,
                                                                "CGT");
    }
    else if ("<=" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpSLE(pLeftValue,
                                                                pRightValue,
                                                                "CLE");
    }
    else if (">=" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpSGE(pLeftValue,
                                                                pRightValue,
                                                                "CGE");
    }
    else if ("==" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpEQ(pLeftValue,
                                                                pRightValue,
                                                                "CEQ");
    }
    else if ("!=" == sBinOp)
    {
        pValue = mLlvmConstructsPtr->mBuilderPtr->CreateICmpNE(pLeftValue,
                                                                pRightValue,
                                                                "CNE");
    }
    else
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Binary Operator " + sBinOp);
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(EnclosedExpression& nodeParm)
{
    Expression* pExpr = nodeParm.getExprPtr();
    if (pExpr)
    {
        pExpr->accept(*this); // fills mValuePtr
    }
}


void LLVMIRGenerator::visit(IntegerLiteral& nodeParm)
{
    int sValue = nodeParm.getValue();
    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext,
                                 APInt(32, static_cast<uint64_t>(sValue)));
}


void LLVMIRGenerator::visit(BooleanLiteral& nodeParm)
{
    string sValue = nodeParm.getBoolValue();
    Value* pValue = NULL;
    bool sBoolValue;
    if ("true" == sValue)
    {
        sBoolValue = true;
        pValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(1, sBoolValue));
    }
    else if ("false" == sValue)
    {
        sBoolValue = false;
        pValue = ConstantInt::get(mLlvmConstructsPtr->mContext, APInt(1, sBoolValue));
    }
    else
    {
        mLlvmConstructsPtr->mErrors++;
        logError("Invalid Boolean Literal: " + sValue); 
    }

    mValuePtr = pValue;
}


void LLVMIRGenerator::visit(HexadecimalLiteral& nodeParm)
{
    long int sHexValue = nodeParm.getHexValue();
    mValuePtr = ConstantInt::get(mLlvmConstructsPtr->mContext,
                                 APInt(64, static_cast<uint64_t>(sHexValue)));
}


void LLVMIRGenerator::visit(CharacterLiteral& nodeParm)
{
    cout << "IR: Character Literal:" << nodeParm.getCharValue() << endl;
}

