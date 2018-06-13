//
// Created by Yihung Lee on 6/12/18.
//

#ifndef ALGORITHM_DEPTHFIRSTSEARCH_HPP
#define ALGORITHM_DEPTHFIRSTSEARCH_HPP


#include "ChallengeBase.hpp"

class DepthFirstSearch : public ChallengeBase {
public:
//    394. Decode String
    string decodeString(string s);

    void test() override { cout << "haha"; }

    ~DepthFirstSearch() {}

private:
    void decodeStringHelper(string s, unsigned int idx, string &ans);
};


#endif //ALGORITHM_DEPTHFIRSTSEARCH_HPP
