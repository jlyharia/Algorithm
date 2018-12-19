//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <BackTracking.hpp>

using namespace std;

BackTracking bt;

TEST (BackTracking, Letter_Combinations_of_a_Phone_Number) {
    {
        vector<string> ss{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        EXPECT_EQ(ss, bt.letterCombinations("23"));
    }
}
