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

TEST (BackTracking, Generate_Parentheses) {
    {
        vector<string> ss{
                "((()))",
                "(()())",
                "(())()",
                "()(())",
                "()()()"
        };
        EXPECT_EQ(ss, bt.generateParenthesis(3));
    }
}

TEST (BackTracking, Next_Permutation) {
    vector<int> nums1 = {1, 2, 3};
    bt.nextPermutation(nums1);
    vector<int> ans1 = {1, 3, 2};
    EXPECT_EQ(ans1, nums1);


    vector<int> nums2 = {3, 2, 1};
    bt.nextPermutation(nums2);
    vector<int> ans2 = {1, 2, 3};
    EXPECT_EQ(ans2, nums2);
}