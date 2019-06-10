//
// Created by Lee, Yihung on 2019-05-23.
//

#include "Sorting.hpp"
#include <random>

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

void Sorting::kSmallest(std::vector<int> &vec, int k) {
    kSmallestSort(vec, 0, vec.size(), k);
}

void Sorting::kSmallestSort(std::vector<int> &vec, int low, int high, int k) {
//    std::random_device rd;  //Will be used to obtain a seed for the random number engine
//    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> dis(low, high - 1);
    int pivot = kSmallestPartition(vec, low, high);
    int leftLength = pivot - low + 1;
    if (k > leftLength) {
        kSmallestSort(vec, pivot + 1, high, k - leftLength);
    } else if (k < leftLength) {
        kSmallestSort(vec, low, pivot, k);
    }
}

int Sorting::kSmallestPartition(std::vector<int> &vec, int low, int high) {
    int i = low;
    for (int j = low + 1; j < high; j++) {
        if (vec.at(low) > vec.at(j)) {
            std::swap(vec.at(j), vec.at(++i));
        }
    }
    std::swap(vec.at(low), vec.at(i));
    return i;
}