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

private:
    void
    letterCombinationsHelper(vector<string> &ans, const string digits, string res, int idx,
                             const unordered_map<char, string> &map);

    void generateParenthesisHelper(int L, int R, string res, vector<string> &ans);
};


#endif //ALGORITHM_BACKTRACKING_HPP
