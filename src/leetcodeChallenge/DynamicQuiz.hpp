/*
 * DynamicQuiz.hpp
 *
 *  Created on: May 2, 2015
 *      Author: johnny
 */

#ifndef DYNAMICQUIZ_HPP_
#define DYNAMICQUIZ_HPP_

#include "ChallengeBase.hpp"
#include <unordered_set>

class DynamicQuiz : public ChallengeBase {
public:
	DynamicQuiz() {}

	void test() override;

	~DynamicQuiz() {}


	// LeetCode  5 Longest Palindromic Substring 20.7% Medium
	std::string longestPalindrome(std::string s);

	std::string expandAroundCenter(std::string s, int a, int b);

	// LeetCode 139  Word Break  22.9%  Medium
	bool wordBreak(string s, unordered_set <string> &wordDict);

	void test139();

	// LeetCode 140  Word Break II  17.6%  Hard
	void test5();

	// LeetCode 64  Minimum Path Sum  32.2%  Medium
	void test64();

	int minPathSum(vector<vector<int>> &grid);

	// LeetCode  70  Climbing Stairs  34.4%  Easy
	void test70();

	int climbStairs(int n);

	// LeetCode 198   House Robber  29.5% Easy
	int rob(vector<int> &house);

	void test198();

	// LeetCode 213  House Robber II 26.9%   Medium
	int rob2(vector<int> &nums);

	int rob1(vector<int> &nums, int begin, int end);

	void test213();

	// LeetCode 91  Decode Ways 16.3%   Medium
	int numDecodings(string s);

	void test91();

	// LeetCode 55 Jump Game   26.9%   Medium
	bool canJump(vector<int> &nums);

	void test55();

	// LeetCode 45 Jump Game II    24.1%   Hard
	int jump(vector<int> &nums);

	void test45();

	// LeetCode 72	Edit Distance 26.5% Hard
	int minDistance(string word1, string word2);

	int minDistance2(string word1, string word2);

	void test72();

	// LeetCode 62	Unique Paths	33.2%	Medium
	int uniquePaths(int m, int n);

	void test62();

	// LeetCode 221. Maximal Square
	int maximalSquare(vector<vector<char>> &matrix);
};

#endif /* DYNAMICQUIZ_HPP_ */
