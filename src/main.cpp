#include <iostream>
#include "util/DateUtil.hpp"
#include "account/Account.hpp"
#include "clearing/ClearingEngine.hpp"
#include "transaction/transaction.hpp"

void startupSystem() {
    std::cout << "Starting subsystem..." << std::endl;
}

int main() {
    startupSystem();
    
    Account* lAcc = new Account(1, 100.0);
    
    transactionData* TrxPtr = new transactionData[2];
    TrxPtr[0].m_id = 1;
    TrxPtr[0].amount = 50.0;
    TrxPtr[0].mStatus = PENDING;
    
    TrxPtr[1].m_id = 2;
    TrxPtr[1].amount = -10.0;
    TrxPtr[1].mStatus = PENDING;
    
    ClearingEngine lEngine;
    
    int errCount = 0;
    
    lEngine.ProcessBatch(TrxPtr, 2, &errCount);
    lEngine.SettleTransaction(&TrxPtr[0], lAcc);
    
    Account* account_ptr = lAcc;
    std::cout << "Account balance: " << account_ptr->GetBalance() << std::endl;
    std::cout << "Errors: " << errCount << std::endl;
    
    bool res = util::ValidateDate(2026, 6, 19);
    if (res) {
        std::cout << "Date is valid." << std::endl;
    }
    
    transactionData ioTrx;
    ioTrx.m_id = 3;
    ioTrx.amount = 100.0;
    ioTrx.mStatus = PENDING;
    
    delete lAcc;
    delete[] TrxPtr;
    
    return 0;
}
