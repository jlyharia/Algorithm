//
// Created by Yihung Lee on 2018-12-02.
//


#include "Utils.hpp"

void printListNode(ListNode *ln) {
    while (ln != nullptr) {
        std::cout << ln->val << " -> ";
        ln = ln->next;
    }
    std::cout << '\n';
}

void printLevel(int lv) {
    for (int i = 0; i < lv; i++) {
        std::cout << '\t';
    }
}