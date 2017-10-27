/*
 * Numbers.cpp
 *
 *  Created on: May 5, 2015
 *      Author: johnny
 */

#include "Numbers.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
/**
 *	9 Palindrome Number
 */
bool Numbers::isPalindrom(int n) {
    if (n < 0) return false;
    int d = 1;
    while (n / d >= 10) {
        d = d * 10;
    }
    while (d > 1) {
        int h = n / d;
        int t = n % 10;
        if (h != t) {
            return false;
        } else {
            n = (n % d) / 10;
            d = d * 0.01;
        }
    }
    return true;
}

void Numbers::test9() {
    cout << "LeetCode 9 PalindromNumber 29.5% Easy" << endl;
    cout << -2147483648 << " is " << this->isPalindrom(-2147483648) << endl;
    cout << 0 << " is " << this->isPalindrom(0) << endl;
    cout << 10 << " is " << this->isPalindrom(10) << endl;
    cout << 334 << " is " << this->isPalindrom(334) << endl;
    cout << 33533 << " is " << this->isPalindrom(33533) << endl;
}
/**
 *LeetCode 7   Reverse Integer  26.4%   Easy
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
int Numbers::reverse(int x) {

    long p = (long)x;
    long t = 0;
    // sign
    int s = (p > 0 ? 1 : -1);
    p *= s;
    while (p > 0) {

        long r = p % 10;
        t = t * 10 + r;
        p /= 10;
    }
    if (t > INT_MAX) t = 0;
    t *= s;
    return (int)t;
}

void Numbers::test7() {
    cout << "LeetCode 7   Reverse Integer  26.4%   Easy" << endl;
    cout << "reverse 1234567 = " << reverse(1234567) << endl;
    cout << "reverse -345 = " << reverse(-345) << endl;
    cout << "reverse 0 = " << reverse(0) << endl;
    cout << "reverse 1534236469 = " << reverse(1534236469) << endl;
    //	assert(p<10 && __FILE__&& __LINE__);
}

bool Numbers::IsOdd(string i) { return i == " "; }
/**
 * LeetCode 8  String to Integer (atoi)  13.2%  Easy
 * Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 *input specs).
 * You are responsible to gather all the input requirements up front.
 *
 */
int Numbers::myAtoi(string str) {
    if (str.length() == 0) return 0;
    long t = 0;
    // sign
    int s = 1;
    int i = 0;
    for (; i < str.length() && str[i] == ' '; i++) {
    }
    if (str[i] == '-') {
        s = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    for (; i < str.length(); i++) {
        int num = str[i] - '0';
        if (num > 9 || num < 0) {
            // invalid input
            break;
        }
        t = t * 10 + num;
        if (t * s >= INT_MAX) {
            return INT_MAX;
        } else if (t * s < INT_MIN) {
            return INT_MIN;
        }
    }

    return (int)t * s;
}
void Numbers::test8() {
    cout << "LeetCode 8  String to Integer (atoi)  13.2%  Easy" << endl;
    string s = "   +004500";
    cout << "input " << s << " = " << myAtoi(s) << endl;
    s = "  -0012a42";
    cout << "input " << s << " = " << myAtoi(s) << endl;
    s = "   +0 123";
    cout << "input " << s << " = " << myAtoi(s) << endl;
    s = "9223372036854775809";
    cout << "input " << s << " = " << myAtoi(s) << endl;
}
void Numbers::test() {
    test9();
    test7();
    test8();
}
