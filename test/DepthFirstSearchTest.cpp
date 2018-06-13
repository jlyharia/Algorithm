//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;

DepthFirstSearch dfs;

TEST (DepthFirstSearch, decodeString) {
    /**
     * s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
     */
    cout << "\n";
    auto ans1 = dfs.decodeString("3[a]2[bc]");
    cout << ans1 << endl;
    EXPECT_EQ("aaabcbc", ans1);

    auto ans2 = dfs.decodeString("3[a2[c]]");
    cout << ans2 << endl;
    EXPECT_EQ("accaccacc", ans2);
//
//    auto ans3 = dfs.decodeString("2[abc]3[cd]ef");
//    cout << ans3 << endl;
//    EXPECT_EQ("abcabccdcdcdef", ans3);

}