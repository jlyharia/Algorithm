/*
 * Permutation.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: johnny
 */

#include <Utils.hpp>
#include "Backtracking.hpp"

using namespace std;

void Backtracking::permuteString(std::string str, int i) {
	if (i == str.length()) {
		cout << str << " ";
	} else {
		for (int j = i; j < str.length(); j++) {
			swap(str[i], str[j]);
			permuteString(str, i + 1);
			swap(str[i], str[j]);
		}
	}
}

/**
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater
 * permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order
 * (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and
 * its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
// LeetCode 31  Next Permutation 25.1%  Medium
void Backtracking::nextPermutation(std::vector<int> &num) {

	int end = num.size() - 1;
	int idx_violate = -1;
	for (int i = end; i > 0; i--) {
		if (num[i] > num[i - 1]) {
			idx_violate = i - 1;
			break;
		}
	}
	if (idx_violate == -1) {
		reverse(num.begin(), num.end());

	} else {
		for (int i = end; i >= 0; i--) {
			if (num[i] > num[idx_violate]) {
				//				cout << "violate idx second= "
				//<<
				// idx_violate << endl;
				//				cout << i << endl;
				swap(num[idx_violate], num[i]);
				reverse(num.begin() + idx_violate + 1, num.end());
				break;
			}
		}
	}
	cout << "result = ";
	for_each(num.cbegin(), num.cend(), [&](int i) { cout << i << " "; });
	cout << endl;
}

/**
 * LeetCode 46  Permutations  31.8%  Medium
 * Given a collection of numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
vector<vector<int>> Backtracking::permute(vector<int> &num) {
	vector<vector<int>> result;
	per(num, 0, result);
	return result;
}

void Backtracking::per(vector<int> raw, int i, vector<vector<int>> &result) {
	if (i == raw.size()) {
		//		for_each(raw.cbegin(), raw.cend(), [&](int i)
		//{cout<<i<<"
		//";});
		result.push_back(raw);
		//		cout << endl;
	} else {
		for (int j = i; j < raw.size(); j++) {
			swap(raw[i], raw[j]);
			per(raw, i + 1, result);
			swap(raw[i], raw[j]);
		}
	}
}

/**
 * LeetCode 60  Permutation Sequence  22.7%  Medium
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 * 最高位可以取{1, 2, 3, 4}，而每個數重複3! =
 *6次。所以第k=9個permutation的s[0]為{1, 2, 3, 4}中的第9/6+1 = 2個數字s[0] = 2。
 * 而對於以2開頭的6個數字而言，k = 9是其中的第k' = 9%(3!) = 3個。
 * 而剩下的數字{1, 3, 4}的重複週期為2! = 2次。所以s[1]為{1, 3, 4}中的第k'/(2!)+1
 *= 2個，即s[1] = 3。
 * 對於以23開頭的2個數字而言，k = 9是其中的第k'' = k'%(2!) = 1個。剩下的數字{1,
 *4}的重複週期為1! = 1次。所以s[2] = 1.
 * 對於以231開頭的一個數字而言，k = 9是其中的第k''' = k''/(1!)+1 = 1個。s[3] = 4
 */
string Backtracking::getPermutation(int n, int k) {
	if (k < 1) return "";
	string perm = "";
	vector<int> raw(n);
	int frac = 1;
	for (int i = 0; i < n; i++) {
		raw[i] = i + 1;
		frac *= i + 1;
	}
	// change K from (1,n) to (0, n-1) to accord to index
	k--;
	int choose = 0;
	for (int i = 0; i < n; i++) {
		frac = frac / (n - i);
		choose = k / frac;

		perm.push_back(raw[choose] + '0');
		for (int j = choose; j < n; j++) {
			raw[j] = raw[j + 1];
		}

		k = k % frac;
	}

	return perm;
}

/**
 * LeetCode 17 Letter Combinations of a Phone Number  25.8%  Medium
 * Given a digit string, return all possible letter combinations that the number
 *could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given
 *below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 */
vector<string> Backtracking::letterCombinations(string digits) {
	vector<string> result;
	if (digits.size() > 0) lcLoop(result, digits, 0);
	return result;
}

