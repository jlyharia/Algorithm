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
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    cout << "dp= \n";
    print(dp);
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] != '.' && p[j - 1] != '*') {
                if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1])
                    dp[i][j] = true;
            } else if (p[j - 1] == '.') {
                if (i > 0 && dp[i - 1][j - 1])
                    dp[i][j] = true;
            } else if (j > 1) {  //'*' cannot be the 1st element
                if (dp[i][j - 1] || dp[i][j - 2]) {  // match 0 or 1 preceding element
                    bool ss = dp[i][j - 1];
                    bool sss = dp[i][j - 2];
                    dp[i][j] = true;
                }
                else if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') &&
                         dp[i - 1][j]) // match multiple preceding elements
                    dp[i][j] = true;
            }
            cout << "i = " << i << " j = " << j << '\n';
            print(dp);
        }
    }
    return dp[m][n];
}
/*
bool StringQuiz::isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    cout << "dp= \n";
    print(dp);
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1 && p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            } else {
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
            cout << "i = " << i << " j = " << j << '\n';
            print(dp);
        }
    }
    return dp[m][n];
}
*/