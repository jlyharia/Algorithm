/*
 * Numbers.hpp
 *
 *  Created on: May 5, 2015
 *      Author: johnny
 */

#ifndef NUMBERS_HPP_
#define NUMBERS_HPP_
#include "ChallengeBase.hpp"
class Numbers : public ChallengeBase {
  public:
    Numbers() {}

    void test() override;
    ~Numbers() {}

  private:
    // LeetCode 7   Reverse Integer  26.4%   Easy
    int reverse(int x);
    void test7();

    // LeetCode 8  String to Integer (atoi)  13.2%  Easy
    void test8();
    int myAtoi(string str);
    bool IsOdd(string i);

    // LeetCode 9 PalindromNumber 29.5% Easy
    bool isPalindrom(int n);
    void test9();

    // LeetCode 12  Integer to Roman  34.8%  Medium
    // LeetCode 13  Roman to Integer  35.1%  Easy
    // LeetCode 29  Divide Two Integers  15.2%  Medium
};

#endif /* NUMBERS_HPP_ */