void Backtracking::lcLoop(vector<string> &result, string digits, int i) {
	if (i == digits.size()) {
		result.push_back(digits);
		return;
	}
	const string candidate = mapCode[digits[i] - 48];
	for (auto j : candidate) {
		digits[i] = j;
		lcLoop(result, digits, i + 1);
	}
}

void Backtracking::test17() {
	cout << "LeetCode 17 Letter Combinations of a Phone Number  25.8%  Medium" << endl;

	auto result = letterCombinations("23");

	for_each(result.cbegin(), result.cend(), [&](string str) { cout << str << " "; });
	cout << endl;
}

/**
 * LeetCode 51  N-Queens  26.6%  Hard
 * The n-queens puzzle is the problem of placing n queens on an n×n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens'
 *placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 * http://www.cnblogs.com/TenosDoIt/p/3801621.html
 */
vector<vector<string>> Backtracking::solveNQueens(int n) {
	vector<vector<string>> result;
	vector<string> cur(n, string(n, '.'));
	getNQueens(result, cur, 0);
	return result;
}

void Backtracking::getNQueens(vector<vector<string>> &result, vector<string> &cur, const int row) {
	cout << row << " " << cur.size() << endl;
	if (row == cur.size()) {
		result.push_back(cur);
		return;
	}
	for (auto col = 0; col < cur.size(); col++) {
		if (isValid(cur, row, col)) {
			//			cout << row << "--" << col << endl;
			cur[row][col] = 'Q';
			getNQueens(result, cur, row + 1);
			cur[row][col] = '.';
		}
	}
}

bool Backtracking::isValid(vector<string> &cur, int row, int col) {
	// row
	for (int i = 0; i < row; i++)
		if (cur[i][col] == 'Q') return false;
	// right diagonal
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		if (cur[i][j] == 'Q') return false;
	// left diagonal
	for (int i = row - 1, j = col + 1; i >= 0 && j < cur.size(); i--, j++)
		if (cur[i][j] == 'Q') return false;
	return true;
}

void Backtracking::test51() {
	cout << "LeetCode 51  N-Queens  26.6%  Hard" << endl;
	// n 3 4
	auto n = 4;
	auto result = solveNQueens(n);
	cout << result.size() << endl;
	for (auto row = 0; row < result.size(); ++row) {
		cout << row;
		for (auto j = 0; j < result[row].size(); ++j) {
			if (j % n == 0) cout << endl;
			cout << result[row][j] << ' ';
		}
		cout << endl;
	}
}

/**
 LeetCode 22 Generate Parentheses 32.8%	Medium
 Given n pairs of parentheses, write a function to generate all combinations of well-formed
parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */
void Backtracking::generateParenthesis(int n) {
	std::string A(n * 2, '(');
	auto i = 0;
	generatePar(A, i, n, 0, 0);
}

void Backtracking::generatePar(string A, int i, const int n, int L, int R) {

	if (i == n * 2) {
		cout << A << endl;
		return;
	}
	if (L < n) {
		A[i] = '(';
		generatePar(A, i + 1, n, L + 1, R);
	}
	if (R < L) {
		A[i] = ')';
		generatePar(A, i + 1, n, L, R + 1);
	}
}

void Backtracking::test22() {
	cout << "LeetCode 22 Generate Parentheses 32.8%	Medium" << endl;
	int input = 3;
	generateParenthesis(input);

	// auto output = generateParenthesis(input);
	// for (auto &i : output) {
	//     cout << i << " ";
	// }
	// cout << endl;
}

/**
LeetCode 79 Word Search 20.9% Medium
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are
those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
http://bangbingsyb.blogspot.com/2014/11/leetcode-word-search.html
*/
bool Backtracking::exist(vector<vector<char>> &board, string word) {

	vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
	for (auto i = 0; i < board.size(); i++) {
		for (auto j = 0; j < board[i].size(); j++) {
			if (wordSearch(board, visit, 0, word, i, j)) return true;
		}
	}
	return false;
}

bool Backtracking::wordSearch(const vector<vector<char>> &board, vector<vector<bool>> visit,
							  int idx, const string word, int i, int j) {
	if (idx == word.length()) return true;
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visit[i][j] ||
		board[i][j] != word[idx])
		return false;
	visit[i][j] = true;
	// up
	if (wordSearch(board, visit, idx + 1, word, i - 1, j)) return true;
	// down
	if (wordSearch(board, visit, idx + 1, word, i + 1, j)) return true;
	// left
	if (wordSearch(board, visit, idx + 1, word, i, j - 1)) return true;
	// right
	if (wordSearch(board, visit, idx + 1, word, i, j + 1)) return true;
	visit[i][j] = false;
	return false;
}

