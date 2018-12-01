//
// Created by Yihung Lee on 2018-12-01.
//

#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP

#include <vector>
#include <iostream>

template<class T>
void print(std::vector<T> &vec) {
    for (auto &&i:vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';

}

#endif //ALGORITHM_UTILS_HPP
