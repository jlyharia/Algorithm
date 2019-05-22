//
// Created by Lee, Yihung on 2019-05-22.
//

#ifndef ALGORITHM_LRUCACHE_HPP
#define ALGORITHM_LRUCACHE_HPP


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
};


#endif //ALGORITHM_LRUCACHE_HPP
