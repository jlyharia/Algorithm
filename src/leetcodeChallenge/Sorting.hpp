//
// Created by Lee, Yihung on 2019-05-23.
//

#ifndef ALGORITHM_SORTING_HPP
#define ALGORITHM_SORTING_HPP

#include <vector>

class Sorting {
public:
    void quickSort(std::vector<int> &);

    int kSmallest(std::vector<int> &vec, int k);

private:
    void quickSort(std::vector<int> &vec, int low, int high);

    int quickSortPartition(std::vector<int> &vec, int low, int high);

    void kSmallestSort(std::vector<int> &vec, int low, int high, int k);

    int kSmallestPartition(std::vector<int> &vec, int low, int high);
};


#endif //ALGORITHM_SORTING_HPP
