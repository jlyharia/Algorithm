//
// Created by Lee, Yihung on 2019-05-22.
//

#ifndef ALGORITHM_LRUCACHE_HPP
#define ALGORITHM_LRUCACHE_HPP


#include <list>
#include <unordered_map>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    // 146. LRU Cache
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    int cap;
    list<pair<int, int>> queue;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};


#endif //ALGORITHM_LRUCACHE_HPP
