//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;


TEST (Dynamic_Programming, Maximal_Square) {

	vector<vector<char>> matrix(2, std::vector<char>(4, '0'));;
	DynamicQuiz dq;
	EXPECT_EQ (0, dq.maximalSquare(matrix));

}