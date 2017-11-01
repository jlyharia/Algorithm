//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"

int isEven() {
	return 2;
}

TEST (SquareRootTest, PositiveNos) {
	EXPECT_EQ (3, isEven());
}