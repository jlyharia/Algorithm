/*
 * ArrayQuiz.h
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#ifndef ARRAYQUIZ_HPP_
#define ARRAYQUIZ_HPP_

#include <vector>
#include <unordered_map>
using namespace std;

class ArrayQuiz {
public:
    ArrayQuiz() {}
    //1. Two Sum
    vector<int> twoSum(vector<int> &&nums, int target);

    ~ArrayQuiz() {}
};

#endif /* ARRAYQUIZ_HPP_ */
