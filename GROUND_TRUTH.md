| File | Line | Rule violated | Current name | Correct name |
|---|---|---|---|---|
| include/transaction/transaction.hpp | 1 | Header files: PascalCase + .hpp/h | transaction.hpp | Transaction.hpp |
| src/clearing/clearingEngine.cpp | 1 | Source files: PascalCase + .cpp | clearingEngine.cpp | ClearingEngine.cpp |
| src/main.cpp | 1 | Source files: PascalCase + .cpp | main.cpp | Main.cpp |
| include/util/DateUtil.hpp | 4 | #defines: UPPERCASE_WITH_UNDERSCORES | default_timeout | DEFAULT_TIMEOUT |
| include/util/DateUtil.hpp | 7 | Helper/utility functions (in namespace): camelCase | ValidateDate | validateDate |
| include/util/DateUtil.hpp | 8 | Output parameters: `out` prefix + Pointer suffix | OutStringPtr | outStringPtr |
| src/util/DateUtil.cpp | 8 | Local variables: `l` prefix + camelCase | Is_Valid | lIsValid |
| src/util/DateUtil.cpp | 10 | Local variables: `l` prefix + camelCase | l_DaysInMonth | lDaysInMonth |
| include/transaction/transaction.hpp | 5 | Enums: PascalCase type | status | Status |
| include/transaction/transaction.hpp | 5 | Enums: UPPERCASE values | failed | FAILED |
| include/transaction/transaction.hpp | 8 | Structs: PascalCase | transactionData | TransactionData |
| include/transaction/transaction.hpp | 10 | Struct member variables: `m` prefix + camelCase | m_id | mId |
| include/transaction/transaction.hpp | 12 | Struct member variables: `m` prefix + camelCase | amount | mAmount |
| include/account/Account.hpp | 9 | Public methods: PascalCase | processTransaction | ProcessTransaction |
| include/account/Account.hpp | 15 | Private/protected methods: camelCase | UpdateInternalState | updateInternalState |
| include/account/Account.hpp | 18 | Static functions: camelCase | is_valid_account | isValidAccount |
| include/account/Account.hpp | 21 | Class member variables: `m` prefix + camelCase | accountId | mAccountId |
| src/account/Account.cpp | 4 | Constants: UPPERCASE_WITH_UNDERSCORES | max_accounts | MAX_ACCOUNTS |
| include/clearing/ClearingEngine.hpp | 11 | Input param + Pointer: inData + dataPtr | inData | inDataPtr |
| include/clearing/ClearingEngine.hpp | 11 | Input param + Pointer: inData + dataPtr | targetAcc | inTargetAccPtr |
| include/clearing/ClearingEngine.hpp | 15 | In/out parameters: `io` prefix + Pointer suffix | ioBatch | ioBatchPtr |
| include/clearing/ClearingEngine.hpp | 15 | Output parameters: `out` prefix + Pointer suffix | ErrorCount | outErrorCountPtr |
| src/clearing/clearingEngine.cpp | 17 | Local + Pointer: lBuffer + bufferPtr | lTemp | lTempPtr |
| src/main.cpp | 8 | Global/standalone functions: PascalCase | startupSystem | StartupSystem |
| src/main.cpp | 15 | Local + Pointer: lBuffer + bufferPtr | lAcc | lAccPtr |
| src/main.cpp | 18 | Local + Pointer: lBuffer + bufferPtr | TrxPtr | lTrxPtr |
| src/main.cpp | 28 | Local variables: `l` prefix + camelCase | errCount | lErrCount |
| src/main.cpp | 33 | Local + Pointer: lBuffer + bufferPtr | account_ptr | lAccountPtr |
| src/main.cpp | 38 | Local variables: `l` prefix + camelCase | res | lRes |
| src/main.cpp | 43 | Local variables: `l` prefix + camelCase | ioTrx | lTrx |