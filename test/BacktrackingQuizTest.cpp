//
// Created by Yihung Lee on 1'.'/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;

int isOdd() {
	return 2;
}

template<typename T>
void printMatrix(vector<vector<T>> mat) {
	cout << endl;
	for (auto row: mat) {
		for (auto e: row) {
			cout << e << " ";
		}
		cout << endl;
	}
}

Backtracking bt;

TEST (Backtracking, sudokuSolver) {
//	EXPECT_EQ (2, isOdd());

	vector<vector<char>> board{
			{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '2', '.', '.', '1'},
			{'7', '.', '.', '.', '3', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	printMatrix(board);
//	bt.solveSudoku(board);
}