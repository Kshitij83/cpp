#pragma once
#include "transaction/transaction.hpp"
#include "account/Account.hpp"

class ClearingEngine {
public:
    ClearingEngine();

    void SettleTransaction(transactionData* inData, Account* targetAcc);
    
    void ProcessBatch(transactionData* ioBatch, int inCount, int* ErrorCount);
    
private:
    int mTotalProcessed;
};
