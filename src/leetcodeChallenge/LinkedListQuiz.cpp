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
    ListNode *dummy = new ListNode(0), *p = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        p->next = new ListNode(carry % 10);
        carry /= 10;
        p = p->next;
    }
    return dummy->next;
}