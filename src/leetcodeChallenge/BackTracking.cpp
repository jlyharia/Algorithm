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
    } else if (L >= 0 && L <= R) {
        generateParenthesisHelper(L - 1, R, res + '(', ans);
        generateParenthesisHelper(L, R - 1, res + ')', ans);
    }
}

/**
 * http://www.cnblogs.com/grandyang/p/4428207.html
 */
void BackTracking::nextPermutation(vector<int> &nums) {
    int n = nums.size(), i = n - 2, j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
        while (nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

bool BackTracking::isValidSudoku(vector<vector<char>> &board) {
    // row
    for (int i = 0; i < 9; i++) {
        std::vector<bool> check(9, false);
        for (int j = 0; j < 9; j++) {
            if (std::isdigit(board[i][j])) {
                int d = board[i][j] - '0';
                if (check[d - 1]) {
                    return false;
                } else {
                    check[d - 1] = true;
                }
            }
        }
    }
    // column
    for (int j = 0; j < 9; j++) {
        std::vector<bool> check(9, false);
        for (int i = 0; i < 9; i++) {
            if (std::isdigit(board[i][j])) {
                int d = board[i][j] - '0';
                if (check[d - 1]) {
                    return false;
                } else {
                    check[d - 1] = true;
                }
            }
        }
    }

    // 3x3 section
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::vector<bool> check(9, false);
            // section
            for (int si = 0; si < 3; si++) {
                for (int sj = 0; sj < 3; sj++) {
                    int r = 3 * i + si;
                    int c = 3 * j + sj;
                    if (std::isdigit(board[r][c])) {
                        int d = board[r][c] - '0';
                        if (check[d - 1]) {
                            return false;
                        } else {
                            check[d - 1] = true;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void BackTracking::solveSudoku(vector<vector<char>> &board) {

}

bool isValidSudokuNumber(vector<vector<char>> &board, int x, int y) {
    vector<int> check(9, false);
    // row
    for (int j = 0; j < 9; j++) {
        if (j != y && std::isdigit(board[x][j])) {
            int d = board[x][j] - '0';
            if (d == board[x][j]) {
                return false;
            }
        }
    }
    // column
    for (int i = 0; i < 9; i++) {
        if (i != x && std::isdigit(board[i][y])) {
            int d = board[i][y] - '0';
            if (d == board[i][y]) {
                return false;
            }
        }
    }
    return true;
}