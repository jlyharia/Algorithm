/*
 * ArrayQuiz.h
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#ifndef ARRAYQUIZ_HPP_
#define ARRAYQUIZ_HPP_

#include "ChallengeBase.hpp"

class ArrayQuiz : public ChallengeBase {
public:
	ArrayQuiz() {}

	void test() override;

	~ArrayQuiz() {}

	std::string getRange(int start, int end);

	// LeetCode  1   Two Sum  17.6%  Medium
	std::vector<int> twoSum(const std::vector<int> &numbers, int target);

	void test1();

	// LeetCode  4   Median of Two Sorted Arrays 17.8% Hard
	// LeetCode 15   3Sum  16.9%  Medium
	vector<vector<int>> threeSum(vector<int> &nums);

	void test15();

	// LeetCode 16  3Sum Closest  26.9%   Medium
	int threeSumClosest(vector<int> &nums, int target);

	void test16();

	// LeetCode 26   Remove Duplicates from Sorted Array 31.5% Easy
	int removeDuplicates(std::vector<int> &A);

	// LeetCode 75   Sort Colors 32.5%  Medium
	void sortColors(vector<int> &nums);

	void test75();

	// LeetCode 33   Search in Rotated Sorted Array 29.0% Hard
	// LeetCode 53   Maximum Subarray 34.6% Medium
	// LeetCode 80   Remove Duplicates from Sorted Array II 30.7% Medium
	// LeetCode 81   Search in Rotated Sorted Array II 31.6% Medium
	// LeetCode 88   Merge Sorted Array 30.2% Easy
	// LeetCode 108  Convert Sorted Array to Binary Search Tree 33.9% Medium

	// LeetCode 118  Pascal's Triangle  30.1 Easy
	vector<vector<int>> generate(int numRows);

	void test118();

	// LeetCode 119  Pascal's Triangle II  29.4%  Easy
	vector<int> getRow(int rowIndex);

	void test119();

	// LeetCode 120  Triangle  27.3  Medium
	int minimumTotal(vector<vector<int>> &triangle);

	void test120();

	// LeetCode 152  Maximum Product Subarray	19.0 Medium
	// LeetCode 153  Find Minimum in Rotated Sorted Array	33.0% Medium
	// LeetCode 154  Find Minimum in Rotated Sorted Array II 31.6% Hard

	// LeetCode 163  Missing Ranges  23.5%  Medium
	std::vector<std::string> findMissingRanges(std::vector<int> range, int start, int end);

	// LeetCode 167  Two Sum II - Input array is sorted  43.6% Medium
	// LeetCode 189  Rotate Array 17.7% Easy
	void rotate(vector<int> &nums, int k);

	void test189();
	// http://en.wikipedia.org/wiki/Pascal%27s_triangle

	// LeetCode 217  Contains Duplicate  35.9%  Easy
	bool containsDuplicate(vector<int> &nums);

	void test217();

	// LeetCode 11 Container With Most Water	32.2%	Medium
	int maxArea(vector<int> &height);

	void test11();

	// LeetCode 242 Valid Anagram 36.6% Easy
	bool isAnagram(string s, string t);

	void test242();

	// 287
	int findDuplicate(vector<int> &nums);

};

#endif /* ARRAYQUIZ_HPP_ */
