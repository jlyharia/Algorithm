/*
 * SingleLinkedList.hpp
 *
 *  Created on: Apr 16, 2015
 *      Author: johnny
 */

#ifndef SINGLELINKEDLIST_HPP_
#define SINGLELINKEDLIST_HPP_

template <typename T> struct SingleLinkedList {
    SingleLinkedList() : next(nullptr), data(0) {}

    SingleLinkedList(T data, SingleLinkedList<T> *node) : data(data), next(node) {}
    SingleLinkedList(T data) : data(data), next(nullptr) {}
    T data;
    SingleLinkedList<T> *next;
};

#endif /* SINGLELINKEDLIST_HPP_ */
