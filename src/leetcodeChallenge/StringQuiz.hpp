/*
 * Substring.hpp
 *
 *  Created on: Apr 20, 2015
 *      Author: johnny
 */

#ifndef STRINGQUIZ_HPP_
#define STRINGQUIZ_HPP_

#include "ChallengeBase.hpp"

class StringQuiz : public ChallengeBase {
public:
	StringQuiz() {}

	/**
	 *
	 * LeetCode 3 Longest Substring Without Repeating Characters 21.1% Medium
	 * Given a string, find the length of the longest substring without
	 *repeating characters.
	 * Given For example, the longest substring without repeating letters for
	 *"abcabcbb" is "abc",
	 * Given which the length is 3. For "bbbbb" the longest substring is "b",
	 *with the length of 1.
	 */
	int LongestSubstringWithoutRepeatingCharacters(std::string str);

	// LeetCode 5 Longest Palindromic Substring 20.7% Medium
	void LongestPalindromicSubstring(std::string str);

	// LeetCode 30 Substring with Concatenation of All Words 19.3% Hard
	void SubstringWithConcatenationOfAllWords(std::string str);

	// LeetCode 76 Minimum Window Substring 18.7 Hard
	void MinimumWindowSubstring(std::string str);

	// LeetCode 20 Valid Parentheses   26.6%   Easy
	void test20();

	bool isValid(string s);

	void test();

	~StringQuiz() {}

	// LeetCode 14  Longest Common Prefix  25.5%  Easy
	void test14();

	string longestCommonPrefix(vector<string> &strs);

	// LeetCode 10 Regular Expression Matching   20.7%   Hard
	void test10();

	bool isMatch(string s, string p);

	// LeetCode 151 Reverse Words in a String   15.3%   Medium
	void reverseWords(string &s);

	void reverseString(string &s, int begin, int end);

	void test151();
};

#endif /* STRINGQUIZ_HPP_ */
