/*
 * Matrix.hpp
 *
 *  Created on: May 20, 2015
 *      Author: johnny
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_
#include <vector>
using namespace std;
class Matrix {
  public:
    Matrix() {}

    vector<vector<int>> multiply(const vector<vector<int>> &A, const vector<vector<int>> &B);
    void test();
    void print(const vector<vector<int>> &C);
    virtual ~Matrix() {}
};

#endif /* MATRIX_HPP_ */
