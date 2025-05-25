#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.hpp"


class IAccount {
public:
    virtual ~IAccount() = default;
    virtual void deposit(double) = 0;
    virtual void withdraw(double) = 0;
};


class MockAccount : public IAccount {
public:
    MOCK_METHOD(void, deposit, (double), (override));
    MOCK_METHOD(void, withdraw, (double), (override));
};

class AdapterAccount : public IAccount {
public:
    AdapterAccount(Account& acc) : account(acc) {}

    void deposit(double amt) override { account.deposit(amt); }
    void withdraw(double amt) override { account.withdraw(amt); }

private:
    Account& account;
};

TEST(TransactionTest, TransferMovesMoney) {
    Account a(100);
    Account b;

    Transaction t;
    t.transfer(a, b, 60.0);

    EXPECT_EQ(a.getBalance(), 40.0);
    EXPECT_EQ(b.getBalance(), 60.0);
}
