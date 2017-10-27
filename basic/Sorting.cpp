/*
 * Sorting.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#include "../basic/Sorting.hpp"

#include <algorithm>
#include <iostream>
void Sorting::quickSort(vector<int> &vec, int begin, int end) {
    if (end > begin) {
        int p = partition(vec, begin, end);
        quickSort(vec, begin, p - 1);
        quickSort(vec, p + 1, end);
    }
}

int Sorting::partition(vector<int> &vec, int begin, int end) {
    int p = begin;
    int i = begin + 1;
    int j = end;
    while (i < j) {
        if (vec[i] < vec[p]) {
            i++;
        } else {
            if (vec[j] > vec[p]) {
                j--;
            } else {
                swap(vec[i], vec[j]);
                i++;
                j--;
            }
        }
    }
    if (vec[p] > vec[i - 1]) swap(vec[p], vec[i - 1]);
    return i - 1;
}

void Sorting::insertionSort(vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[i]) { swap(vec[j], vec[i]); }
        }
    }
}

void Sorting::bubbleSort(vector<int> &vec) {
    for (int i = vec.size(); i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (vec[j] < vec[j - 1]) { swap(vec[j], vec[j - 1]); }
        }
    }
}

vector<int> Sorting::mergeSort(vector<int> vec, int begin, int end) {
    vector<int> pool{vec[begin]};
    if (end > begin) {
        int mid = (begin + end) / 2;
        vector<int> left = mergeSort(vec, begin, mid);
        vector<int> right = mergeSort(vec, mid + 1, end);

        pool = mergeJoin(left, right);
    }
    return pool;
}

vector<int> Sorting::mergeJoin(const vector<int> &vec1, const vector<int> &vec2) {
    int i = 0;
    int j = 0;
    vector<int> join;
    while (i < vec1.size() || j < vec2.size()) {

        if (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] < vec2[j]) {
                join.push_back(vec1[i]);
                i++;
            } else {
                join.push_back(vec2[j]);
                j++;
            }
        } else if (i == vec1.size()) {
            // add from vec 2
            join.push_back(vec2[j]);
            j++;
        } else {
            // add from vec 1
            join.push_back(vec1[i]);
            i++;
        }
    }
    return join;
}

void Sorting::heapSort(vector<int> &vec) {
    int i = vec.size() / 2;
    for (; i >= 0; i--) {
        heapify(vec, i, vec.size());
    }
    swap(vec[0], vec[vec.size() - 1]);
    for (int j = vec.size() - 1; j > 0; j--) {

        heapify(vec, 0, j);
        swap(vec[0], vec[j - 1]);
    }
}
void Sorting::heapify(vector<int> &vec, int root, int boundary) {
    auto father = root;
    auto son = father * 2 + 1;
    while (son < boundary) {
        if (son + 1 < boundary && vec[son] < vec[son + 1]) {
            // has two son and second one is bigger
            son++;
        }
        if (vec[father] < vec[son]) {

            swap(vec[father], vec[son]);
            father = son;
            son = father * 2 + 1;
        } else {
            break;
        }
    }
}

void Sorting::test() {
    //	vector<int> vec { 4, 2, 5, 9, 20, 1, 11, 8 };
    //	cout << "input array = " << endl;
    //	for_each(vec.cbegin(), vec.cend(), [&](int i) {cout<<i<<", ";});
    //	cout << endl;
    //	cout << "Quick sort = " << endl;
    //	quickSort(vec, 0, vec.size() - 1);
    //	for_each(vec.cbegin(), vec.cend(), [&](int i) {cout<<i<<", ";});
    //	cout << endl;
    //
    //	vector<int> vec2 { 4, 2, 5, 9, 20, 1, 11, 8 };
    //	cout << "Insertion sort = " << endl;
    //	insertionSort(vec2);
    //	for_each(vec2.cbegin(), vec2.cend(), [&](int i) {cout<<i<<", ";});
    //	cout << endl;
    //
    //	vector<int> vec3 { 4, 2, 5, 9, 20, 1, 11, 8 };
    //	cout << "bubble sort = " << endl;
    //	bubbleSort(vec3);
    //	for_each(vec3.cbegin(), vec3.cend(), [&](int i) {cout<<i<<", ";});
    //	cout << endl;
    //
    //	vector<int> vec4 { 4, 2, 5, 9, 20, 1, 11, 8 };
    //	cout << "merge sort = " << endl;
    //
    //	auto c = mergeSort(vec4, 0, vec4.size() - 1);
    //	for_each(c.cbegin(), c.cend(), [&](int i) {cout<<i<<", ";});
    //	cout << endl;

    vector<int> vec5{4, 2, 5, 9, 20, 1, 11, 8};
    cout << "heap sort = " << endl;
    heapSort(vec5);
    for_each(vec5.cbegin(), vec5.cend(), [&](int i) { cout << i << ", "; });
}
