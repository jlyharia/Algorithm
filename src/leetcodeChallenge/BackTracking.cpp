//
// Created by Yihung Lee on 2018-12-01.
//

#include "BackTracking.hpp"


vector<string> BackTracking::letterCombinations(string digits) {
    if (digits.empty()) return {};
    const unordered_map<char, string> map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };
    vector<string> ans;
    letterCombinationsHelper(ans, digits, "", 0, map);
    return ans;
}


void BackTracking::letterCombinationsHelper(vector<string> &ans, const string digits, string res, int idx,
                                            const unordered_map<char, string> &map) {

    if (res.size() == digits.size()) {
        ans.push_back(res);
    } else {
        for (auto s : map.at(digits[idx])) {
            letterCombinationsHelper(ans, digits, res + s, idx + 1, map);
        }
    }
}