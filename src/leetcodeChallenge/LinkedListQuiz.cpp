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


ListNode *LinkedListQuiz::removeNthFromEnd(ListNode *head, int n) {
    ListNode *slow = new ListNode(0);
    slow->next = head;
    ListNode *fast = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    int cn = 0;
    while (fast) {
        cn++;
        fast = fast->next;
        slow = slow->next;
    }
    if (cn == 0) {
        // remove head
        ListNode *del = slow->next;
        head = head->next;
        delete del;
    } else {
        // regular
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
    }

    return head;
}


/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */
ListNode *LinkedListQuiz::mergeTwoLists(ListNode *l1, ListNode *l2) {

}