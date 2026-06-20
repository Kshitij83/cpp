#pragma once
#include "transaction/transaction.hpp"

class Account {
public:
    Account(int inId, double inBalance);
    
    void processTransaction(const transactionData& inTrx);
    
    double GetBalance() const;
    
private:
    void UpdateInternalState();
    
    static bool is_valid_account();
    
    int accountId;
    double mBalance;
};
