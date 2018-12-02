//
// Created by Yihung Lee on 2018-12-01.
//

#include "LinkedListQuiz.hpp"

/**
 *
 * case 3 - carry digit
    Input: (2 -> 9) + (5 -> 6 -> 9)
    Output: 7 -> 5 -> 0 -> 1
    92 + 965 = 1057
 */
ListNode *LinkedListQuiz::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    int res = 0;
    int sum = 0;
    ListNode *head = nullptr;
    ListNode *prev = nullptr;

    while (l1 != nullptr || l2 != nullptr) {

        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        carry = sum / 10;
        res = sum % 10;

        ListNode *temp = new ListNode(res);

        if (head == nullptr) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) {
        prev->next = new ListNode(carry);
    }

    return head;    
}