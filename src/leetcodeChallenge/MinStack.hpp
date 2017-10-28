/*
 * MinStack.hpp
 *
 *  Created on: Sep 7, 2015
 *      Author: johnny
 */

#ifndef MINSTACK_HPP_
#define MINSTACK_HPP_

#include "ChallengeBase.hpp"
class MinStack : public ChallengeBase {
  public:
    stack<int> origin;
    stack<int> minStack;
    void push(int x) {
        origin.emplace(x);
        if (minStack.empty() || minStack.top() >= x) {
            minStack.emplace(x);
            cout << x << " in MinStack" << endl;
        }
    }

    void pop() {
        auto top = this->origin.top();
        if (minStack.top() == top) { minStack.pop(); }
        origin.pop();
    }

    int top() { return origin.top(); }

    int getMin() { return minStack.top(); }
    void test() override {
        cout << "LeetCode 155  Min Stack  19.7%  Easy" << endl;
        std::vector<int> vec = {3, 4, 1, 6, 10, 3, 9};

        for (auto &i : vec) {
            this->push(i);
        }
        // cout<<this->top()<<endl;
        // this->pop();
        // cout<<this->getMin()<<endl;
        // cout<<this->top()<<endl;
        // cout<<top();
    };
};

#endif /* MINSTACK_HPP_ */