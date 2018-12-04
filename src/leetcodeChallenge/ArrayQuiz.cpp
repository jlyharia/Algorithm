/*
 * ArrayQuiz.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include "ArrayQuiz.hpp"
#include <unordered_map>

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


int ArrayQuiz::lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> map;
    int maxLen = 0;

    for (int i = 0, j = 0; i < s.size(); i++) {
        if (map.find(s[i]) != map.end()) {
            j = std::max(map[s[i]] + 1, j);
        }

        maxLen = std::max(maxLen, i - j + 1);
        map[s[i]] = i;
    }
    return maxLen;
}