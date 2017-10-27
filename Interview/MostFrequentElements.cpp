/*
 * MostFrequentElements.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: johnny
 */

#include "MostFrequentElements.hpp"
#include <queue>
#include <unordered_map>
// class mycomparison {
//     bool reverse;

//   public:
//     mycomparison(const bool &revparam = false) { reverse = revparam; }
//     bool operator()(const int &lhs, const int &rhs) const {
//         if (reverse)
//             return (lhs > rhs);
//         else
//             return (lhs < rhs);
//     }
// };
/**
 *
 * Given a list of ints and an integer k, return the k (note: not the kth) most
 * frequent elements
 * http://stackoverflow.com/a/7709970
 *
 * str str
 * http://articles.leetcode.com/2010/10/implement-strstr-to-find-substring-in.html
 */
void MostFrequentElements::test() {
    // k = 3
    auto limit = 3;
    vector<int> source = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 6, 6, 6, 7, 8, 5, 5, 5};
    unordered_map<int, int> umap;
    for (auto &i : source) {
        umap[i] += 1;
    }
    // --

    auto comp = [&](int a, int b) { return umap[a] > umap[b]; };
    priority_queue<int, vector<int>, decltype(comp)> mypq(comp);
    for (auto &i : umap) {
        cout << i.first << " -> " << i.second << endl;
    }

    for (auto &i : umap) {
        if (mypq.size() == limit) {
            if (umap[mypq.top()] < i.second) {
                // compare least frequent one with new one
                mypq.pop();
            } else {
                continue;
            }
        }
        mypq.push(i.first);
    }
    while (!mypq.empty()) {
        cout << mypq.top() << " ";
        mypq.pop();
    }
}
