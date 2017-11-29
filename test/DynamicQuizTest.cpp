//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;

DynamicQuiz dq;

TEST (Dynamic_Programming, Maximal_Square) {

	vector<vector<char>> matrix {{'1', '0', '1','0', '0'},
								 {'1', '0', '1','1', '1'},
								 {'1', '1', '1','1', '1'},
								 {'1', '0', '0','1', '0'}};

	EXPECT_EQ (0, dq.maximalSquare(matrix));
}