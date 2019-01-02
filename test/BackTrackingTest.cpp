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

TEST (BackTracking, Valid_Sudoku) {
    vector<vector<char>>
            board1 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    EXPECT_TRUE(bt.isValidSudoku(board1));

    vector<vector<char>>
            board2 = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    EXPECT_FALSE(bt.isValidSudoku(board2));

}