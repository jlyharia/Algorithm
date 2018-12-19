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
