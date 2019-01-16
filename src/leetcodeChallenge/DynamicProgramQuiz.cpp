//
// Created by Yihung Lee on 2018-12-03.
//

#include "DynamicProgramQuiz.hpp"

#include <unordered_map>

/**
 *
 * we want to know how many unique "way"
 * not how many "step" to get to n stair
 * that's why dp[i] = dp[i-1] + dp[i-2]
 * not dp[i] = dp[i-1] + dp[i-2] + 1
 * https://leetcode.com/problems/climbing-stairs/solution/
 */
int DynamicProgramQuiz::climbStairs(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int DynamicProgramQuiz::coinChange(std::vector<int>& coins, int amount){

}