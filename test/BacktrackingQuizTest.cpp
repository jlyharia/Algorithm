//
// Created by Yihung Lee on 1'.'/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;

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
