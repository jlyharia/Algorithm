//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

ArrayQuiz aq;

TEST (ArrayTest, findDuplicate) {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 5, 7, 8, 9};
    EXPECT_EQ(5, aq.findDuplicate(vec));
}

TEST (ArrayTest, lengthOfLongestSubstring) {
    cout << "\nLongest Substring Without Repeating Characters\n";
    string s1 = "abcabcbb";
    cout << aq.lengthOfLongestSubstring(s1) << endl;
//    string s2 = "bbbbb";
//    cout << aq.lengthOfLongestSubstring(s2) << endl;
//    string s3 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~";
//    cout << aq.lengthOfLongestSubstring(s3) << endl;
}