//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <LinkedListQuiz.hpp>

using namespace std;

LinkedListQuiz lq;

/**
 * reverse order
 * case 1 - same digit
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
 case 2- different digit
    Input: (2 -> 4 -> 7) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 2 -> 1
    742 + 465 = 1207
 case 3 - carry digit
    Input: (2 -> 9) + (5 -> 6 -> 9)
    Output: 7 -> 5 -> 0 -> 1
    92 + 965 = 1057
 */
TEST (LinkedListQuiz, Add_Two_Numbers) {
    ListNode *case3_l1 = new ListNode(2, new ListNode(9));
    ListNode *case3_l2 = new ListNode(5, new ListNode(6, new ListNode(9)));
    printListNode(case3_l1);
    printListNode(case3_l2);
    ListNode *answer = lq.addTwoNumbers(case3_l1, case3_l2);
    printListNode(answer);
}


TEST (LinkedListQuiz, Remove_Nth_Node_From_End_of_List) {
    {
        // 1->2->3->4->5, and n = 1.
        ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printListNode(head);
        ListNode *ans = lq.removeNthFromEnd(head, 1);
        printListNode(ans);
    }
    {
        // 1->2->3->4->5, and n = 2.
        ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printListNode(head);
        ListNode *ans = lq.removeNthFromEnd(head, 2);
        printListNode(ans);
    }
    {
        ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printListNode(head);
        ListNode *ans = lq.removeNthFromEnd(head, 3);
        printListNode(ans);
    }
    {
        ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printListNode(head);
        ListNode *ans = lq.removeNthFromEnd(head, 4);
        printListNode(ans);
    }
    {
        ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printListNode(head);
        ListNode *ans = lq.removeNthFromEnd(head, 5);
        printListNode(ans);
    }
    {
        ListNode *head = new ListNode(1);
        ListNode *ans = lq.removeNthFromEnd(head, 1);
        EXPECT_EQ(NULL, ans);
    }
}

TEST (LinkedListQuiz, Merge_Two_Sorted_Lists) {
//    Input: 1->2->4, 1->3->4
//    Output: 1->1->2->3->4->4

    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(6))));
    ListNode *ans = lq.mergeTwoLists(l1, l2);
    printListNode(ans);
}

TEST (LinkedListQuiz, Merge_K_Sorted_Lists) {
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));
    // Output: 1->1->2->3->4->4->5->6

//    ListNode *ans = lq.mergeKLists({l1, l2, l3});
    ListNode *ans = lq.mergeKLists({});

    printListNode(ans);
}