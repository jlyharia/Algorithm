/*
 *
 *  Created on: Apr 23, 2015
 *      Author: johnny
 */

#ifndef BACKTRACKING_HPP_
#define BACKTRACKING_HPP_

#include "ChallengeBase.hpp"

class Backtracking : public ChallengeBase {
public:
    Backtracking() {}

    void test() override;

    ~Backtracking() {}

    void per(std::vector<int> raw, int i, std::vector<std::vector<int>> &result);

    // LeetCode 17 Letter Combinations of a Phone Number  25.8%  Medium
    vector<string> letterCombinations(string digits);

    void lcLoop(vector<string> &result, string digits, int i);

    void test17();

    // LeetCode 31  Next Permutation 25.1%  Medium
    void nextPermutation(std::vector<int> &num);

    // LeetCode 46  Permutations  31.8%  Medium
    std::vector<std::vector<int>> permute(std::vector<int> &&nums);


    // LeetCode 51  N-Queens  26.6%  Hard
    vector<vector<string>> solveNQueens(int n);

    void getNQueens(vector<vector<string>> &result, vector<string> &cur, const int row);

    bool isValid(vector<string> &cur, int row, int col);

    void test51();

    // LeetCode 52  N-Queens II  35.8%  Hard
    int totalNQueens(int n);

    void test52();

    // LeetCode 60  Permutation Sequence  22.7%  Medium
    std::string getPermutation(int n, int k);

    void permuteString(std::string str, int i);

    const vector<string> mapCode = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // LeetCode 22	Generate Parentheses 32.8%	Medium
    void generateParenthesis(int n);

    void generatePar(string A, int i, const int n, int L, int R);

    void test22();

    // LeetCode 79	Word Search	20.9%	Medium
    bool exist(vector<vector<char>> &board, string word);

    bool wordSearch(const vector<vector<char>> &board, vector<vector<bool>> visit, int idx,
                    const string word, int i, int j);

    void test79();

    // Leetcode 212	Word Search II	15.4%	Hard
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words);

    void test212();

    // 37. Sudoku Solver
    void solveSudoku(vector<vector<char>> &board);

    // 44. Wildcard Matching
    bool isMatchWildcard(string s, string p);

    vector<vector<int>> combine(int n, int k);

    void printBinary(int numOfDigit);

    // 47. Permutations II
    vector<vector<int>> permuteUnique(vector<int>&& nums);

private:

    void printBinaryHelper(int numOfDigit, std::string prefix);

    bool validSudokuElement(vector<vector<char>> &board, int row, int col, char e);

    bool sudokudfs(vector<vector<char>> &board, int row, int col);

    void permuteBacktrack(vector<int> &nums, vector<int> cur, vector<bool> isVisit, vector<vector<int>> &result);

    void combineDFS(vector<vector<int>> &ret, vector<int> curr, int n, int k, int level);


};

#endif /* BACKTRACKING_HPP_ */
