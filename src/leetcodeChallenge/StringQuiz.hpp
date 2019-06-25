//
// Created by Yihung Lee on 2018-12-05.
//

#ifndef ALGORITHM_STRINGQUIZ_HPP
#define ALGORITHM_STRINGQUIZ_HPP

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class StringQuiz {
public:
    // 5. Longest Palindromic Substring
    string longestPalindrome(string s);

    // 6. ZigZag Conversion
    string convert(string s, int numRows);

    // 10. Regular Expression Matching
    bool isMatch(string s, string p);

    // 12. Integer to Roman
    string intToRoman(int num);

    // 13. Roman to Integer
    int romanToInt(string s);

    // 14. Longest Common Prefix
    string longestCommonPrefix(vector<string> &&strs);

    // 20. Valid Parentheses
    bool isValid(string s);

    // 28. Implement strStr()
    int strStr(string haystack, string needle);

    // 30. Substring with Concatenation of All Words
    vector<int> findSubstring(string s, vector<string> &&words);

    // 32. Longest Valid Parentheses
    int longestValidParentheses(string s);

    // 38. Count and Say
    string countAndSay(int n);

    // 224. Basic Calculator
    int calculate(string s);

private:
    int expandAroundCenter(string s, int begin, int end);

    bool checkSubstring(string S, int start, unordered_map<string, int> &wordCount, int wordSize, int totalWords);

};


#endif //ALGORITHM_STRINGQUIZ_HPP
