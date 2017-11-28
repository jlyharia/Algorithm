//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"

using namespace std;

int isEven() {
	return 2;
}

TEST (SquareRootTest, PositiveNos) {
	EXPECT_EQ (3, isEven());

//	vector<vector<int> > matrix = {{1,  3,  5,  7},
//								   {10, 11, 16, 20},
//								   {23, 30, 34, 50}};
//
//	MatrixQuiz mxQ;
//	mxQ.test();
//	cout << searchMatrix(matrix, 50) << endl;
}