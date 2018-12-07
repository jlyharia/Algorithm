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
    cout << sq.convert("PAYPALISHIRING", 3);
    //PAHNAPLSIIGYIR
//    cout << sq.convert("PAYPALISHIRING", 4);
    //PINALSIGYAHRPI

//    cout << sq.convert("0123456789abcdef", 6);
}