/*
 * Tree.hpp
 *
 *  Created on: Apr 17, 2015
 *      Author: johnny
 */

#ifndef TREE_HPP_
#define TREE_HPP_

template<typename T>
struct TreeNode {
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}

    TreeNode(T data, TreeNode *left, TreeNode *right)
            : data(data), left(left), right(right) {}
};

template<typename T>
TreeNode<T> *createTree(vector<T> treeList, int idx) {
    if (idx > treeList.size() - 1) {
        return nullptr;
    }
    const auto data = treeList.at(idx);
    if (INT_MIN == data) {
        return nullptr;
    }
    TreeNode<T> *node = new TreeNode<T>(data);
    node->left = createTree(treeList, idx * 2 + 1);
    node->right = createTree(treeList, idx * 2 + 2);

    return node;
}

template<typename T>
TreeNode<T> *createTree(vector<T> treeList) {
    return createTree(treeList, 0);
}


template<typename T>
void in_order(const TreeNode<T> *root) {
    if (root != nullptr) {
        in_order(root->left);
        std::cout << root->data << " ";
        in_order(root->right);
    }
}

#endif /* TREE_HPP_ */
