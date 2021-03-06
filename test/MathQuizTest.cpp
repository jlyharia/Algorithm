//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <MathQuiz.hpp>
#include <Utils.hpp>

using namespace std;

MathQuiz mt;

TEST (MathQuiz, Reverse_Integer) {
    EXPECT_EQ(-321, mt.reverse(-123));
}


TEST(MathQuiz, String_to_Integer_atoi) {
    EXPECT_EQ(-42, mt.myAtoi("   -42"));
    EXPECT_EQ(INT_MIN, mt.myAtoi("   -41235124523453462"));
    EXPECT_EQ(0, mt.myAtoi(" kk  -41235124523453462"));
}


TEST(MathQuiz, Palindrome_Number) {
    EXPECT_TRUE(mt.isPalindrome(121));

    EXPECT_FALSE(mt.isPalindrome(123));

    EXPECT_FALSE(mt.isPalindrome(-121));

    EXPECT_TRUE(mt.isPalindrome(99));
    EXPECT_TRUE(mt.isPalindrome(0));

    EXPECT_TRUE(mt.isPalindrome(1001));


    EXPECT_FALSE(mt.isPalindrome(-121));
}


TEST(MathQuiz, Divide_Two_Integers) {
    EXPECT_EQ(6, mt.divide(20, 3));
}

TEST(MathQuiz, Pow_x_n) {
    EXPECT_EQ(1024.00000, (mt.myPow(2.00000, 10)));
}

TEST(MathQuiz, Sort_by_array) {
    // https://leetcode.com/discuss/interview-question/309656/google-phone-screen
    vector<int> A{24, 56, 74, -23, 87, 91};
    vector<int> B{2, 3, 4, 1, 5, 6};
    int i = 0;
    while (i < A.size()) {
        int pos = B[i] - 1;
        if (pos != i) { // not the right position
            std::swap(A[i], A[pos]);
            std::swap(B[i], B[pos]);
        } else // otherwise, skip
            i++;
    }
    vector<int> expect{1, 2, 3, 4, 5, 6};
    EXPECT_EQ(expect, B);
}