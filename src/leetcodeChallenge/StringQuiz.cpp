/*
 * Substring.cpp
 *
 *  Created on: Apr 20, 2015
 *      Author: johnny
 */

#include "StringQuiz.hpp"
#include <cstdio>
#include <stack>
#include <unordered_map>
/**
 * LeetCode 20 Valid Parentheses   26.6%   Easy
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 *']',
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order,
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
bool StringQuiz::isValid(string s) {
    if (s.length() < 2) return false;

    unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (map.find(s[i]) == map.end()) {
            // not found
            st.push(s[i]);
        } else {
            if (st.size() == 0) return false;
            char prev = st.top();
            if (prev == map[s[i]]) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if (st.size() != 0) return false;
    return true;
}
void StringQuiz::test20() {
    cout << "LeetCode 20 Valid Parentheses   26.6%   Easy" << endl;
    string s = "(){}()()";
    cout << "input " << s << " = " << isValid(s) << endl;
    s = "(())";
    cout << "input " << s << " = " << isValid(s) << endl;
    s = "())";
    cout << "input " << s << " = " << isValid(s) << endl;
    s = "(([))";
    cout << "input " << s << " = " << isValid(s) << endl;
}

/**
 * LeetCode 10 Regular Expression Matching   20.7%   Hard
 *
 * Implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ah", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
 */
bool StringQuiz::isMatch(string s, string p) {
    //	if (p.length() == 0) {
    //		return true;
    //	}
    //	char prev;
    //	int j = 0;
    //	char k = p[k];
    //
    //	for (auto i : s) {
    //
    //	}

    return true;
}
void StringQuiz::test10() {
    cout << "LeetCode 10 Regular Expression Matching   20.7%   Hard" << endl;
    string s = "aa";
    string regex = "a";
    printf("isMatch(\"%s\", \"%s\") = %i", s.c_str(), regex.c_str(), isMatch(s, regex));
}

/**
 * LeetCode 14  Longest Common Prefix  25.5%  Easy
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 */
string StringQuiz::longestCommonPrefix(vector<string> &strs) { return ""; }
void StringQuiz::test14() { cout << "LeetCode 14  Longest Common Prefix  25.5%  Easy" << endl; }

/** LeetCode 151 Reverse Words in a String   15.3%   Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

http://www.cnblogs.com/dolphin0520/p/3700019.html

*/
void StringQuiz::reverseWords(string &s) {

    // reverse whole sentence
    reverseString(s, 0, s.length() - 1);

    // reverse each word
    for (auto i = 0; i < s.length(); i++) {
        if (i != ' ') {
            auto j = i;
            while (j < s.length() && s[j] != ' ') {
                j++;
            }
            // cout << i << " " << j << endl;
            reverseString(s, i, j - 1);
            i = j;
        }
    }
}
void StringQuiz::reverseString(string &s, int begin, int end) {
    while (begin < end) {
        swap(s[begin++], s[end--]);
    }
}

void StringQuiz::test151() {
    cout << "151 Reverse Words in a String   15.3%   Medium" << endl;
    string s = "the sky is blue";
    // string s = "   ";
    cout << "input string = " << s << ";" << endl;
    reverseWords(s);
    cout << "output = " << s << ";" << endl;
}
void StringQuiz::test() {
    cout << "LeetCode 3 Longest Substring Without Repeating Characters 21.1% Medium" << endl;
    string str = "geekforgeekz";
    cout << LongestSubstringWithoutRepeatingCharacters(str) << endl;

    str = "bbbbb";
    cout << LongestSubstringWithoutRepeatingCharacters(str) << endl;

    cout << "LeetCode 5 Longest Palindromic Substring 20.7% Medium" << endl;

    cout << "LeetCode 30 Substring with Concatenation of All Words 19.3% Hard" << endl;

    cout << "LeetCode 76 Minimum Window Substring 18.7 Hard" << endl;
    test20();
    test10();
    test151();
}
// Find the length of the longest substring without repeating characters.
int StringQuiz::LongestSubstringWithoutRepeatingCharacters(string str) {
    /**
     * i-curr_len > prev means the previous occurrence of str[i] does not lie in
     * the current substring
     * that is being considered. for example when we encounter 2nd "g" in the
     * string geeksforgeeks,
     * we have prev_index=0, i=8, curr_len=6. So the condition is true, and
     * curr_len is incremented
     */
    cout << "input string = " << str << endl;
    int maxLength = 1;
    int curLength = 1;
    vector<int> visited(1 + (int)'z', -1);
    visited[str[0]] = 0;

    int prev;
    for (int i = 1; i < str.size(); i++) {
        prev = visited.at(str[i]);
        if (prev == -1 || i - curLength > prev) {
            curLength++;
        } else {
            if (curLength > maxLength) { maxLength = curLength; }
            curLength = 1 - prev;
        }
        visited[str[i]] = i;
    }
    if (curLength > maxLength) maxLength = curLength;

    return maxLength;
}
