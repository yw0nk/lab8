#include "Transaction.hpp"

void Transaction::transfer(Account& from, Account& to, double amount) {
    from.withdraw(amount);
    to.deposit(amount);
}

