//
// Created by Yihung Lee on 6/12/18.
//

#include "DepthFirstSearch.hpp"


string DepthFirstSearch::decodeString(string s) {

    string ans = "";
    decodeStringHelper(s, 0, ans);
    return ans;
}

void DepthFirstSearch::decodeStringHelper(string s, unsigned int idx, string &ans) {
    if (s.size() > idx && !std::isdigit(s.at(idx))) {
        // print until digit or ]
        while (s.size() > idx && !std::isdigit(s.at(idx)) && s.at(idx) != ']') {
            ans.push_back(s.at(idx++));
        }
    }
    if (s.size() > idx && std::isdigit(s.at(idx))) {
        int repeat = s.at(idx) - '0';
        for (int i = 0; i < repeat; i++) {
            decodeStringHelper(s, idx + 2, ans);
        }
    }
    // find next available index
    while (s.size() > idx && s.at(idx) != ']') {
        idx++;
    }
    if (s.size() > idx) {
        decodeStringHelper(s, idx + 1, ans);
    }

}