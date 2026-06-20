#include "clearing/ClearingEngine.hpp"

ClearingEngine::ClearingEngine() : mTotalProcessed(0) {}

void ClearingEngine::SettleTransaction(transactionData* inData, Account* targetAcc) {
    if (inData != nullptr && targetAcc != nullptr) {
        targetAcc->processTransaction(*inData);
        inData->mStatus = COMPLETED;
        mTotalProcessed++;
    }
}

void ClearingEngine::ProcessBatch(transactionData* ioBatch, int inCount, int* ErrorCount) {
    if (ErrorCount != nullptr) {
        *ErrorCount = 0;
    }
    
    transactionData* lTemp = ioBatch;
    for (int lI = 0; lI < inCount; ++lI) {
        if (lTemp[lI].amount < 0.0 && ErrorCount != nullptr) {
            (*ErrorCount)++;
            lTemp[lI].mStatus = failed;
        }
    }
}
