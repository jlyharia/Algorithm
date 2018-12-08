//
// Created by Yihung Lee on 2018-12-06.
//

#include "MathQuiz.hpp"


int MathQuiz::reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int MathQuiz::myAtoi(string str) {
    if (str.empty()) return 0;
    int sign = 1, base = 0, i = 0, n = str.size();
    while (i < n && str[i] == ' ') ++i;
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '+') ? 1 : -1;
    }
    while (i < n && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            //32位int的最大值 2147483647 的最后一位
            //即 7 == INT_MAX % 10
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}


bool isPalindrome(int x)