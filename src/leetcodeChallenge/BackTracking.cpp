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
    if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
    solveSudokuHelper(board, 0, 0);
}

bool BackTracking::solveSudokuHelper(vector<vector<char>> &board, int i, int j) {
    if (i == 9) return true;
    if (j >= 9) return solveSudokuHelper(board, i + 1, 0);
    if (board[i][j] == '.') {
        for (int k = 1; k < 10; k++) {
            board[i][j] = (char) ('0' + k);
            if (isValidSudokuNumber(board, i, j)) {
                if (solveSudokuHelper(board, i, j + 1)) return true;
            }
            board[i][j] = '.';
        }
    } else {
        return solveSudokuHelper(board, i, j + 1);
    }
    return false;
}

bool BackTracking::isValidSudokuNumber(vector<vector<char>> &board, int i, int j) {
    vector<int> check(9, false);
    // col
    for (int col = 0; col < 9; col++) {
        if (col != j && board[i][j] == board[i][col]) return false;
    }
    // row
    for (int row = 0; row < 9; row++) {
        if (i != row && board[i][j] == board[row][j]) {
            return false;
        }
    }
    // section
    for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
        for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
            if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
        }
    }
    return true;
}

/**
 *
 * http://www.cnblogs.com/grandyang/p/4419259.html
 * Similar Question
 * Path Sum II，Subsets II，Permutations，Permutations II，Combinations
 */
vector<vector<int>> BackTracking::combinationSum(vector<int> &&candidates, int target) {
    vector<vector<int>> res;
    combinationSumDFS(candidates, target, 0, {}, res);
    return res;
}

void BackTracking::combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out,
                                     vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(out);
    } else {
        for (int i = start; i < candidates.size(); i++) {
            int temp = target - candidates[i];
            if (temp < 0) {
                break;
            }
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, temp, i, out, ans);
            out.pop_back();
        }
    }
}

vector<vector<int>> BackTracking::subsets(vector<int> &&nums) {
    vector<vector<int>> ans;
    vector<int> out;
    std::sort(nums.begin(), nums.end());
    dfsSubsets(nums, 0, out, ans);
    return ans;
}

void BackTracking::dfsSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &ans) {
    if (pos == nums.size()) {
        ans.push_back(out);
    } else {
        out.push_back(nums[pos]);
        dfsSubsets(nums, pos + 1, out, ans);
        out.pop_back();
        dfsSubsets(nums, pos + 1, out, ans);
    }
}

vector<vector<int>> BackTracking::permute(vector<int> &nums) {

}


vector<vector<int>> BackTracking::permuteUnique(vector<int> &&nums) {
    vector<vector<int>> res;
    vector<int> out, visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    permuteUniqueDFS(nums, 0, visited, out, res);
    return res;
}

void BackTracking::permuteUniqueDFS(vector<int> &nums, int level, vector<int> &visited, vector<int> &out,
                                    vector<vector<int>> &res) {
    if (level >= nums.size()) {
        res.push_back(out);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] == 1) continue;
        if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
            continue;
        }
        visited[i] = 1;
        out.push_back(nums[i]);
        permuteUniqueDFS(nums, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int>> BackTracking::combinationSum2(vector<int> &&candidates, int target) {
    vector<int> out;
    vector<vector<int>> ans;
    std::sort(candidates.begin(), candidates.end());
    combinationSum2DFS(candidates, target, 0, out, ans);
    return ans;
}

void BackTracking::combinationSum2DFS(vector<int> &candidates, int target, int pos, vector<int> &out,
                                      vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(out);
    } else {
        for (int i = pos; i < candidates.size(); i++) {
            int temp = target - candidates[i];
            if (temp < 0) {
                break;
            }
            if (i > pos && candidates[i - 1] == candidates[i]) {
                continue;
            }
            out.push_back(candidates[i]);
            combinationSum2DFS(candidates, temp, i + 1, out, ans);
            out.pop_back();
        }
    }
}

vector<vector<int>> BackTracking::subsetsWithDup(vector<int> &&nums) {
    vector<bool> visit(nums.size(), false);
    vector<int> out;
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    dfsSubsetsWithDup(nums, 0, visit, out, ans);
    return ans;
}

void BackTracking::dfsSubsetsWithDup(vector<int> &nums, int pos, vector<bool> &visit, vector<int> &out,
                                     vector<vector<int>> &ans) {
    if (pos == nums.size()) {
        ans.push_back(out);
    } else {
        if (!(pos > 0 && nums[pos] == nums[pos - 1] && !visit[pos - 1])) {
            visit[pos] = true;
            out.push_back(nums[pos]);
            dfsSubsetsWithDup(nums, pos + 1, visit, out, ans);
            out.pop_back();
            visit[pos] = false;
        }
        dfsSubsetsWithDup(nums, pos + 1, visit, out, ans);
    }
}

vector<vector<int>> BackTracking::combinationSum3(int k, int n) {

}

int BackTracking::numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int num = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                numIslandsDfs(grid, visited, i, j);
                num++;
            }
        }
    }
    return num;
}

void BackTracking::numIslandsDfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0') {
        return;
    }
    visited[x][y] = true;
    numIslandsDfs(grid, visited, x + 1, y);
    numIslandsDfs(grid, visited, x - 1, y);
    numIslandsDfs(grid, visited, x, y + 1);
    numIslandsDfs(grid, visited, x, y - 1);
}