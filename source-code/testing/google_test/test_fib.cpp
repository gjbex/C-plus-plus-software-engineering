#include "fib.h"
#include <gtest/gtest.h>

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
