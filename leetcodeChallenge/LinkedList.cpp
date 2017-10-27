/*
 * LinkedList.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: johnny
 */

#include "LinkedList.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
using namespace std;

template <typename T> void LinkedList::traverse(T *node) {
    while (node) {
        std::cout << node->data << ' ';
        node = node->next;
    }
    std::cout << std::endl;
}

ListInt *LinkedList::getSample() {

    ListInt *n4 = new ListInt(4, nullptr);
    ListInt *n3 = new ListInt(3, n4);
    ListInt *n2 = new ListInt(2, n3);
    ListInt *n1 = new ListInt(1, n2);
    return n1;
}

ListInt *LinkedList::reverseRecursive(ListInt *node) {
    if (!node) return node;
    // recursive version
    if (node->next == nullptr) {
        return node;

    } else {
        ListInt *begin = reverseRecursive(node->next);
        node->next->next = node;
        node->next = nullptr;
        return begin;
    }
}
ListInt *LinkedList::reverseLoop(ListInt *node) {
    if (!node) return node;
    ListInt *begin;
    ListInt *prev = nullptr;
    while (node) {

        ListInt *next = node->next;
        node->next = prev;
        prev = node;
        begin = node;

        node = next;
    }
    return begin;
}
ListInt *LinkedList::getSample2() {

    ListInt *n7 = new ListInt(1, nullptr);
    ListInt *n6 = new ListInt(5, n7);
    ListInt *n5 = new ListInt(4, n6);
    ListInt *n4 = new ListInt(3, n5);
    ListInt *n3 = new ListInt(6, n4);
    ListInt *n2 = new ListInt(2, n3);
    ListInt *n1 = new ListInt(6, n2);
    return n1;
}

/**
 * LeetCode  203 Remove Linked List Elements  28.0%  Easy
 * Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */
ListInt *LinkedList::removeElements(ListInt *node, int val) {

    ListInt *current = node;
    ListInt *prev = nullptr;
    ListInt *head = node;
    //	cout << head << endl;
    //	cout << node << endl;
    while (current) {
        if (current->data == val) {
            if (head == current) {
                head = current->next;
                delete current;
            } else {

                prev->next = current->next;
            }

        } else {
            prev = current;
        }
        current = current->next;
    }
    return head;
}
/**
 * LeetCode  160 Intersection of Two Linked Lists  27.9%  Easy
 * Write a program to find the node at which the intersection of two singly
 *linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                       c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 *returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */
