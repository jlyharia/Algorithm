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
    EXPECT_EQ(-42, mt.myAtoi("   -42"));
    EXPECT_EQ(INT_MIN, mt.myAtoi("   -41235124523453462"));
    EXPECT_EQ(0, mt.myAtoi(" kk  -41235124523453462"));
}


TEST(MathQuiz, Palindrome_Number) {
//    cout << mt.isPalindrome(121) << '\n';
//
//    cout << mt.isPalindrome(123) << '\n';
//
//    cout << mt.isPalindrome(-121) << '\n';
//
//    cout << mt.isPalindrome(99) << '\n';
//    cout << mt.isPalindrome(0) << '\n';

    cout << mt.isPalindrome(1001) << '\n';


//    cout << mt.isPalindrome(-121) << '\n';
}
