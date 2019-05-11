//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <ArrayQuiz.hpp>
#include "Utils.hpp"

using namespace std;

ArrayQuiz aq;

TEST (ArrayTest, two_sum) {

//    vector<int> ans1 = aq.twoSum({2, 7, 11, 15}, 9);
//    print(ans1);
//
//    vector<int> ans2 = aq.twoSum({3, 2, 4}, 6);
//    print(ans2);

    print(aq.twoSum({3, 3}, 6));
}


TEST (ArrayTest, Longest_Substring_Without_Repeating_Characters) {
    EXPECT_EQ(3, aq.lengthOfLongestSubstring("abcabcbb"));

    EXPECT_EQ(1, aq.lengthOfLongestSubstring("bbbbb"));

    EXPECT_EQ(2, aq.lengthOfLongestSubstring("au"));

    EXPECT_EQ(3, aq.lengthOfLongestSubstring("pwwkew"));

    EXPECT_EQ(2, aq.lengthOfLongestSubstring("cdd"));

    EXPECT_EQ(2, aq.lengthOfLongestSubstring("abba"));
}

TEST (ArrayTest, Median_of_Two_Sorted_Arrays) {
    std::cout << aq.findMedianSortedArrays({1, 3}, {2}) << '\n';

    std::cout << aq.findMedianSortedArrays({1, 2}, {3, 4}) << '\n';
}

TEST (ArrayTest, Container_With_Most_Water) {

    EXPECT_EQ(49, aq.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}));

    EXPECT_EQ(32, aq.maxArea({1, 8, 8, 8, 8, 8, 2, 2, 2}));
}

TEST (ArrayTest, _3_Sum) {
    print(aq.threeSum({-1, 0, 1, 2, -1, -4}));

    print(aq.threeSum({-2, 0, 1, 1, 2}));

    print(aq.threeSum({0, 0, 0, 0}));

    print(aq.threeSum({-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}));
}

TEST (ArrayTest, _3_Sum_Closest) {
    EXPECT_EQ(2, aq.threeSumClosest({-1, 2, 1, -4}, 1));
}

TEST (ArrayTest, _4_Sum) {
    {
        vector<vector<int>> ans{
                {-2, -1, 1, 2},
                {-2, 0,  0, 2},
                {-1, 0,  0, 1}
        };
        EXPECT_EQ(ans, (aq.fourSum({1, 0, -1, 0, -2, 2}, 0)));
    }

    {
        vector<vector<int>> ans{
                {0, 0, 0, 0},
        };
        EXPECT_EQ(ans, (aq.fourSum({0, 0, 0, 0}, 0)));
    }

}

TEST (ArrayTest, Remove_Duplicates_from_Sorted_Array) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ln = aq.removeDuplicates(nums);
    EXPECT_EQ(5, ln);
    vector<int> exp = {0, 1, 2, 3, 4, 2, 2, 3, 3, 4};
    EXPECT_EQ(exp, nums);
}

TEST (ArrayTest, Remove_Element) {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int ln = aq.removeElement(nums, 2);
    EXPECT_EQ(5, ln);
    vector<int> exp = {0, 1, 4, 0, 3, 0, 4, 2};
    EXPECT_EQ(exp, nums);
}

TEST (ArrayTest, Search_in_Rotated_Sorted_Array) {
    EXPECT_EQ(4, aq.search({4, 5, 6, 7, 0, 1, 2}, 0));

    EXPECT_EQ(-1, aq.search({4, 5, 6, 7, 0, 1, 2}, 3));
}

TEST (ArrayTest, Find_First_and_Last_Position_of_Element_in_Sorted_Array) {
    vector<int> ans1 = {3, 4};
    EXPECT_EQ(ans1, aq.searchRange({5, 7, 7, 8, 8, 10}, 8));

    vector<int> ans2 = {-1, -1};
    EXPECT_EQ(ans2, aq.searchRange({5, 7, 7, 8, 8, 10}, 6));
}

TEST (ArrayTest, Search_Insert_Position) {
    EXPECT_EQ(2, aq.searchInsert({1, 3, 5, 6}, 5));
    EXPECT_EQ(1, aq.searchInsert({1, 3, 5, 6}, 2));
    EXPECT_EQ(4, aq.searchInsert({1, 3, 5, 6}, 7));
    EXPECT_EQ(0, aq.searchInsert({1, 3, 5, 6}, 0));
}

TEST (ArrayTest, Sort_Colors) {
    {
        vector<int> nums = {2, 0, 2, 1, 1, 0};
        vector<int> ans = {0, 0, 1, 1, 2, 2};
        aq.sortColors(nums);
        EXPECT_EQ(ans, nums);
    }

    {
        vector<int> nums = {2, 0, 1};
        vector<int> ans = {0, 1, 2};
        aq.sortColors(nums);
        EXPECT_EQ(ans, nums);
    }
}

TEST (ArrayTest, First_Missing_Positive) {
    EXPECT_EQ(3, aq.firstMissingPositive({1, 2, 0}));

    EXPECT_EQ(2, aq.firstMissingPositive({3, 4, -1, 1}));

    EXPECT_EQ(1, aq.firstMissingPositive({7, 8, 9, 11, 12}));
}

TEST (ArrayTest, Product_of_Array_Except_Self) {

    vector<int> ans = {24,
                       12,
                       8,
                       6};
    EXPECT_EQ(ans, aq.productExceptSelf({1, 2, 3, 4}));
}
