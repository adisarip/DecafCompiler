
#include <vector>
#include "StatementsList.hh"
using namespace std;


void StatementsList::add(class Statement* pStmtParm)
{
    mStmtPtrList.push_back(pStmtParm);
}


bool StatementsList::hasReturnValue()
{
    bool sStatus = false;
    // check if any of the statements from the list has a return value
    for (auto& stmt : mStmtPtrList)
    {
        if (stmt->hasReturnValue())
        {
            sStatus = true;
            break;
        }
    }
    return sStatus;
}


vector<class Statement*> StatementsList::getStmtPtrList()
{
    return mStmtPtrList;
}


void StatementsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
