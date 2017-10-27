/*
 * MatrixQuiz.h
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#ifndef MATRIXQUIZ_HPP_
#define MATRIXQUIZ_HPP_
#include "ChallengeBase.hpp"

class MatrixQuiz : public ChallengeBase {
  public:
    MatrixQuiz() {}
    void test() override;
    ~MatrixQuiz() {}

  private:
    // LeetCode 74 Search a 2D Matrix 33.4 Medium
    void test74();
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    // LeetCode 73 Set Matrix Zeroes 33.1% Medium
    void test73();
    void setZeroes(vector<vector<int>> &matrix);

    
};

#endif /* MATRIXQUIZ_HPP_ */
