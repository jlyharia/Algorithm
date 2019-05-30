//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <Sorting.hpp>
#include "Utils.hpp"
#include <list>
#include <iostream>

using namespace std;

Sorting sorting;

TEST (Sorting, quick_sort) {
    vector<int> vec{5, 9, 4, 7, 2, 6, 1, 3, 8};
    sorting.quickSort(vec);
    print(vec);
}

std::ostream &operator<<(std::ostream &ostr, const std::list<int> &list) {
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

TEST (Sorting, quick_test) {
    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::list<int> list2 = {10, 20, 30, 40, 50};
    shared_ptr<std::list<int>> ptr = make_shared<std::list<int>>();
    ptr->push_back(123);
    cout << ptr->size() << endl;
    auto it = list1.begin();
//    std::advance(it, 2);

    list1.splice(it, list2);

//    std::cout << "list1: " << list1 << "\n";
//    std::cout << "list2: " << list2 << "\n";

}