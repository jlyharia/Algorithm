/*
 * LinkedList.hpp
 *
 *  Created on: Apr 16, 2015
 *      Author: johnny
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include "ChallengeBase.hpp"
#include "SingleLinkedList.hpp"
using ListInt = SingleLinkedList<int>;
using ListString = SingleLinkedList<std::string>;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class LinkedList : public ChallengeBase {
  public:
    LinkedList() {}

    void test() override;
    ~LinkedList() {}

  private:
    template <typename T> void traverse(T *node);

    ListInt *getSample();
    ListInt *getSample2();
    // LeetCode 206  Reverse Linked List  37.5%  Easy
    ListInt *reverseRecursive(ListInt *node);
    ListInt *reverseLoop(ListInt *node);

    // LeetCode 92 Reverse Linked List II 26.2%  Medium
    ListInt *reverseBetween(ListInt *node, int m, int n);

    // LeetCode  160 Intersection of Two Linked Lists  27.9%  Easy
    ListString *getIntersectionNode(ListString *headA, ListString *headB);
    void test160();
    template <typename T> int getListLength(T *node);
    // LeetCode  203 Remove Linked List Elements  28.0%  Easy
    ListInt *removeElements(ListInt *node, int val);

    // LeetCode 2  Add Two Numbers  21.9%  Medium
    ListInt *addTwoNumbers(ListInt *l1, ListInt *l2);
    std::vector<ListInt *> getSample3();
    //	int addNode(ListInt* l1, ListInt* l2, int diff);
    void test2();

    // LeetCode 141  Linked List Cycle   36.3%   Medium
    bool hasCycle(ListInt *node);
    void test141();

    // LeetCode 142  Linked List Cycle  II 31.3%   Medium
    ListInt *detectCycle(ListInt *node);
    void test142();

    // LeetCode 19   Remove Nth Node From End of List    26.8%   Easy
    ListInt *removeNthFromEnd(ListInt *head, int n);
    void test19();

    ListInt *getCycledList();

    // LeetCode 83	Remove Duplicates from Sorted List	34.7%	Easy
    ListInt *deleteDuplicates(ListInt *head);
    void test83();

    // LeetCode 82	Remove Duplicates from Sorted List II	25.1%	Medium
    ListInt *deleteDuplicates2(ListInt *head);
    void test82();

    // LeetCode 138 Copy List with Random Pointer 25.6% Hard
    RandomListNode *copyRandomList(RandomListNode *head);
    void test138();
};

#endif /* LINKEDLIST_HPP_ */
