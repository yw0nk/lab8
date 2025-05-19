#include <gtest/gtest.h>
#include "print.hpp"

TEST(PrintTest, BasicUsage) {
    EXPECT_NO_THROW(print("Hello, test!"));
}
