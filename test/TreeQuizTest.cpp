//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include "LeetCodeHeaders.hpp"

using namespace std;

TreeQuiz tq;

TEST (TreeQuiz, level_order) {
    vector<int> treeList = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    auto *root = createTree(treeList);
    auto traversal = tq.levelOrder(root);
//
//    for (auto row: traversal) {
//        for (auto col: row) {
//            cout << col << " ";
//        }
//        cout << "\n";
//    }
//    tq.levelOrder()
}