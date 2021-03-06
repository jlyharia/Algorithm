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
    // 1. Two Sum
    vector<int> twoSum(vector<int> &&nums, int target);


    // 3. Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring(std::string s);

    // 4. Median of Two Sorted Arrays
    double findMedianSortedArrays(vector<int> &&nums1, vector<int> &&nums2);

    // 11. Container With Most Water
    int maxArea(vector<int> &&height);

    // 15. 3Sum
    vector<vector<int>> threeSum(vector<int> &&nums);

    // 16. 3Sum Closest
    int threeSumClosest(vector<int> &&nums, int target);

    // 18. 4Sum
    vector<vector<int>> fourSum(vector<int> &&nums, int target);

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int> &nums);

    // 27. Remove Element
    int removeElement(vector<int> &nums, int val);

    // 33. Search in Rotated Sorted Array
    int search(vector<int> &&nums, int target);

    // 34. Find First and Last Position of Element in Sorted Array
    vector<int> searchRange(vector<int> &&nums, int target);

    // 35. Search Insert Position
    int searchInsert(vector<int> &&nums, int target);

    // 41. First Missing Positive
    int firstMissingPositive(vector<int> &&nums);

    // 42. Trapping Rain Water
    int trap(vector<int> &&height);

    // 53. Maximum Subarray
    int maxSubArray(vector<int> &&nums);

    // 75. Sort Colors
    void sortColors(vector<int> &nums);

    // 121. Best Time to Buy and Sell Stock
    int maxProfit(vector<int> &&prices);

    // 238. Product of Array Except Self
    vector<int> productExceptSelf(vector<int> &&nums);

    // 973. K Closest Points to Origin
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K);


private:
    int searchRangeHelper(const vector<int> &nums, const int &target, bool isLeft);

    void kClosestSort(vector<vector<int>> &points, int low, int high, int K);

    int kClosestPartition(vector<vector<int>> &points, int low, int high);

    int dist(vector<int> point);
};

#endif /* ARRAYQUIZ_HPP_ */
