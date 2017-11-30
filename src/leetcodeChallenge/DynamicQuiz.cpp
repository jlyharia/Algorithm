/*
 * DynamicQuiz.cpp
 *
 *  Created on: May 2, 2015
 *      Author: johnny
 */

#include "DynamicQuiz.hpp"

using namespace std;

/**
 * LeetCode   5 Longest Palindromic Substring 20.7% Medium
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 */
string DynamicQuiz::longestPalindrome(string s) {
	if (s.size() == 0) return "";

	string substr = s.substr(0, 1);

	for (int i = 0; i < s.size(); i++) {
		string str = expandAroundCenter(s, i, i);
		//		cout << str << endl;
		if (str.size() > substr.size()) substr = str;
	}
	for (int i = 0; i < s.size() - 1; i++) {
		string str = expandAroundCenter(s, i, i + 1);
		//		cout << str << endl;
		if (str.size() > substr.size()) substr = str;
	}
	return substr;
}

// return the length of palindrome which centered between s[i] and s[j]
string DynamicQuiz::expandAroundCenter(string s, int l, int r) {
	int n = s.length();
	while (l >= 0 && r < n && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}

void DynamicQuiz::test5() {
	cout << "LeetCode 5 Longest Palindromic Substring 20.7% Medium" << endl;
	string str = "bananas123321";
	//	string str = "b";
	cout << "input string = " << str << endl;
	cout << "Longest Palindromic Substring = " << longestPalindrome(str) << endl;

	//	cout << expandAroundCenter(str, 3, 3) << endl;
}

/**
 * LeetCode 139  Word Break  22.9%  Medium
 Given a string s and a dictionary of words dict, determine if s can be segmented into a
space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */
bool DynamicQuiz::wordBreak(string s, unordered_set<string> &wordDict) {

	vector<bool> dp(s.size() + 1, false);
	for (auto i = 0; i <= s.size(); ++i) {
		if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
			dp[i] = true;
		} else {
			for (auto j = 0; j < i; ++j) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
	}
	return dp.back();
}

void DynamicQuiz::test139() {
	cout << "LeetCode 139  Word Break  22.9%  Medium" << endl;
	std::unordered_set<std::string> wordDict({"leet", "code"});
	string s = "leetcode";
	auto result = wordBreak(s, wordDict);
	cout << result;
}

/**
 * LeetCode 64  Minimum Path Sum  32.2%  Medium
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all
 *numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */
int DynamicQuiz::minPathSum(vector<vector<int>> &grid) {
	vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

	for (auto i = 0; i < dp.size(); ++i) {
		for (auto j = 0; j < dp[i].size(); ++j) {
			if (i == 0 && j == 0) {
				dp[i][j] = grid[i][j];
			} else if (i == 0) {
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			} else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			} else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
	}

	for (auto &row : dp) {
		for (auto &var : row) {
			cout << var << " ";
		}
		cout << endl;
	}
	return dp[dp.size() - 1][dp[0].size() - 1];
}

void DynamicQuiz::test64() {
	cout << "LeetCode 64  Minimum Path Sum  32.2%  Medium" << endl;
	//	vector<vector<int>> grid = { { 3, 4, 3, 3, 1 }, { 2, 3, 2, 2, 3 }, { 1,
	// 4,
	//			3, 4, 4 }, { 1, 2, 1, 2, 2 }, { 4, 1, 4, 1, 1 } };
	vector<vector<int>> grid = {{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}};
	for (auto &row : grid) {
		for (auto &var : row) {
			cout << var << " ";
		}
		cout << endl;
	}
	auto minSum = minPathSum(grid);
	cout << "minSum = " << minSum << endl;
}

/**
 * LeetCode  70  Climbing Stairs  34.4%  Easy
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 * hint: fibonacci
 http://www.cnblogs.com/springfor/p/3886576.html
 */
int DynamicQuiz::climbStairs(int n) {
	if (n < 3) { return n; }
	auto f1 = 1;
	auto f2 = 2;
	for (auto i = 3; i <= n; i++) {
		f2 = f1 + f2;
		f1 = f2 - f1;
	}
	return f2;
}

void DynamicQuiz::test70() {
	cout << "LeetCode  70  Climbing Stairs  34.4%  Easy" << endl;
	auto n = 6;
	cout << "n = " << n << endl;
	auto result = climbStairs(n);
	cout << result << endl;
}

/**
LeetCode 198   House Robber  29.5% Easy
 You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed,
 the only constraint stopping you from robbing each of them is that adjacent
houses have security system connected and
 it will automatically contact the police if two adjacent houses were broken
into on the same night.

 Given a list of non-negative integers representing the amount of money of each
house,
 determine the maximum amount of money you can rob tonight without alerting the
police.
*/
int DynamicQuiz::rob(vector<int> &num) {

	if (num.size() <= 1) return num.empty() ? 0 : num[0];

	std::vector<int> dp = {num[0], max(num[0], num[1])};

	for (auto i = 2; i < num.size(); ++i) {
		dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
	}

	return dp.back();
}

void DynamicQuiz::test198() {
	cout << "LeetCode 198   House Robber  29.5% Easy" << endl;
	std::vector<int> house = {3, 2, 6, 11, 7, 10, 5, 9};
	cout << rob(house) << endl;
}

/**
LeetCode 213  House Robber II 26.9%   Medium
After robbing those houses on that street, the thief has found himself a new
place for his thievery so that he will not get too much attention. This time,
all houses at this place are arranged in a circle. That means the first house is
the neighbor of the last one. Meanwhile, the security system for these houses
remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.
*/
int DynamicQuiz::rob2(vector<int> &nums) {
	if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];

	return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
}

