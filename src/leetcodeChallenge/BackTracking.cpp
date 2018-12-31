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


/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
vector<string> BackTracking::generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesisHelper(n, n, "", ans);
    return ans;
}

void BackTracking::generateParenthesisHelper(int L, int R, string res, vector<string> &ans) {
    if (L == 0 && R == 0) {
        ans.push_back(res);
    } else if (L >=0 && L <= R) {
        generateParenthesisHelper(L - 1, R, res + '(', ans);
        generateParenthesisHelper(L, R - 1, res + ')', ans);
    }
}


void BackTracking::nextPermutation(vector<int>& nums){

}