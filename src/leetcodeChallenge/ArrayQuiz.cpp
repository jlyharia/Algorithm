/*
 * ArrayQuiz.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include "ArrayQuiz.hpp"

void ArrayQuiz::test1() {
	cout << "LeetCode  1   Two Sum  17.6%  Medium\n";
	vector<int> numbers{0, 2, 7, 9, 11, 15};
	cout << "input = \n";
	for_each(numbers.cbegin(), numbers.cend(), [&](const int i) { cout << i << " "; });
	cout << endl;
	int target = 18;
	cout << "target = " << target << endl;
	vector<int> result = twoSum(numbers, target);
	for_each(result.cbegin(), result.cend(), [&](const int i) { cout << i << " "; });
	cout << endl;
}

/**
 * LeetCode  1   Two Sum  17.6%  Medium
 * Given an array of integers, find two numbers such that they add up to a
 * specific target number.
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target,
 * where index1 must be less than index2. Please note that your returned answers
 * (both index1 and index2)
 * are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
vector<int> ArrayQuiz::twoSum(const vector<int> &numbers, int target) {
	unordered_map<int, int> map;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		map[target - numbers.at(i)] = i;
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (map.find(numbers.at(i)) != map.end() && i != map[i]) {

			result.push_back(i + 1);
			result.push_back(map.at(numbers.at(i)) + 1);
			if (result[0] > result[1]) swap(result[0], result[1]);
			break;
		}
	}
	return result;
}

/**
 * LeetCode 163  Missing Ranges  23.5%  Medium
 * Given a sorted integer array where the range of elements are [0, 99]
 *inclusive,
 * return its missing ranges.
 * For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”,
 *“76->99”]
 *
 */
vector<string> ArrayQuiz::findMissingRanges(vector<int> range, int start, int end) {
	vector<string> missingRanges;

	int ra, rb;
	ra = start - 1;
	for (int i = 0; i <= range.size(); i++) {
		if (i == range.size()) {
			rb = end + 1;
		} else {
			rb = range[i];
		}

		if (rb - ra > 1) { missingRanges.push_back(getRange(ra + 1, rb - 1)); }
		ra = rb;
	}

	return missingRanges;
}

string ArrayQuiz::getRange(int start, int end) {
	if (end == start) {
		return std::to_string(start);
	} else {
		string str = std::to_string(start) + "->" + std::to_string(end);
		return str;
	}
}

/**
 * LeetCode 26  Remove Duplicates from Sorted Array 31.5% Easy
 * Given a sorted array, remove the duplicates in place such that each element
 *appear only once
 * and return the new length.
 * Do not allocate extra space for another array, you must do this in place with
 *constant memory.
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 */
int ArrayQuiz::removeDuplicates(std::vector<int> &A) {
	int n = A.size();
	if (n == 0) return 0;
	int index = 0;
	for (int i = 0; i < n; i++) {

		if (A[index] == A[i]) { continue; }
		index++;
		A[index] = A[i];
		for_each(A.cbegin(), A.cend(), [&](int i) { cout << i << ", "; });
		cout << endl;
	}
	// remove element from index+1 to end
	A.erase(A.begin() + index + 1, A.end());
	return index + 1;
	//	return length;
}

/**
 * LeetCode 118  Pascal's Triangle  30.1 Easy
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 *	[
 *		 [1],
 *		[1,1],
 *	   [1,2,1],
 *	  [1,3,3,1],
 *	 [1,4,6,4,1]
 *	]
 */
