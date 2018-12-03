//
// Created by Yihung Lee on 2018-12-02.
//


#include "Utils.hpp"

void printListNode(ListNode *ln) {
    while (ln != nullptr) {
        std::cout << ln->val << '\t';
        ln = ln->next;
    }
    std::cout << '\n';
}