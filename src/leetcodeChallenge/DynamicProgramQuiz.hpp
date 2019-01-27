//
// Created by Yihung Lee on 2018-12-03.
//

#ifndef ALGORITHM_DYNAMICPROGRAMQUIZ_HPP
#define ALGORITHM_DYNAMICPROGRAMQUIZ_HPP

#include "Utils.hpp"
#include <string>

using namespace std;

class DynamicProgramQuiz {
public:
    // 70. Climbing Stairs
    int climbStairs(int n);

    // 322. Coin Change
    int coinChange(std::vector<int> &&coins, int amount);

private:
    int coinChangeDFS(vector<int> &coins, int target, vector<int> &memo);
};


#endif //ALGORITHM_DYNAMICPROGRAMQUIZ_HPP
