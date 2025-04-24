#include <gtest/gtest.h>
#include "../nodes/Value.h"
#include "../nodes/Sum.h"

TEST(SumTest, AddsTwoPositiveValues) {
    auto left = std::make_unique<Value>(3.0);
    auto right = std::make_unique<Value>(7.0);
    Sum sum(std::move(left), std::move(right));

    EXPECT_DOUBLE_EQ(sum.calc(), 10.0);
}

TEST(SumTest, AddsNegativeValues) {
    auto left = std::make_unique<Value>(-4.0);
    auto right = std::make_unique<Value>(-6.0);
    Sum sum(std::move(left), std::move(right));

    EXPECT_DOUBLE_EQ(sum.calc(), -10.0);
}