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

double ArrayQuiz::findMedianSortedArrays(vector<int> &&nums1, vector<int> &&nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) { // to ensure m<=n
        std::swap(nums1, nums2);
        std::swap(m, n);
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < iMax && nums2[j - 1] > nums1[i]) {
            iMin = i + 1; // i is too small
        } else if (i > iMin && nums1[i - 1] > nums2[j]) {
            iMax = i - 1; // i is too big
        } else { // i is perfect
            int maxLeft = 0;
            if (i == 0) { maxLeft = nums2[j - 1]; }
            else if (j == 0) { maxLeft = nums1[i - 1]; }
            else { maxLeft = std::max(nums1[i - 1], nums2[j - 1]); }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }

            int minRight = 0;
            if (i == m) { minRight = nums2[j]; }
            else if (j == n) { minRight = nums1[i]; }
            else {
                minRight = std::min(nums2[j], nums1[i]);
            }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}

/**
 * Prove
 * https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
 */
int ArrayQuiz::maxArea(vector<int> &&height) {
    int max_area = 0;
    int L = 0, R = height.size() - 1;
    while (R > L) {
        max_area = std::max(max_area, std::min(height[L], height[R]) * (R - L));
        height[L] < height[R] ? L++ : R--;
    }
    return max_area;
}

vector<vector<int>> ArrayQuiz::threeSum(vector<int> &&nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // for empty or small input
    if (nums.size() < 3) return ans;
    // fix left
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                // remove duplicate
                while (nums[j] == nums[j - 1] && j < k) j++;
                while (nums[k] == nums[k + 1] && j < k) k--;
            }
        }
    }
    return ans;
}

/**
 * Return the sum of the three integers.
 */
int ArrayQuiz::threeSumClosest(vector<int> &&nums, int target) {
    if (nums.size() < 3) return INT_MAX;
    std::sort(nums.begin(), nums.end());
    // for empty or small input
    // fix left
    int min = INT_MAX;
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            const int diff = nums[i] + nums[j] + nums[k] - target;
            if (abs(diff) < abs(min)) min = diff;
            if (diff == 0) {
                break;
            } else if (diff < 0) {
                j++;
            } else {
                k--;
            }

        }
    }
    return target + min;
}

/**
 * http://www.cnblogs.com/grandyang/p/4515925.html
 *
 * k-sum
 * http://bangbingsyb.blogspot.com/2014/11/leetcode-4sum.html
 */
vector<vector<int>> ArrayQuiz::fourSum(vector<int> &&nums, int target) {
    vector<vector<int>> ans;
    if (nums.size() < 4) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int third = j + 1, fourth = nums.size() - 1;
            while (third < fourth) {
                int sum = nums[i] + nums[j] + nums[third] + nums[fourth];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[third], nums[fourth]});
                    third++;
                    fourth--;
                    while (third < fourth && nums[third] == nums[third - 1]) third++;
                    while (third < fourth && nums[fourth] == nums[fourth + 1]) fourth--;
                } else if (sum < target) {
                    third++;
                } else {
                    fourth--;
                }
            }
        }
    }
    return ans;
}

int ArrayQuiz::removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

