int DynamicQuiz::rob1(vector<int> &nums, int begin, int end) {
	int a = 0, b = 0;
	for (int i = begin; i < end; ++i) {
		int m = a, n = b;
		a = n + nums[i];
		b = max(m, n);

		// cout << i << " " << a << "  " << b << " " << m << " " << n << endl;
	}
	return max(a, b);
}

void DynamicQuiz::test213() {
	cout << "LeetCode 213  House Robber II 26.9%   Medium" << endl;
	std::vector<int> house = {3, 2, 6, 11, 7, 10, 5, 9};
	// cout << rob2(house) << endl;
	cout << rob1(house, 0, house.size()) << endl;
}

/**
 LeetCode 91  Decode Ways 16.3%   Medium
 A message containing letters from A-Z is being encoded to numbers using the
following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways
to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

http://www.cnblogs.com/springfor/p/3896162.html
http://fisherlei.blogspot.com/2013/01/leetcode-decode-ways-solution.html
 */

int DynamicQuiz::numDecodings(string s) {

	if (s.empty() || s[0] == '0') return 0;

	auto checkOne = [=](char c) { return c != '0' ? true : false; };
	auto checkTwo = [=](char a, char b) {
		return (a == '1' || (a == '2' && b <= '6')) ? true : false;
	};
	if (s.length() == 1) return checkOne(s[0]);

	std::vector<int> dp(s.length() + 1, 0);
	dp[0] = 1;

	if (checkOne(s[0])) {
		dp[1] = 1;
	} else
		return 0;

	for (int i = 2; i < s.length() + 1; i++) {
		if (checkOne(s[i - 1])) dp[i] += dp[i - 1];

		if (checkTwo(s[i - 2], s[i - 1])) dp[i] += dp[i - 2];

		// cout << i << " " << dp[i] << endl;
	}

	return dp.back();
}

void DynamicQuiz::test91() {
	cout << "LeetCode 91  Decode Ways 16.3%   Medium" << endl;
	auto s = "10";
	cout << numDecodings(s) << endl;
}

/**
LeetCode 55 Jump Game   26.9%   Medium
Given an array of non-negative integers, you are initially positioned at the first index of the
array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
http://www.cnblogs.com/TenosDoIt/p/3719630.html
*/
bool DynamicQuiz::canJump(vector<int> &nums) {
	auto far = 0;
	for (auto i = 0; i < nums.size(); i++) {
		far--;
		far = nums[i] > far ? nums[i] : far;
		if (far == 0 && i != nums.size() - 1) return false;
	}
	return true;
}

void DynamicQuiz::test55() {
	cout << "LeetCode 55 Jump Game   26.9%   Medium" << endl;
	std::vector<int> nums = {2, 3, 1, 1, 4};
	// std::vector<int> nums = {3, 2, 1, 0, 4};
	// std::vector<int> nums = {0};
	for (const auto &i : nums) {
		cout << i << ' ';
	}
	cout << endl;
	cout << canJump(nums) << endl;
}
/** LeetCode 45 Jump Game II    24.1%   Hard
Given an array of non-negative integers, you are initially positioned at the first index of the
array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3
steps to the last index.)
http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
*/
/*
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
 */
