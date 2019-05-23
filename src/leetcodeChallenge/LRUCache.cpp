//
// Created by Lee, Yihung on 2019-05-22.
//

#include "LRUCache.hpp"


LRUCache::LRUCache(int capacity) {
    cap = capacity;
}

int LRUCache::get(int key) {
    auto it = map.find(key);
    if (it == map.end()) return -1;
    queue.splice(queue.begin(), queue, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = map.find(key);
    if (it != map.end()) queue.erase(it->second);
    queue.push_front(make_pair(key, value));
    map[key] = queue.begin();
    if (map.size() > cap) {
        int k = queue.rbegin()->first;
        queue.pop_back();
        map.erase(k);
    }
}