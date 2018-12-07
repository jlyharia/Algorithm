//
// Created by Yihung Lee on 2018-12-05.
//

#include "StringQuiz.hpp"


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