#include <gtest/gtest.h>
#include "Account.hpp"

TEST(AccountTest, InitialBalanceIsZero) {
    Account acc;
    EXPECT_EQ(acc.getBalance(), 0.0);
}

TEST(AccountTest, DepositIncreasesBalance) {
    Account acc;
    acc.deposit(100.0);
    EXPECT_EQ(acc.getBalance(), 100.0);
}

TEST(AccountTest, WithdrawDecreasesBalance) {
    Account acc(200.0);
    acc.withdraw(50.0);
    EXPECT_EQ(acc.getBalance(), 150.0);
}
