/*
 * MathQuiz.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: johnny
 */

#include "MathQuiz.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <regex>

/**
 * LeetCode 224  Basic Calculator  15.7%  Medium
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ),
 * the plus + or minus sign -, non-negative integers and empty spaces .
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 *
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * https://market.cloud.edu.tw/content/senior/computer/ks_ks/et/datastruct/compute/compute.htm
 */
int MathQuiz::calculate(string s) {
    // remove while space
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    cout << s << endl;
    auto strOrder = reorder(s);
    auto postfix = to_postfix(strOrder);
    stack<int> st;
    for (auto it : postfix) {
        if (std::isdigit(it.front())) {
            st.push(std::stoi(it));
        } else {
            auto n2 = st.top();
            st.pop();
            auto n1 = st.top();
            st.pop();
            cout << "n1 n2 = " << n1 << " " << n2 << endl;

            switch (it.front()) {
            case '+':
                n1 += n2;
                break;
            case '-':
                n1 -= n2;
                break;
            case '*':
                n1 *= n2;
                break;
            case '/':
                n1 /= n2;
                break;
            default:
                break;
            }
            cout << n1 << endl;
            st.push(n1);
        }
    }
    //	cout << st.top() << endl;
    return st.top();
}
vector<string> MathQuiz::reorder(string str) {
    vector<string> newStr;
    for (auto i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i]) && std::isdigit(str[i - 1]) && i != 0) {
            newStr.back().push_back(str[i]);
        } else {
            string st = {str[i]};
            newStr.push_back(st);
        }
    }
    //	for (auto i : newStr) {
    //		cout << i << endl;
    //	}
    return newStr;
}
/**
 * ISP(堆疊內優先權):In Stack Priority
 * ICP(輸入優先權):In Coming Priority
 * ISP>=ICP則將堆疊的運算子pop出來，否則就push到堆疊內。
 */
bool MathQuiz::shouldPush(string curVar, string stackVar) {
    unordered_map<string, short> map = {{"*", 5}, {"/", 5}, {"+", 6}, {"-", 6}};
    if (stackVar == "(" || (map[curVar] < map[stackVar])) return true;
    return false;
}
vector<string> MathQuiz::to_postfix(vector<string> vec) {
    vector<string> result;
    stack<string> stk;
    for (auto c = 0; c < vec.size(); c++) {
        auto i = vec[c];
        if (std::isdigit(i.front())) {
            // operand
            result.push_back(i);
        } else {
            // operator
            if (stk.empty()) {
                stk.push(i);
            } else {
                if (i == "(") {
                    // always push
                    stk.push("(");
                } else if (i == ")") {
                    // pop until meet ")"
                    while (stk.top() != "(") {

                        result.push_back(stk.top());
                        stk.pop();
                    }
                    // pop '('
                    stk.pop();
                } else {
                    // compare priority
                    if (shouldPush(i, stk.top())) {
                        stk.push(i);
                    } else {
                        result.push_back(stk.top());
                        stk.pop();
                        stk.push(i);
                    }
                }
            }
        }
    }

    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    //	for (auto i : result)
    //		cout << i << " ";
    //	cout << endl;
    return result;
}
void MathQuiz::test224() {
    cout << "LeetCode 224	Basic Calculator  15.7% Medium" << endl;
    string str = "(10+(4 +0     *2) -  3 )/( 6+8)";
    //	cout << "result = " << calculate(str) << endl;
    calculate(str);
}

void MathQuiz::test() { test224(); }
