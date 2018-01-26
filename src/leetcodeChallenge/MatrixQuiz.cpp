/*
 * MatrixQuiz.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include <Utils.hpp>
#include "MatrixQuiz.hpp"
// LeetCode 74 Search a 2D Matrix 33.4 Medium
void MatrixQuiz::test74() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    cout << searchMatrix(matrix, 50) << endl;
}
bool MatrixQuiz::searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) return false;
    if (matrix[0].size() == 0) return false;
    if (target < matrix[0][0]) return false;

    int row = -1;
    int begin = 0;
    int end = matrix.size();
    const uint n = matrix[0].size();
    while (begin < end) {
        int m = (begin + end) / 2;
        if (target < matrix[m][0]) {
            end = m;
        } else if (target > matrix[m][n - 1]) {
            begin = m + 1;
        } else {
            row = m;
            break;
        }
    }
    begin = 0;
    end = n;
    if (row >= 0) {
        while (begin < end) {
            int m = (begin + end) / 2;
            if (target < matrix[row][m]) {
                end = m;
            } else if (target > matrix[row][m]) {
                begin = m + 1;
            } else {
                return true;
            }
        }
    }
    return false;
}

void MatrixQuiz::setZeroes(vector<vector<int>> &matrix) {
    bool firstRow = false, firstCol = false;
    uint m = matrix.size();
    uint n = matrix[0].size();
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    // check if there is zero in first row
    for (auto i = 0; i < n; i++) {
        if (matrix[0][i] == 0) {
            firstRow = true;
            break;
        }
    }
    // check if there is zero in first column
    for (auto i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }
    cout << firstRow << " " << firstCol << endl;
    // check set zero on first row and column
    for (auto i = 1; i < m; i++) {
        for (auto j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (auto i = 1; i < m; i++)
        for (auto j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    // set matrix zero, first row
    if (firstCol == true)
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
            cout << matrix[0][i] << "-";
        }
    if (firstRow == true)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
}
void MatrixQuiz::test73() {
    vector<vector<int>> matrix = {{1, 0, 3}};
    printMatrix(matrix);

    cout << "new line" << endl;

    setZeroes(matrix);
    printMatrix(matrix);
}
void MatrixQuiz::test() {
    test74();
    test73();
}
