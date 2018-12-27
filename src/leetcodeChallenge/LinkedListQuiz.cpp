//
// Created by Yihung Lee on 2018-12-01.
//

#include "LinkedListQuiz.hpp"
#include <queue>

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
 * http://www.cnblogs.com/grandyang/p/4086297.html
 */
ListNode *LinkedListQuiz::mergeTwoLists(ListNode *l1, ListNode *l2) {
    /* recursion
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = this->mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = this->mergeTwoLists(l1, l2->next);
        return l2;
    }
    */

    ListNode *head = new ListNode(0);
    ListNode *cur = head;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return head->next;
}


ListNode *LinkedListQuiz::mergeKLists(std::vector<ListNode *> &&lists) {
    auto comp = [](const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(comp)> priorityQueue(comp);

    for (const auto &i: lists) {
        if (i) { // null list
            priorityQueue.push(i);
        }
    }

    ListNode *head = new ListNode(0);
    ListNode *cur = head;

    while (!priorityQueue.empty()) {
        ListNode *top = priorityQueue.top();
        cur->next = top;
        priorityQueue.pop();
        cur = cur->next;
        if (top->next) {
            priorityQueue.push(top->next);
        }

    }
    return head->next;
}


ListNode *LinkedListQuiz::reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur) {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

/**
 * 1) Your algorithm should use only constant extra space.<br />
 * 2) You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
ListNode *LinkedListQuiz::swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy ->next = head;
    ListNode *cur = head;
    ListNode *prev = dummy;
    while (cur && cur->next) {
        prev->next = cur->next;
        prev = cur;
        ListNode *temp = cur->next->next;
        cur->next->next = cur;
        cur->next = temp;
        cur = temp;
    }
    head = dummy->next;
    delete dummy;
    return head;
}