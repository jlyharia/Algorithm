//
// Created by Yihung Lee on 2018-12-01.
//

#ifndef ALGORITHM_LINKEDLIST_HPP
#define ALGORITHM_LINKEDLIST_HPP

#include <Utils.hpp>

class LinkedListQuiz {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

    // 206. Reverse Linked List
    ListNode *reverseList(ListNode *head);

    // 19. Remove Nth Node From End of List
    ListNode *removeNthFromEnd(ListNode *head, int n);

    // 21. Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

    // 23. Merge k Sorted Lists
    ListNode *mergeKLists(std::vector<ListNode *> &&lists);

    // 24. Swap Nodes in Pairs
    ListNode *swapPairs(ListNode *head);

    // 25. Reverse Nodes in k-Group
    ListNode *reverseKGroup(ListNode *head, int k);
};


#endif //ALGORITHM_LINKEDLIST_HPP
