#include "account/Account.hpp"

const int max_accounts = 1000;

Account::Account(int inId, double inBalance) 
    : accountId(inId), mBalance(inBalance) {
}

void Account::processTransaction(const transactionData& inTrx) {
    if (is_valid_account()) {
        double lAmt = inTrx.amount;
        mBalance += lAmt;
        UpdateInternalState();
    }
}

double Account::GetBalance() const {
    return mBalance;
}

void Account::UpdateInternalState() {
}

bool Account::is_valid_account() {
    return true;
}
