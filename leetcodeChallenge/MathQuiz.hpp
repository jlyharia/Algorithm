/*
 * MathQuiz.hpp
 *
 *  Created on: Jun 24, 2015
 *      Author: johnny
 */

#ifndef MATHQUIZ_HPP_
#define MATHQUIZ_HPP_
#include "ChallengeBase.hpp"
class MathQuiz : public ChallengeBase {
  public:
    MathQuiz() {}
    ~MathQuiz() {}
    void test() override;

  private:
    // LeetCode 224	Basic Calculator	15.7%	Medium
    void test224();
    int calculate(string s);

    vector<string> to_postfix(vector<string> str);
    bool shouldPush(string curVar, string stackVar);
    vector<string> reorder(string str);
};

#endif /* MATHQUIZ_HPP_ */
