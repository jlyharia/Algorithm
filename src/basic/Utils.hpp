//
// Created by Yihung Lee on 2018-12-01.
//

#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template<class T>
inline void print(std::vector<T> &vec) {
    for (auto &&i:vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}

inline void print(ListNode *ln) {
    while (ln != nullptr) {
        std::cout << ln->val << '\t';
        ln = ln->next;
    }
    std::cout << '\n';
}


#endif //ALGORITHM_UTILS_HPP