vector<vector<int>> ArrayQuiz::generate(int numRows) {
	vector<vector<int>> pas;

	if (numRows == 0) return pas;

	vector<int> ini(1, 1);
	pas.push_back(ini);
	if (numRows == 1) return pas;

	for (auto i = 1; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (auto j = 1; j < row.size() - 1; j++) {
			row[j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
		pas.push_back(row);
	}
	return pas;
}

void ArrayQuiz::test118() {
	cout << "LeetCode 118  Pascal's Triangle  30.1 Easy" << endl;
	cout << "Pascal's Triangle level 6" << endl;
	auto Pascal = generate(6);

	for (auto &row : Pascal) {
		for (auto &val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
}

/**
 * LeetCode 119 Pascal's Triangle II 29.4% Easy
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */
vector<int> ArrayQuiz::getRow(int rowIndex) {
	vector<int> row(rowIndex + 1, 1);

	for (auto i = 1; i < rowIndex + 1; i++) {
		for (auto j = i - 1; j > 0; j--) {
			row[j] = row[j] + row[j - 1];
		}
	}
	return row;
}

void ArrayQuiz::test119() {
	cout << "LeetCode 119 Pascal's Triangle II 29.4% Easy" << endl;

	cout << "Pascal's Triangle II level 5" << endl;
	auto row = getRow(5);
	for_each(row.cbegin(), row.cend(), [&](int i) { cout << i << " "; });
}

/**
 * LeetCode 120  Triangle  27.3  Medium
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 *	For example, given the following triangle
 *	[
 *		 [2],
 *		[3,4],
 *	   [6,5,7],
 *	  [4,1,8,3]
 *	]
 *	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 =
 *11).
 *
 *	Note:
 *	Bonus point if you are able to do this using only O(n) extra space,
 *	where n is the total number of rows in the triangle.
 */
int ArrayQuiz::minimumTotal(vector<vector<int>> &triangle) {

	if (triangle.size() == 1) return triangle[0][0];
	vector<int> sumArray(triangle.size(), 0);
	sumArray[0] = triangle[0][0];
	for (auto i = 1; i < triangle.size(); i++) {
		for (auto j = i; j >= 0; j--) {
			if (j == 0) {
				sumArray[j] = triangle[i][j] + sumArray[j];
			} else if (j == i) {
				sumArray[j] = triangle[i][j] + sumArray[j - 1];
			} else {
				sumArray[j] = std::min(sumArray[j - 1], sumArray[j]) + triangle[i][j];
			}
		}
	}

	// go through sum array to find minimum
	// because triangle may arbitrary large, it is inefficient to compare each
	// time at
	// above loop
	int min = sumArray[0];
	for (auto &i : sumArray) {
		if (min > i) { min = i; }
	}

	return min;
}

void ArrayQuiz::test120() {
	cout << "LeetCode 120  Triangle  27.3  Medium" << endl;
	vector<vector<int>> triangle{{2},
								 {3, 4},
								 {6, 5, 7},
								 {4, 1, 8, 3}};
	for_each(triangle.cbegin(), triangle.cend(), [&](vector<int> row) {
		for_each(row.cbegin(), row.cend(), [&](int i) { cout << i << " "; });
		cout << endl;
	});
	cout << "Triangle sum = " << minimumTotal(triangle) << endl;
}

/**
 * LeetCode 15   3Sum  16.9%  Medium
 * Given an array S of n integers, are there elements a, b, c in S such that a +
 *b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≦ b ≦
 *c)
 * The solution set must not contain duplicate triplets.
 *  For example, given array S = {-1 0 1 2 -1 -4},
 *
 *  A solution set is:
 *  (-1, 0, 1)
 *  (-1, -1, 2)
 */
vector<vector<int>> ArrayQuiz::threeSum(vector<int> &nums) {
	vector<vector<int>> result;
	std::sort(nums.begin(), nums.end());

	for (auto i = 0; i < nums.size(); ++i) {
		auto p = nums[i];
		// skip duplicate
		if (p == nums[i - 1] && i != 0) {
			cout << i << endl;
			continue;
		}
		auto s = i + 1;
		auto t = nums.size() - 1;
		while (s < t) {
			auto sum = p + nums[s] + nums[t];
			if (sum > 0) {
				t--;
			} else if (sum < 0) {
				s++;
			} else {
				vector<int> vec = {p, nums[s], nums[t]};
				result.push_back(vec);
				t--;
				s++;
				// skip duplicate
				while (nums[t] == nums[t + 1] && s < t) {
					t--;
				}
				// skip duplicate
				while (nums[s] == nums[s - 1] && s < t) {
					s++;
				}
			}
		}
	}

	return result;
}

void ArrayQuiz::test15() {
	cout << "LeetCode 15   3Sum  16.9%  Medium" << endl;
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	for_each(nums.begin(), nums.end(), [&](int u) { cout << u << " "; });
	cout << endl;
	auto result = threeSum(nums);

	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << result.size() << endl;
}

/**
 * TODO LeetCode 16  3Sum Closest  26.9%   Medium
 */
int ArrayQuiz::threeSumClosest(vector<int> &nums, int target) { return 0; }

void ArrayQuiz::test16() { cout << "LeetCode 16  3Sum Closest  26.9%   Medium" << endl; }

/**
 * LeetCode 217  Contains Duplicate  35.9%  Easy
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the
 * array,
 * and it should return false if every element is distinct.
 */
bool ArrayQuiz::containsDuplicate(vector<int> &nums) { return true; }

void ArrayQuiz::test217() {
	cout << "LeetCode 217  Contains Duplicate  35.9%  Easy" << endl;
	vector<int> nums = {1, 1, 1, 1, 3, 3, 3, 5, 6};
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
}

/**
LeetCode 75   Sort Colors 32.5%  Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same
color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total
number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
http://fisherlei.blogspot.com/2013/01/leetcode-sort-colors.html
*/
void ArrayQuiz::sortColors(vector<int> &nums) {
	int i = 0;
	int k = 0;
	int j = nums.size() - 1;
	while (k <= j) {
		if (nums[k] == 0) {
			swap(nums[k], nums[i]);
			i++;
			k++;
			continue;
		}
		if (nums[k] == 2) {
			swap(nums[k], nums[j]);
			j--;
			continue;
		}
		k++;
	}
}

void ArrayQuiz::test75() {
	cout << "LeetCode 75   Sort Colors 32.5%  Medium" << endl;
	// vector<int> nums = {2, 1, 0, 1, 2, 0, 2, 2, 0};
	vector<int> nums = {2};
	sortColors(nums);
	for (auto &i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

/**
LeetCode 11 Container With Most Water	32.2%	Medium
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two
lines, which together with x-axis forms a container, such that the container contains the most
water.

Note: You may not slant the container.

*/
int ArrayQuiz::maxArea(vector<int> &height) {
	int begin = 0;
	int end = height.size() - 1;
	int maxV = 0;
	while (begin < end) {
		int contains = min(height[end], height[begin]) * (end - begin);
		cout << contains << " " << maxV << endl;
		maxV = max(maxV, contains);
		if (height[begin] < height[end]) {
			begin++;
		} else {
			end--;
		}
	}
	return maxV;
}

void ArrayQuiz::test11() {
	cout << "LeetCode 11 Container With Most Water	32.2% Medium" << endl;
	vector<int> height = {1, 2, 3, 1, 2, 4, 2, 3};
	// vector<int> height = {2,1,2};

	cout << maxArea(height) << endl;;
}

/**
LeetCode 242 Valid Anagram 36.6% Easy
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

http://www.cnblogs.com/jcliBlogger/p/4694047.html
*/
bool ArrayQuiz::isAnagram(string s, string t) {
	if (s.length() != t.length()) return false;
	if (s.empty() && t.empty()) return true;
	std::array<int, 26> dict;
	for (int i = 0; i < s.length(); i++) {
		dict.at(s[i] - 'a')++;
		dict.at(t[i] - 'a')--;
	}
	for (auto d : dict) {
		if (d != 0) return false;
	}
	return true;
}

void ArrayQuiz::test242() {
	cout << "LeetCode 242 Valid Anagram 36.6% Easy" << endl;
	auto s("a");
	auto t("a");
	cout << isAnagram(s, t) << endl;
}

// LeetCode 189  Rotate Array 17.7% Easy
void ArrayQuiz::rotate(vector<int> &nums, int k) {

	std::reverse(nums.begin(), nums.begin() + k + 1);
	std::reverse(nums.begin() + k + 1, nums.end());
	std::reverse(nums.begin(), nums.end());
}

void ArrayQuiz::test189() {
	cout << "LeetCode 189  Rotate Array 17.7% Easy" << endl;
	vector<int> nums = {1, 2, 3, 4, 5, 6};

	rotate(nums, 6);
	for_each(nums.cbegin(), nums.cend(), [](int i) { cout << i << " "; });
	cout << endl;
	// [5,6,7,1,2,3,4]
}

int ArrayQuiz::findDuplicate(vector<int> &nums) {

	int tortoise = nums[0];
	int hare = nums[0];
	do {
		tortoise = nums[tortoise];
		hare = nums[nums[hare]];
	} while (tortoise != hare);

	// Find the "entrance" to the cycle.
	int ptr1 = nums[0];
	int ptr2 = tortoise;
	while (ptr1 != ptr2) {
		ptr1 = nums[ptr1];
		ptr2 = nums[ptr2];
	}

	return ptr1;
}

void ArrayQuiz::test() {
	// cout << "LeetCode 163  Missing Ranges  23.5%  Medium" << endl;
	// vector<int> range{-2, -1, 0, 10, 30};
	// auto missingRange = findMissingRanges(range, -10, 100);
	// for_each(missingRange.cbegin(), missingRange.cend(), [&](string i) { cout << i << ", "; });
	// cout << endl;

	// vector<int> range2{-20, -1, 0, 10, 110};
	// auto missingRange2 = findMissingRanges(range2, -10, 100);
	// for_each(missingRange2.cbegin(), missingRange2.cend(), [&](string i) { cout << i << ", "; });

	// cout << endl << endl;
	// cout << "LeetCode 26   Remove Duplicates from Sorted Array 31.5% Easy" << endl;
	// vector<int> array{1, 1, 1, 2, 2, 4, 4, 4, 5};
	// cout << removeDuplicates(array) << endl;
	// for_each(array.cbegin(), array.cend(), [&](int i) { cout << i << ", "; });
	// cout << endl;

	// LeetCode  1   Two Sum  17.6%  Medium
	// test1();
	// LeetCode 4    Median of Two Sorted Arrays 17.8% Hard
	// LeetCode 15   3Sum  16.9%  Medium
	// test15();
	// LeetCode 33   Search in Rotated Sorted Array 29.0% Hard
	// LeetCode 53   Maximum Subarray 34.6% Medium
	// LeetCode 80   Remove Duplicates from Sorted Array II 30.7% Medium
	// LeetCode 81   Search in Rotated Sorted Array II 31.6% Medium
	// LeetCode 88   Merge Sorted Array 30.2% Easy
	// LeetCode 108  Convert Sorted Array to Binary Search Tree 33.9% Medium
	// LeetCode 118  Pascal's Triangle  30.1 Easy
	// test118();
	// LeetCode 119 Pascal's Triangle II 29.4% Easy
	// test119();
	// LeetCode 120  Triangle  27.3  Medium
	// test120();
	// LeetCode 152  Maximum Product Subarray	19.0 Medium
	// LeetCode 153  Find Minimum in Rotated Sorted Array	33.0% Medium
	// LeetCode 154  Find Minimum in Rotated Sorted Array II 31.6% Hard
	// LeetCode 167  Two Sum II - Input array is sorted  43.6% Medium
	// LeetCode 189  Rotate Array 17.7% Easy
	// LeetCode 16  3Sum Closest  26.9%   Medium
	// test16();
	// test217();
	// test75();
	// test11();
	// test242();
	test189();
}
