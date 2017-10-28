/*
 * Sorting.hpp
 *
 *  Created on: Apr 22, 2015
 *      Author: johnny
 */

#ifndef SORTING_HPP_
#define SORTING_HPP_
#include <vector>
/**
 * quick sort
 * merge sort
 * insertion sort
 * bubble sort
 * TODO heap sort
 */
using namespace std;
class Sorting {
  public:
    Sorting() {}

    void quickSort(vector<int> &vec, int begin, int end);
    int partition(vector<int> &vec, int begin, int end);

    vector<int> mergeSort(vector<int> vec, int begin, int end);

    vector<int> mergeJoin(const vector<int> &vec1, const vector<int> &vec2);

    void insertionSort(vector<int> &vec);

    void bubbleSort(vector<int> &vec);

    void heapSort(vector<int> &vec);
    void heapify(vector<int> &vec, int i, int boundary);
    void test();
    ~Sorting() {}
};

#endif /* SORTING_HPP_ */
