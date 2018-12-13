//
// Created by Yihung Lee on 2018-12-05.
//

#include "StringQuiz.hpp"
#include "Utils.hpp"

string StringQuiz::longestPalindrome(string s) {

    if (s.empty() || s.length() < 1) {
        return "";
    }

    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = std::max(len1, len2);
        if (len > end - start) {
            // update longest palendrome index
            // for pair center, i is start from i not i + 1
            start = i - (len - 1) / 2;

            end = i + len / 2;
        }
    }
    return s.substr(start, end + 1 - start);
}

// Given a center, either one letter or two letter,
// Find longest palindrome
int StringQuiz::expandAroundCenter(string s, int begin, int end) {
    while (begin >= 0 && end <= s.length() - 1 && s[begin] == s[end]) {
        begin--;
        end++;
    }
    return end - begin - 1;
}

string StringQuiz::convert(string s, int numRows) {
    if (numRows == 1) return s;
    int cycleLen = 2 * (numRows - 1);
    int n = s.size();
    string ret;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < s.size(); j += cycleLen) {
            ret += s[i + j];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                // not first row, not last row and next character is within length
                ret += s[j + cycleLen - i];
            }
        }
    }
    return ret;
}

/**
 * Explain better
 * http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
 * https://www.youtube.com/watch?v=DqhPJ8MzDKM
 */
bool StringQuiz::isMatch(string s, string p) {
    const int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }
    return dp[m][n];
}

int StringQuiz::romanToInt(string s) {

}