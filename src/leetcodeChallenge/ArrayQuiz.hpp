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
#include <string>

using namespace std;

class ArrayQuiz {
public:
    //1. Two Sum
    vector<int> twoSum(vector<int> &&nums, int target);


    //3. Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring(std::string s);
};

#endif /* ARRAYQUIZ_HPP_ */
