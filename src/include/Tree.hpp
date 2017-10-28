/*
 * Tree.hpp
 *
 *  Created on: Apr 17, 2015
 *      Author: johnny
 */

#ifndef TREE_HPP_
#define TREE_HPP_

template <typename T> struct BinaryTree {
    T data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(T data) : data(data), left(nullptr), right(nullptr) {}

    BinaryTree(T data, BinaryTree *left, BinaryTree *right)
        : data(data), left(left), right(right) {}
};

#endif /* TREE_HPP_ */
