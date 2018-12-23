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
void print(std::vector<T> &&vec) {
    for (auto &&i:vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}

template<class T>
void print(std::vector<std::vector<T>> &&vec) {
    for (auto &&i:vec) {
        for (auto &&j:i) {
            std::cout << j << '\t';
        }
        std::cout << '\n';
    }
}

void printListNode(ListNode *ln);


void printLevel(int lv);
#endif //ALGORITHM_UTILS_HPP
