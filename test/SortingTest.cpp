//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <Sorting.hpp>
#include "Utils.hpp"

using namespace std;

Sorting sorting;

TEST (Sorting, quick_sort) {
    vector<int> vec{5, 9, 4, 7, 2, 6, 1, 3, 8};
    sorting.quickSort(vec);
    print(vec);
}