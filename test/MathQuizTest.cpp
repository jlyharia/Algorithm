//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <MathQuiz.hpp>

using namespace std;

MathQuiz mt;

TEST (MathQuiz, Reverse_Integer) {
    EXPECT_EQ(-321, mt.reverse(-123));
}


TEST(MathQuiz, String_to_Integer_atoi) {

}