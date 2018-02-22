//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"


StringQuiz sq;

TEST (StringTest, Regular_expression_match) {
	EXPECT_TRUE(sq.isMatch("bc", ".*"));
	EXPECT_FALSE(sq.isMatch("aaa", "aa"));
	EXPECT_TRUE(sq.isMatch("aab", "c*a*b"));
	EXPECT_FALSE(sq.isMatch("abab", "ab*"));
}