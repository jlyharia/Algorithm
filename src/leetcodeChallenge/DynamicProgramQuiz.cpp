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

/**
 *
 * http://www.cnblogs.com/grandyang/p/5138186.html
 */
int DynamicProgramQuiz::coinChange(std::vector<int> &&coins, int amount) {
    vector<int> memo(amount + 1, INT_MAX);
    memo[0] = 0;
    return coinChangeDFS(coins, amount, memo);
}

int DynamicProgramQuiz::coinChangeDFS(vector<int> &coins, int target, vector<int> &memo) {
    if (target < 0) return -1;
    if (memo[target] != INT_MAX) return memo[target];
    // cannot found any match from catch then continue
    for (int i = 0; i < coins.size(); ++i) {
        int tmp = coinChangeDFS(coins, target - coins[i], memo);
        // none of memo will not be set to -1 here
        if (tmp >= 0) memo[target] = min(memo[target], tmp + 1);
    }
    return memo[target] = (memo[target] == INT_MAX) ? -1 : memo[target];
}