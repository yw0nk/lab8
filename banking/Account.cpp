#include "Account.hpp"

Account::Account(double initial) : balance(initial) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    balance -= amount;
}

double Account::getBalance() const {
    return balance;
}