void Backtracking::test79() {
	cout << "LeetCode 79 Word Search 20.9% Medium" << endl;
	string word = "ABCCEDG";

	vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
								  {'S', 'F', 'C', 'S'},
								  {'A', 'D', 'E', 'E'}};
	cout << this->exist(board, word) << endl;
}

/**
        LeetCode 212 Word Search II	15.4%  Hard
    Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are
those horizontally or vertically neighboring. The same letter cell may not be used more than once in
a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
vector<string> Backtracking::findWords(vector<vector<char>> &board, vector<string> &words) {}

void Backtracking::test212() { cout << "LeetCode 212 Word Search II	15.4%  Hard" << endl; }

void Backtracking::solveSudoku(vector<vector<char>> &board) {
	if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
	sudokudfs(board, 0, 0);
}

bool Backtracking::sudokudfs(vector<vector<char>> &board, int row, int col) {
	if (row == 9)
		return true;
	if (col > 8)
		return sudokudfs(board, row + 1, 0);

	if (board[row][col] == '.') {
		for (int i = 1; i < 10; i++) {
			char e = (char) (i + '0');

			if (validSudokuElement(board, row, col, e)) {
				board[row][col] = e;
				if (sudokudfs(board, row, col + 1))
					return true;
				board[row][col] = '.';
			}

		}
	} else {
		return sudokudfs(board, row, col + 1);
	}

	return false;
}

bool Backtracking::validSudokuElement(vector<vector<char>> &board, int row, int col, char e) {
	// horizontal
	for (auto j = 0; j < board[row].size(); j++) {
		if (j != col && board[row][j] == e) {
			return false;
		}
	}
	// vertical
	for (auto i = 0; i < board.size(); i++) {
		if (i != row && board[i][col] == e) {
			return false;
		}
	}
	// square
	const pair<int, int> left_corner = {(row / 3) * 3, (col / 3) * 3};

	for (int i = left_corner.first; i < left_corner.first + 3; i++) {
		for (int j = left_corner.second; j < left_corner.second + 3; j++) {
			if (i != row && j != col && e == board[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Backtracking::isMatchWildcard(string s, string p) {

}

void Backtracking::test() {
	cout << "__FILE__ : " << __FILE__ << endl;
	//	string str = "1234";
	//	cout << "permute string = " << str << endl;
	//	cout << "result = ";
	//	permuteString(str, 0);
	//	cout << endl << endl;
	//
	//	cout << "LeetCode 31  Next Permutation 25.1%  Medium" << endl;
	//	vector<int> sample { 6, 8, 7, 4, 3, 2 };
	//	cout << "sample = ";
	//	for_each(sample.cbegin(), sample.cend(), [&](int i) {cout<<i<<" ";});
	//	cout << endl;
	//	nextPermutation(sample);
	//
	//	vector<int> sample2 { 1, 2, 3 };
	//	cout << "sample2 = ";
	//	for_each(sample2.cbegin(), sample2.cend(), [&](int i) {cout<<i<<" ";});
	//	cout << endl;
	//	nextPermutation(sample2);
	//	cout << endl << endl;
	//
	//	cout << "LeetCode 46  Permutations  31.8%  Medium" << endl;
	//	cout << "sample2 = ";
	//	for_each(sample2.cbegin(), sample2.cend(), [&](int i) {cout<<i<<" ";});
	//	cout << endl;
	//	permute(sample2);
	//	cout << endl << endl;
	//
	//	cout << "LeetCode 60  Permutation Sequence  22.7%  Medium" << endl;
	//	int n = 4;
	//	int k = 9;
	//	cout << "n = " << n << ", k = " << k << endl;
	//	cout << getPermutation(n, k);
	//	cout << getPermutation(n, 0);
	//	cout << endl << endl;

	//	cout << "LeetCode 47  Permutations II  25.8%  Hard" << endl;
	//	test17();
	// test51();
	// test22();
	// test79();
	test212();
}
