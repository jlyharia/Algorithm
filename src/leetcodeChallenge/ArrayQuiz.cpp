/*
 * ArrayQuiz.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include <Utils.hpp>
#include "ArrayQuiz.hpp"
#include <stack>

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

/**
 *
 * https://www.cnblogs.com/grandyang/p/4465932.html
 * https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
 * https://www.youtube.com/watch?v=LPFhl65R7ww
 */
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

int ArrayQuiz::removeElement(vector<int> &nums, int val) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}

/**
 * http://www.cnblogs.com/grandyang/p/4325648.html
 */
int ArrayQuiz::search(vector<int> &&nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < nums[right]) {
            if (nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
        } else {
            if (nums[left] <= target && nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
    }
    return -1;
}


vector<int> ArrayQuiz::searchRange(vector<int> &&nums, int target) {
    vector<int> ans = {-1, -1};
    int leftEdge = searchRangeHelper(nums, target, true);
    if (leftEdge == nums.size() || nums[leftEdge] != target) {
        return ans;
    }

    ans[0] = leftEdge;
    ans[1] = searchRangeHelper(nums, target, false) - 1;

    return ans;
}

int ArrayQuiz::searchRangeHelper(const vector<int> &nums, const int &target, bool isLeft) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (isLeft && nums[mid] == target)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

/**
 *
 * http://bangbingsyb.blogspot.com/2014/11/leetcode-search-insert-position.html
 */
int ArrayQuiz::searchInsert(vector<int> &&nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

/**
 *
 * http://www.cnblogs.com/grandyang/p/4341243.html
 */
void ArrayQuiz::sortColors(vector<int> &nums) {
    int L = 0; // 0's location
    int R = nums.size() - 1; // 2's location
    for (int i = 0; i <= R; i++) {
        if (nums[i] == 0) {
            // swap 0 to L
            std::swap(nums[i], nums[L++]);
        } else if (nums[i] == 2) {
            std::swap(nums[i--], nums[R--]);
        }
    }
}

int ArrayQuiz::firstMissingPositive(vector<int> &&nums) {

}

vector<int> ArrayQuiz::productExceptSelf(vector<int> &&nums) {
    vector<int> res(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int ac = 1;
    for (int j = nums.size() - 1; j >= 0; j--) {
        res[j] *= ac;
        ac *= nums[j];
    }
    return res;
}

int ArrayQuiz::maxProfit(vector<int> &&prices) {
    int res = 0, buy = INT_MAX;
    for (int price : prices) {
        buy = min(buy, price);
        res = max(res, price - buy);
    }
    return res;
}

int ArrayQuiz::maxSubArray(vector<int> &&nums) {
    int res = INT_MIN, curSum = 0;
    for (int num : nums) {
        curSum = max(curSum + num, num);
        res = max(res, curSum);
    }
    return res;
}

//vector<vector<int>> ArrayQuiz::kClosest(vector<vector<int>> &points, int K) {
//    kClosestSort(points, 0, points.size(), K);
//}

//void ArrayQuiz::kClosestSort(vector<vector<int>> &points, int low, int high, int K) {
//    int pivot = kClosestPartition(points, low, high);
//    int leftLength = pivot - low + 1;
//    if (K > leftLength) {
//        kClosestSort(points, pivot + 1, high, K - leftLength);
//    } else if (K < leftLength) {
//        kClosestSort(points, low, pivot, K);
//    }
//}

//int ArrayQuiz::kClosestPartition(vector<vector<int>> &points, int low, int high) {
//    int i = low;
//    for (int j = low + 1; j < high; j++) {
//        if (vec.at(low) > vec.at(j)) {
//            std::swap(vec.at(j), vec.at(++i));
//        }
//    }
//    std::swap(vec.at(low), vec.at(i));
//    return i;
//}
//
//int ArrayQuiz::dist(vector<int> point) {
//    return point[0] * point[0] + point[1] * point[1];
//}


int ArrayQuiz::trap(vector<int> &&height) {
    stack<int> st;
    int i = 0, res = 0, n = height.size();
    while (i < n) {
        if (st.empty() || height[i] <= height[st.top()]) {
            st.push(i++);
        } else {
            int t = st.top();
            st.pop();
            if (st.empty()) continue;
            res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
        }
    }
    return res;
}