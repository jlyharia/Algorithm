/*
 * ArrayQuiz.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include "ArrayQuiz.hpp"

vector<int> ArrayQuiz::twoSum(vector<int> &&nums, int target) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        auto find = map.find(nums[i]);
        if (find != map.end() && map.at(nums[i]) != i) {
            result.push_back(i);
            result.push_back(map.at(nums[i]));
            break;
        }
        map[target - nums[i]] = i;
    }
    return result;
}