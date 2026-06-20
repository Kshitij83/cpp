#include "util/DateUtil.hpp"
#include <cstring>
#include <cstdio>

namespace util {
    bool ValidateDate(int inYear, int inMonth, int inDay) {
        bool Is_Valid = true;
        int l_DaysInMonth = 31;
        
        if (inYear < 0 || inMonth < 1 || inMonth > 12 || inDay < 1 || inDay > l_DaysInMonth) {
            Is_Valid = false;
        }
        return Is_Valid;
    }

    void formatAmount(double inAmount, char* OutStringPtr) {
        if (OutStringPtr != nullptr) {
            std::sprintf(OutStringPtr, "%.2f", inAmount);
        }
    }
}
