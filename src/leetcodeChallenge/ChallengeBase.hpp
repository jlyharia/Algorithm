/*
 * ChallengeBase.hpp
 *
 *  Created on: May 6, 2015
 *      Author: johnny
 */

#ifndef CHALLENGEBASE_HPP_
#define CHALLENGEBASE_HPP_

#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class ChallengeBase {
public:
	ChallengeBase() {}

	virtual void test() = 0;

	virtual ~ChallengeBase() {}
};

#endif /* CHALLENGEBASE_HPP_ */
