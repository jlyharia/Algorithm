//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "DynamicProgramQuiz.hpp"

using namespace std;

DynamicProgramQuiz dp;

TEST (DynamicProgram, Climbing_Stairs) {
    EXPECT_EQ(0, dp.climbStairs(0));
    EXPECT_EQ(1, dp.climbStairs(1));
    EXPECT_EQ(2, dp.climbStairs(2));
    EXPECT_EQ(3, dp.climbStairs(3));
    EXPECT_EQ(8, dp.climbStairs(5));
}

TEST (DynamicProgram, Coin_Change) {
    EXPECT_EQ(3, dp.coinChange({1, 2, 5}, 11));
    EXPECT_EQ(-1, dp.coinChange({2}, 3));
}