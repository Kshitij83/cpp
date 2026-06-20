#pragma once

enum status { PENDING, COMPLETED, failed };

struct transactionData {
    int m_id;
    double amount;
    status mStatus;
};
