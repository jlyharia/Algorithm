//
// Created by Yihung Lee on 2018-12-01.
//

#ifndef ALGORITHM_LINKEDLIST_HPP
#define ALGORITHM_LINKEDLIST_HPP

#include <Utils.hpp>

class LinkedListQuiz {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);


    ListNode *reverseList(ListNode *node);

    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n);

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};


#endif //ALGORITHM_LINKEDLIST_HPP
