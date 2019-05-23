//
// Created by Lee, Yihung on 2019-05-23.
//

#include "Sorting.hpp"


void Sorting::quickSort(std::vector<int> &vec) {
    return quickSort(vec, 0, vec.size());
}

void Sorting::quickSort(std::vector<int> &vec, int low, int high) {
    if (low < high) {
        int pivot = quickSortPartition(vec, low, high);
        quickSort(vec, low, pivot);
        quickSort(vec, pivot + 1, high);
    }
}

int Sorting::quickSortPartition(std::vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low;
    for (int j = low + 1; j < high; j++) {
        if (vec[j] < pivot) {
            std::swap(vec[j], vec[++i]);
        }
    }
    std::swap(vec[low], vec[i]);
    return i;
}