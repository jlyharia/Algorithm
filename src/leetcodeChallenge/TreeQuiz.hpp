/*
 * BinaryTreeTraversal.hpp
 *
 *  Created on: Apr 17, 2015
 *      Author: johnny
 */

#ifndef BINARYTREETRAVERSAL_HPP_
#define BINARYTREETRAVERSAL_HPP_
#include "ChallengeBase.hpp"
#include "Tree.hpp"

using BSTint = BinaryTree<int>;
using BSTstring = BinaryTree<string>;

class TreeQuiz : public ChallengeBase {
  public:
    BSTstring *getSample();
    BSTint *getSampleInt();
    void test();

  private:
    void preorderTranveralRecursive(BSTstring *node);
    void preorderTranveralLoop(BSTstring *node);
    void inorderTranveralRecursive(BSTstring *node);
    void inorderTranveralLoop(BSTstring *node);
    void postorderTranveralRecursive(BSTstring *node);
    void postorderTranveralLoop(BSTstring *node);

    // LeetCode 226  Invert Binary Tree  37.3%   Easy
    BSTstring *invertTree(BSTstring *root);
    void test226();

    // LeetCode 230  Kth Smallest Element in a BST  31.2%  Medium
    string kthSmallest(BSTstring *root, int k);
    void test230();

    // 199  Binary Tree Right Side View  28.2%  Medium
    vector<string> rightSideView(BSTstring *node);
    vector<string> result;
    void tranverse(BSTstring *node, int level, int &max);
    void test199();

    // LeetCode 103	Binary Tree Zigzag Level Order Traversal	26.6%	Medium
    vector<vector<int>> zigzagLevelOrder(BSTint *root);
    void test103();
};

#endif /* BINARYTREETRAVERSAL_HPP_ */
