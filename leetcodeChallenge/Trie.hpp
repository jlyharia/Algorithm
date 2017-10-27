/*
 * Trie.hpp
 *
 *  Created on: Sep 7, 2015
 *      Author: johnny
 */

#ifndef TRIE_HPP_
#define TRIE_HPP_
// LeetCode 208	Implement Trie (Prefix Tree)	24.9%	Medium
// http://blog.neofung.org/leetcode-implement-trie-prefix-tree/
#include "ChallengeBase.hpp"

class TrieNode {
  public:
    // Initialize your data structure here.
    TrieNode() : end(false) {
        for (int i = 0; i < 26; ++i)
            dict[i] = NULL;
    }
    TrieNode *dict[26];
    bool end;
};
class Trie : public ChallengeBase {
  public:
    Trie() { root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string word) {
        auto ptr = root;
        for (auto c : word) {
            unsigned char p = c - 'a';
            if (ptr->dict[p] == NULL) ptr->dict[p] = new TrieNode();
            ptr = ptr->dict[p];
        }
        ptr->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto ptr = root;
        for (auto c : word) {
            unsigned char p = c - 'a';
            if (ptr->dict[p] == NULL) return false;
            ptr = ptr->dict[p];
        }
        return ptr->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto ptr = root;
        for (auto c : prefix) {
            unsigned char p = c - 'a';
            if (ptr->dict[p] == NULL) return false;
            ptr = ptr->dict[p];
        }
        return true;
    }

    void test() override {
        cout << "LeetCode 208 Implement Trie (Prefix Tree) 24.9% Medium" << endl;
        Trie trie;
        trie.insert("somestring");
        cout << trie.search("omestring") << endl;
    };

  private:
    TrieNode *root;
};

#endif /* MINSTACK_HPP_ */