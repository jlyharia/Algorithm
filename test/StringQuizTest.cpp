//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <StringQuiz.hpp>

using namespace std;

StringQuiz sq;

TEST (StringQuiz, Longest_Palindromic_Substring) {
    cout << sq.longestPalindrome("babad");
}

TEST (StringQuiz, ZigZag_Conversion) {
    EXPECT_EQ("PAHNAPLSIIGYIR", sq.convert("PAYPALISHIRING", 3));
    //PAHNAPLSIIGYIR
    EXPECT_EQ("PINALSIGYAHRPI", sq.convert("PAYPALISHIRING", 4));
    //PINALSIGYAHRPI
    EXPECT_EQ("0a19b28c37d46e5f", sq.convert("0123456789abcdef", 6));
}

TEST (StringQuiz, Regular_Expression_Matching) {
    EXPECT_EQ(true, sq.isMatch("aab", "a*b*"));
}

TEST (StringQuiz, Roman_to_Integer) {
    EXPECT_EQ(3, sq.romanToInt("III"));

    EXPECT_EQ(4, sq.romanToInt("IV"));

    EXPECT_EQ(9, sq.romanToInt("IX"));

    EXPECT_EQ(58, sq.romanToInt("LVIII"));

    EXPECT_EQ(1994, sq.romanToInt("MCMXCIV"));
}


TEST (StringQuiz, Integer_to_Roman) {
    EXPECT_EQ("III", sq.intToRoman(3));

    EXPECT_EQ("IV", sq.intToRoman(4));

    EXPECT_EQ("IX", sq.intToRoman(9));

    EXPECT_EQ("LVIII", sq.intToRoman(58));

    EXPECT_EQ("MCMXCIV", sq.intToRoman(1994));
}

TEST (StringQuiz, Longest_Common_Prefix) {
    EXPECT_EQ("fl", sq.longestCommonPrefix({"flower", "flow", "flight"}));

    EXPECT_EQ("", sq.longestCommonPrefix({"dog", "racecar", "car"}));
}

TEST (StringQuiz, Valid_Parentheses) {
    EXPECT_EQ(true, sq.isValid("()"));
    EXPECT_EQ(true, sq.isValid("()[]{}"));
    EXPECT_EQ(false, sq.isValid("(]"));
    EXPECT_EQ(false, sq.isValid("([)]"));
    EXPECT_EQ(true, sq.isValid("{[]}"));
    EXPECT_EQ(false, sq.isValid("]"));
    EXPECT_EQ(false, sq.isValid("(])"));
}

TEST (StringQuiz, Implement_strStr) {
    EXPECT_EQ(2, sq.strStr("hello", "ll"));
    EXPECT_EQ(-1, sq.strStr("aaaaa", "bba"));
}

TEST (StringQuiz, Substring_with_Concatenation_of_All_Words) {
    vector<int> ans1 = {0, 9};
    EXPECT_EQ(ans1, sq.findSubstring("barfoothefoobarman", {"foo", "bar"}));

    vector<int> ans2 = {};
    EXPECT_EQ(ans2, sq.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}));
}

TEST (StringQuiz, Longest_Valid_Parentheses) {

    EXPECT_EQ(2, sq.longestValidParentheses("(()"));

    EXPECT_EQ(4, sq.longestValidParentheses(")()())"));
}

TEST (StringQuiz, Count_and_Say) {
    EXPECT_EQ("1", sq.countAndSay(1));
    EXPECT_EQ("11", sq.countAndSay(2));
    EXPECT_EQ("21", sq.countAndSay(3));
    EXPECT_EQ("1211", sq.countAndSay(4));
    EXPECT_EQ("111221", sq.countAndSay(5));
}

TEST (StringQuiz, Basic_Calculator) {
    cout << "Basic_Calculator\n";
    EXPECT_EQ(154, sq.calculate("(1+(41+5+24)-3 )+(6+ 80)"));
}
