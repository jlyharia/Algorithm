//
// Created by Lee, Yihung on 1/25/18.
//

#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printMatrix(const vector<vector<T>> &mat) {
	cout << endl;
	for (auto row: mat) {
		for (auto e: row) {
			cout << e << " ";
		}
		cout << endl;
	}
}

#endif //ALGORITHM_UTILS_HPP
