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

TEST (BackTracking, Sudoku_Solver) {
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

    vector<vector<char>>
            ans = {
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };
    bt.solveSudoku(board1);
    EXPECT_EQ(ans, board1);
}

TEST (BackTracking, Combination_Sum) {
    vector<vector<int>> ans = bt.combinationSum({2,3,6,7}, 7);
}