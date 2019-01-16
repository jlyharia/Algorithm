//
// Created by Yihung Lee on 2018-12-05.
//

#include "StringQuiz.hpp"
#include "Utils.hpp"
#include <array>
#include <stack>

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
    unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int sum = map[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (map[s[i]] < map[s[i + 1]]) {
            sum -= map[s[i]];
        } else {
            sum += map[s[i]];
        }
    }
    return sum;
}

string StringQuiz::intToRoman(int num) {
    const array<string, 13> rom{{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}};
    const array<int, 13> digit{{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}};
    string ans;
    for (int i = 0; i < digit.size() && num > 0; i++) {
        int count = num / digit[i];
        if (count > 0) {
            num %= digit[i];
            for (int c = 0; c < count; c++) {
                ans += rom[i];
            }
        }
    }
    return ans;
}


string StringQuiz::longestCommonPrefix(vector<string> &&strs) {
    if (strs.empty()) return "";
    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (i > strs[j].size() - 1 || strs[j][i] != strs[0][i]) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}


/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
 */
bool StringQuiz::isValid(string s) {
    std::stack<char> arr;
    for (char c:s) {
        if (c == '(' || c == '{' || c == '[') {
            arr.push(c);
        } else if (arr.empty()) {
            arr.push(c);
            break;
        } else {
            if ((arr.top() == '(' && c == ')') ||
                (arr.top() == '{' && c == '}') ||
                (arr.top() == '[' && c == ']')) {
                arr.pop();
            } else {
                break;
            }
        }
    }
    return arr.empty();
}

/**
 * http://www.cnblogs.com/grandyang/p/4606696.html
 */
int StringQuiz::strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int m = haystack.size(), n = needle.size();
    if (m < n) return -1;
    for (int i = 0; i <= m - n; ++i) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }
    return -1;
}

/**
 *
 * You are given a string, s, and a list of words, words, that are all of the same length.
 *
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once
 * and without any intervening characters
 */
vector<int> StringQuiz::findSubstring(string s, vector<string> &&words) {
    vector<int> allPos;
    if (words.empty()) return allPos;
    int totalWords = words.size();

    // all words are the same length
    int wordSize = words[0].size();

    int totalLen = wordSize * totalWords;
    if (s.size() < totalLen) return allPos;

    unordered_map<string, int> wordCount;
    for (int i = 0; i < totalWords; i++)
        wordCount[words[i]]++;

    for (int i = 0; i <= s.size() - totalLen; i++) {
        // each time we check if there is substring within s[i~end]
        if (checkSubstring(s, i, wordCount, wordSize, totalWords))
            allPos.push_back(i);
    }
    return allPos;
}

bool
StringQuiz::checkSubstring(string S, int start, unordered_map<string, int> &wordCount, int wordSize, int totalWords) {
    if (S.size() - start + 1 < wordSize * totalWords) return false;
    unordered_map<string, int> wordFound;

    for (int i = 0; i < totalWords; i++) {
        string curWord = S.substr(start + i * wordSize, wordSize);
        // if word does not exist in dictionary
        if (wordCount.find(curWord) == wordCount.end()) return false;
        wordFound[curWord]++;
        if (wordFound[curWord] > wordCount[curWord]) return false;
    }
    return true;
}

/**
 *
 * official leetcode solution
 */

int StringQuiz::longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int maxLength = 0;
    // left to right
    for (const char &c:s) {
        if (c == '(') {
            left++;
        } else if (c == ')') {
            right++;
        }
        if (left == right) {
            maxLength = std::max(maxLength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;

    // right to left
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else if (s[i] == ')') {
            right++;
        }

        if (left == right) {
            maxLength = std::max(maxLength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxLength;
}
/**
 * https://blog.csdn.net/zhangxiao93/article/details/49183209
 * 第n項：第n-1項的數字串從左到右讀出來
 * http://www.cnblogs.com/grandyang/p/4086299.html
 */
string StringQuiz::countAndSay(int n) {
    if (n <= 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); ++i) {
            int cnt = 1;
            while (i + 1 < res.size() && res[i] == res[i + 1]) {
                ++cnt;
                ++i;
            }
            cur += to_string(cnt) + res[i];
        }
        res = cur;
    }
    return res;
}