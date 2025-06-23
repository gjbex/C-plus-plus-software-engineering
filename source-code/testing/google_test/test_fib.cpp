#include "fib.h"
#include <stdexcept>
#include <gtest/gtest.h>

TEST(FibTest, NegativeInput) {
  EXPECT_THROW(fib(-1), std::invalid_argument);
  EXPECT_THROW(fib(-10), std::invalid_argument);
}

TEST(FibTest, BaseCases) {
  EXPECT_EQ(fib(0), 1);
  EXPECT_EQ(fib(1), 1);
}

TEST(FibTest, RecursiveCases) {
  EXPECT_EQ(fib(2), 2);
  EXPECT_EQ(fib(3), 3);
  EXPECT_EQ(fib(4), 5);
  EXPECT_EQ(fib(5), 8);
  EXPECT_EQ(fib(6), 13);
  EXPECT_EQ(fib(7), 21);
}
