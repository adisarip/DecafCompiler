
#include <vector>
#include "ExpressionsList.hh"
using namespace std;


void ExpressionsList::add(class Expression* pExprParm)
{
    mExprList.push_back(pExprParm);
}


vector<class Expression*>
ExpressionsList::getExpressionsList()
{
    return mExprList;
}


void ExpressionsList::accept(Visitor& vParm)
{
    vParm.visit(*this);
}
