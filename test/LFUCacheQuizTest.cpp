//
// Created by Yihung Lee on 10/31/17.
//

#include "gtest/gtest.h"
#include <LRUCache.hpp>

using namespace std;


TEST (LRUCache, cache) {
    LFUCache *cache = new LFUCache(2 /* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(1, cache->get(1));       // returns 1
    cache->put(3, 3);    // evicts key 2
    EXPECT_EQ(-1, cache->get(2));       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    EXPECT_EQ(-1, cache->get(1));       // returns -1 (not found)
    EXPECT_EQ(3, cache->get(3));       // returns 3
    EXPECT_EQ(4, cache->get(4));       // returns 4
}