//
// Created by Yihung Lee on 1'.'/31/17.
//

#include <Utils.hpp>
#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;


Backtracking bt;

TEST (Backtracking, Wildcard_match) {
    /**
        '?' Matches any single character.
        '*' Matches any sequence of characters (including the empty sequence).
     */
    EXPECT_TRUE(bt.isMatchWildcard("aa", "*"));
    EXPECT_TRUE(bt.isMatchWildcard("ab", "?*"));

    EXPECT_FALSE(bt.isMatchWildcard("aab", "c*a*b"));
}

TEST (Backtracking, Sudoku_Solver) {

    vector<vector<char>> board{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//	5 3 4 6 7 8 9 1 2
//	6 7 2 1 9 5 3 4 8
//	1 9 8 3 4 2 5 6 7
//	8 5 9 7 6 1 4 2 3
//	4 2 6 8 5 3 7 9 1
//	7 1 3 9 2 4 8 5 6
//	9 6 1 5 3 7 2 8 4
//	2 8 7 4 1 9 6 3 5
//	3 4 5 2 8 6 1 7 9

    bt.solveSudoku(board);
//	printMatrix(board);
    EXPECT_EQ('6', board[8][5]);
    EXPECT_EQ('1', board[8][6]);
}

TEST (Backtracking, Permutation) {

    auto ans = bt.permute({1, 2, 3});
    EXPECT_EQ(3, ans[5][0]);
    EXPECT_EQ(2, ans[5][1]);
    EXPECT_EQ(1, ans[5][2]);

    auto ans2 = bt.permute({5, 4, 6, 2});
    EXPECT_EQ(2, ans2[23][0]);
    EXPECT_EQ(6, ans2[23][1]);
    EXPECT_EQ(4, ans2[23][2]);
    EXPECT_EQ(5, ans2[23][3]);
}

// 77. Combinations
TEST (Backtracking, Combination) {
    auto ans = bt.combine(4, 2);
    printMatrix(ans);
}

TEST (Backtracking, printBinary) {
    bt.printBinary(3);
}

TEST (Backtracking, PermutationII) {
    bt.permuteUnique({1, 1, 2});
}