//
// Created by Yihung Lee on 2019-06-18.
//

#ifndef ALGORITHM_LFUCACHE_HPP
#define ALGORITHM_LFUCACHE_HPP

#include <Utils.hpp>
#include <unordered_map>
#include <list>

class LFUCache {
public:
    LFUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    int cap, minFreq;
    std::unordered_map<int, std::pair<int, int>> m;
    std::unordered_map<int, std::list<int>> freq;
    std::unordered_map<int, std::list<int>::iterator> iter;
};


#endif //ALGORITHM_LFUCACHE_HPP
