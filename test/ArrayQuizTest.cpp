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

    vector<int> ans3 = aq.twoSum({3, 3}, 6);
    print(ans3);
}


TEST (ArrayTest, Longest_Substring_Without_Repeating_Characters) {


    EXPECT_EQ(3, aq.lengthOfLongestSubstring("abcabcbb"));

    cout << aq.lengthOfLongestSubstring("bbbbb") << "\n";

    cout << aq.lengthOfLongestSubstring("au") << "\n";

    cout << aq.lengthOfLongestSubstring("pwwkew") << "\n";

    cout << aq.lengthOfLongestSubstring("cdd") << "\n";

    cout << aq.lengthOfLongestSubstring("abba") << "\n";
}