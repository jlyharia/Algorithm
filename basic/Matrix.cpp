/*
 * Matrix.cpp
 *
 *  Created on: May 20, 2015
 *      Author: johnny
 */

#include <Matrix.hpp>
#include <cstdio>
#include <iostream>
/**
 * Cache Efficient Matrix Multiplication
 * http://functionspace.org/articles/40/Cache-aware-Matrix-Multiplication---Naive-isn--039;t-that-bad-
 */
vector<vector<int>> Matrix::multiply(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    vector<vector<int>> C(3, vector<int>(3, 0));

    //	for (int i = 0; i < A.size(); i++) {
    //		for (int j = 0; j < A.size(); j++) {
    //			for (int k = 0; k < A.size(); k++) {
    //				printf("A[%i][%i] * B[%i][%i] +", i, k, k, j);
    //				C[i][j] += A[i][k] * B[k][j];
    //			}
    //			cout << endl;
    //		}
    //
    //	}
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < A.size(); k++) {
            for (int j = 0; j < A.size(); j++) {
                printf("C[%i][%i] = A[%i][%i] * B[%i][%i] +", i, j, i, k, k, j);
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << endl;
        }
    }

    return C;
}
void Matrix::test() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> C = this->multiply(A, B);
    print(C);
}

void Matrix::print(const vector<vector<int>> &C) {
    for (auto &rows : C) {
        for (auto &elem : rows) {
            cout << elem << " ";
        }
        cout << endl;
    }
}