int DynamicQuiz::jump(vector<int> &nums) {
	int ret = 0;
	int last = 0;
	int curr = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (i > last) {
			last = curr;
			++ret;
		}
		curr = max(curr, i + nums[i]);
	}

	return ret;
}

void DynamicQuiz::test45() {
	cout << "LeetCode 45 Jump Game II 24.1% Hard" << endl;
	// std::vector<int> nums = {2, 3, 1, 1, 4};
	// std::vector<int> nums = {3, 2, 2, 0, 4};
	std::vector<int> nums = {2, 1, 1, 1, 1};
	for (const auto &i : nums) {
		cout << i << ' ';
	}
	cout << endl;
	cout << jump(nums) << endl;
}

/**
 LeetCode 62	Unique Paths	33.2%	Medium
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 */
int DynamicQuiz::uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 1));
	for (auto i = 1; i < m; ++i) {
		for (auto j = 1; j < n; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

void DynamicQuiz::test62() {
	cout << "LeetCode 62	Unique Paths 33.2% Medium" << endl;
	cout << uniquePaths(4, 3) << endl;
}

/**
LeetCode 72	Edit Distance 26.5% Hard
Given two words word1 and word2, find the minimum number of steps required to convert word1 to
word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
int DynamicQuiz::minDistance(string word1, string word2) {
	// http://www.cnblogs.com/springfor/p/3896167.html
	// https://www.youtube.com/watch?v=We3YDTzNXEk
	auto len1 = word1.length() + 1;
	auto len2 = word2.length() + 1;
	vector<vector<int>> dp(len1, vector<int>(len2, 0));

	for (auto i = 0; i < len1; i++) {
		dp[i][0] = i;
	}
	for (auto j = 0; j < len2; j++) {
		dp[0][j] = j;
	}
	for (auto i = 1; i < len1; i++) {
		for (auto j = 1; j < len2; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = 1 + std::min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
			}
		}
	}

	// for(auto row:dp){
	//     for(auto c:row){
	//         cout<<c<<" ";
	//     }
	//     cout<<endl;
	// }

	return dp[len1 - 1][len2 - 1];
}

int DynamicQuiz::minDistance2(string word1, string word2) {
	// optimize extra space
	auto len1 = word1.length() + 1;
	auto len2 = word2.length() + 1;
	vector<int> dp(len1, 0);

	for (auto j = 0; j < len1; j++) {
		dp[j] = j;
	}
	auto temp = 0;
	auto cur = 0;
	for (auto i = 1; i < len2; i++) {
		for (auto j = 0; j < len1; j++) {
			if (j == 0) {
				temp = dp[j];
				dp[j] = i;
			} else {
				cur = dp[j];
				if (word2[i - 1] == word1[j - 1]) {
					dp[j] = temp;
				} else {
					dp[j] = 1 + std::min({dp[j - 1], dp[j], temp});
					// cout<<"-"<<dp[j - 1]<<" "<< dp[j]<<" "<< temp<<"- ";
				}
				temp = cur;
			}
			cout << dp[j] << " ";
			// if(i==1 && j==1)
			// break;
		}
		cout << endl;
	}

	return dp.back();
}

void DynamicQuiz::test72() {
	cout << "LeetCode 72	Edit Distance 26.5% Hard" << endl;
	auto s1 = "hellow";
	auto s2 = "ellowra";
	cout << "string 1 = " << s1 << endl;
	cout << "string 2 = " << s2 << endl;
	// cout << "minDistance1 = " << endl<<minDistance(s1, s2) << endl;
	cout << "minDistance2 = " << endl << minDistance2(s1, s2) << endl;
}


int DynamicQuiz::maximalSquare(vector<vector<char>> &matrix) {
	int ln = 0; // length of the square
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

	for (auto i = 0; i < matrix.size(); i++) {
		dp[i][0] = matrix[i][0] - '0';
		ln = std::max(dp[i][0], ln);
	}
	for (auto i = 0; i < matrix[0].size(); i++) {
		dp[0][i] = matrix[0][i] - '0';
		ln = std::max(dp[0][i], ln);
	}
	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[i].size(); j++) {
			dp[i][j] = matrix[i][j] == '1' ? std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1 : 0;
			ln = std::max(ln, dp[i][j]);
		}
	}

	return ln * ln;
}

void DynamicQuiz::test() {
	// test5();
	// test139();
	// test64();
	// test70();
	// test198();
	// test213();
	// test91();
	// test55();
	// test45();
	// test62();
	test72();
}