ListString *LinkedList::getIntersectionNode(ListString *headA, ListString *headB) {
    int lengthA = getListLength<ListString>(headA);
    int lengthB = getListLength<ListString>(headB);
    ListString *pivot = new ListString("null", nullptr);
    if (lengthA > lengthB) {
        auto diff = lengthA - lengthB;
        for (int i = 0; i < diff; i++) {
            headA = headA->next;
        }
    } else {
        auto diff = lengthB - lengthA;
        for (int i = 0; i < diff; i++) {
            headB = headB->next;
        }
    }

    while (headA && headB) {
        if (headA->data == headB->data) {
            pivot = headA;
            break;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return pivot;
}

template <typename T> int LinkedList::getListLength(T *node) {
    int i = 0;
    while (node) {
        node = node->next;
        i++;
    }
    return i;
}
void LinkedList::test160() {
    cout << "LeetCode  160 Intersection of Two Linked Lists  27.9%  Easy" << endl;
    ListString *c3 = new ListString("c3", nullptr);
    ListString *c2 = new ListString("c2", c3);
    ListString *c1 = new ListString("c1", c2);
    ListString *b3 = new ListString("b3", c1);
    ListString *b2 = new ListString("b2", b3);
    ListString *b1 = new ListString("b1", b2);
    ListString *a2 = new ListString("a2", c1);
    ListString *a1 = new ListString("a1", a2);

    traverse<ListString>(a1);
    traverse<ListString>(b1);
    ListString *pivot = getIntersectionNode(a1, b1);
    cout << pivot->data << endl;
}
/**
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a
 *single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

ListInt *LinkedList::addTwoNumbers(ListInt *l1, ListInt *l2) {
    auto s1 = this->getListLength(l1);
    auto s2 = this->getListLength(l2);
    if (s1 < s2) swap(l1, l2);
    // l1 is longer than l2

    auto head = l1;
    auto carry = 0;
    while (true) {
        if (l2) {
            l1->data += l2->data;
            l2 = l2->next;
        }
        l1->data += carry;
        carry = l1->data / 10;
        l1->data = l1->data % 10;

        if (!l1->next) {
            if (carry != 0) l1->next = new ListInt(carry);
            break;
        }
        l1 = l1->next;
    }

    return head;
}
void LinkedList::test2() {
    cout << "LeetCode 2  Add Two Numbers  21.9%  Medium reverse order" << endl;
    auto sample = getSample3();

    auto l1 = sample[0];
    auto l2 = sample[1];
    cout << "l1 = ";
    this->traverse(l1);
    cout << "l2 = ";
    this->traverse(l2);
    auto result = addTwoNumbers(l1, l2);
    cout << "result = ";
    this->traverse(result);
    cout << endl;
}
vector<ListInt *> LinkedList::getSample3() {

    ListInt *a3 = new ListInt(9, nullptr);
    ListInt *a2 = new ListInt(2, a3);
    ListInt *a1 = new ListInt(7, a2);

    ListInt *b4 = new ListInt(8, nullptr);
    ListInt *b3 = new ListInt(3, b4);
    ListInt *b2 = new ListInt(4, b3);
    ListInt *b1 = new ListInt(5, b2);
    vector<ListInt *> sample{a1, b1};
    return sample;
}

/**
 * LeetCode 141  Linked List Cycle   36.3%   Medium
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */
bool LinkedList::hasCycle(ListInt *node) {

    auto *p1 = node;
    auto *p2 = node;

    do {
        if (p2 == nullptr || p2->next == nullptr) return false;
        p1 = p1->next;
        p2 = p2->next->next;

    } while (p1 != p2);

    return true;
}
void LinkedList::test141() {
    cout << "LeetCode 141  Linked List Cycle   36.3%   Medium\n";
    auto a1 = this->getCycledList();
    cout << this->hasCycle(a1) << endl;
}
ListInt *LinkedList::getCycledList() {
    ListInt *a7 = new ListInt(7);
    ListInt *a6 = new ListInt(6, a7);
    ListInt *a5 = new ListInt(5, a6);
    ListInt *a4 = new ListInt(4, a5);
    ListInt *a3 = new ListInt(3, a4);
    ListInt *a2 = new ListInt(2, a3);
    ListInt *a1 = new ListInt(1, a2);
    a7->next = a3;
    return a1;
}
/**
 * LeetCode 142  Linked List Cycle  II 31.3%   Medium
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */
ListInt *LinkedList::detectCycle(ListInt *node) {
    auto *p1 = node;
    auto *p2 = node;

    do {
        if (p2 == nullptr || p2->next == nullptr) return nullptr;
        p1 = p1->next;
        p2 = p2->next->next;

    } while (p1 != p2);

    p1 = node;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}
void LinkedList::test142() {
    cout << "LeetCode 142  Linked List Cycle  II 31.3%   Medium\n";
    auto a1 = this->getCycledList();
    auto res = this->detectCycle(a1);
    if (res == nullptr) {
        cout << "no cycle";
    } else {
        cout << "cycle at " << res->data << endl;
    }
}

/** LeetCode 19   Remove Nth Node From End of List    26.8%   Easy
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
ListInt *LinkedList::removeNthFromEnd(ListInt *head, int n) {
    auto ori = head;
    auto out = head;
    while (head && n != -1) {
        head = head->next;
        n--;
    }

    if (n == 0) { // remove head
        return out->next;
    }
    while (head) {
        head = head->next;
        ori = ori->next;
    }
    ori->next = ori->next->next;
    return out;
}
void LinkedList::test19() {
    cout << "LeetCode 19   Remove Nth Node From End of List    26.8%   Easy" << endl;
    auto sample = this->getSample2();
    auto head = sample;
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    // auto head2 = sample;
    auto result = removeNthFromEnd(sample, 7);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
}
/**
LeetCode 83	Remove Duplicates from Sorted List	34.7%	Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
ListInt *LinkedList::deleteDuplicates(ListInt *head) {
    auto cur = head;
    while (cur && cur->next) {
        if (cur->next->data == cur->data) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}
void LinkedList::test83() {
    cout << "LeetCode 83  Remove Duplicates from Sorted List	34.7%	Easy" << endl;

    ListInt *a7 = new ListInt(7);
    ListInt *a6 = new ListInt(6, a7);
    ListInt *a5 = new ListInt(3, a6);
    ListInt *a4 = new ListInt(3, a5);
    ListInt *a3 = new ListInt(3, a4);
    ListInt *a2 = new ListInt(1, a3);
    ListInt *a1 = new ListInt(0, a2);

    auto result = deleteDuplicates(a1);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
}
/**
LeetCode 82	Remove Duplicates from Sorted List II	25.1%	Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
ListInt *LinkedList::deleteDuplicates2(ListInt *head) {
    auto dummy = new ListInt(-123, head);
    auto cur = dummy;
    int du;
    auto pre = cur;
    while (cur && cur->next) {
        if (du && cur->data == du) {
            *cur = *cur->next;
            continue;
        }
        if (cur->next->data == cur->data) {
            du = cur->data;
            continue;
        }
        pre = cur;
        cur = cur->next;
    }

    if (du && cur->data == du) { pre->next = nullptr; }
    return dummy->next;
}
void LinkedList::test82() {
    cout << "LeetCode 82  Remove Duplicates from Sorted List II	25.1%	Medium" << endl;
    // ListInt *a7 = new ListInt(6);
    // ListInt *a6 = new ListInt(6, a7);
    // ListInt *a5 = new ListInt(3, a6);
    // ListInt *a4 = new ListInt(2, a5);
    // ListInt *a3 = new ListInt(2, a4);
    ListInt *a3 = new ListInt(1);
    ListInt *a2 = new ListInt(1, a3);
    ListInt *a1 = new ListInt(1, a2);

    auto result = deleteDuplicates2(a1);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
}
/** LeetCode 138 Copy List with Random Pointer 25.6% Hard
A linked list is given such that each node contains an additional random pointer which could point
to any node in the list or null.

Return a deep copy of the list.

http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

*/
RandomListNode *LinkedList::copyRandomList(RandomListNode *head) {}
void LinkedList::test138() {
    cout << "LeetCode 138 Copy List with Random Pointer 25.6% Hard" << endl;
}
void LinkedList::test() {
    //	auto *root = getSample();
    //	traverse<ListInt>(root);
    //	cout << "--reverse by recursive--\n";
    //	auto *newRoot = reverseRecursive(root);
    //	traverse<ListInt>(newRoot);
    //	cout << "--reverse by loop---\n";
    //
    //	auto *newRoot2 = reverseLoop(newRoot);
    //	traverse<ListInt>(newRoot2);
    //
    //	cout << "LeetCode  203 Remove Linked List Elements  28.0%  Easy" <<
    // endl;
    //	auto head = getSample2();
    //	traverse<ListInt>(head);
    //	auto res = removeElements(head, 6);
    //	traverse<ListInt>(res);
    //
    //	test160();
    // LeetCode 2  Add Two Numbers  21.9%  Medium
    // test2();

    //	test141();
    //

    // test142();
    // test19();
    // test83();
    test82();
}
