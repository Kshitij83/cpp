#pragma once

#define default_timeout 30

namespace util {
    bool ValidateDate(int inYear, int inMonth, int inDay);
    void formatAmount(double inAmount, char* OutStringPtr);
}
