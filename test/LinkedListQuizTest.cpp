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
TEST (LinkedListQu, Add_Two_Numbers) {
    ListNode* case3_l1 = new ListNode(2, new ListNode(9));
    ListNode* case3_l2 = new ListNode(5, new ListNode(6, new ListNode(9)));
    printListNode(case3_l1);
    printListNode(case3_l2);
    ListNode* answer = lq.addTwoNumbers(case3_l1, case3_l2);
    printListNode(answer);
}


