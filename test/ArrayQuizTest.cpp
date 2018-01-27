//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"


TEST (ArrayTest, findDuplicate) {
	ArrayQuiz aq;
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 5, 7, 8, 9};
	EXPECT_EQ(5, aq.findDuplicate(vec));
}