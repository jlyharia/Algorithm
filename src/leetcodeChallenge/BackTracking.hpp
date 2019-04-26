//
// Created by Yihung Lee on 2018-12-01.
//

#ifndef ALGORITHM_BACKTRACKING_HPP
#define ALGORITHM_BACKTRACKING_HPP

#include <Utils.hpp>
#include <string>
#include <unordered_map>

using namespace std;

class BackTracking {
public:

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations(string digits);

    // 22. Generate Parentheses
    vector<string> generateParenthesis(int n);

    // 31. Next Permutation
    void nextPermutation(vector<int> &nums);

    // 36. Valid Sudoku
    bool isValidSudoku(vector<vector<char>> &board);

    // 37. Sudoku Solver
    void solveSudoku(vector<vector<char>> &board);

    // 39. Combination Sum
    vector<vector<int>> combinationSum(vector<int> &&candidates, int target);

    // 40. Combination Sum II
    vector<vector<int>> combinationSum2(vector<int> &&candidates, int target);

    // 46. Permutations
    vector<vector<int>> permute(vector<int> &nums);

    // 47. Permutations II
    vector<vector<int>> permuteUnique(vector<int> &&nums);

    // 216. Combination Sum III
    vector<vector<int>> combinationSum3(int k, int n);

    // 78. Subsets
    vector<vector<int>> subsets(vector<int> &&nums);

    // 90. Subsets II
    vector<vector<int>> subsetsWithDup(vector<int> &&nums);


private:
    void
    letterCombinationsHelper(vector<string> &ans, const string digits, string res, int idx,
                             const unordered_map<char, string> &map);

    void generateParenthesisHelper(int L, int R, string res, vector<string> &ans);

    bool solveSudokuHelper(vector<vector<char>> &board, int i, int j);

    bool isValidSudokuNumber(vector<vector<char>> &board, int x, int y);

    void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out, vector<vector<int>> &ans);

    void
    permuteUniqueDFS(vector<int> &nums, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &res);

    void dfsSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &ans);

    void combinationSum2DFS(vector<int> &candidates, int target, int pos, vector<int> &out,
                            vector<vector<int>> &ans);

    void dfsSubsetsWithDup(vector<int> &nums, int pos, vector<bool> &visit, vector<int> &out,
                           vector<vector<int>> &ans);

};


#endif //ALGORITHM_BACKTRACKING_HPP
