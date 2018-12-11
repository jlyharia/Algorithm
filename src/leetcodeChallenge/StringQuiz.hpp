//
// Created by Yihung Lee on 2018-12-05.
//

#ifndef ALGORITHM_STRINGQUIZ_HPP
#define ALGORITHM_STRINGQUIZ_HPP

#include <string>
#include <vector>
using namespace std;

class StringQuiz {
public:
    // 5. Longest Palindromic Substring
    string longestPalindrome(string s);

    // 6. ZigZag Conversion
    string convert(string s, int numRows);

    // 10. Regular Expression Matching
    bool isMatch(string s, string p);
private:
    int expandAroundCenter(string s, int begin, int end);
};


#endif //ALGORITHM_STRINGQUIZ_HPP
