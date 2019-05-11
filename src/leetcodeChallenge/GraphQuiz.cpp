//
// Created by Yihung Lee on 2019-04-30.
//

#include "GraphQuiz.hpp"
#include <unordered_map>
#include <queue>
#include <utility>
#include <unordered_set>
#include <set>

string GraphQuiz::alienOrder(vector<string> &words) {
    set<pair<char, char>> st;
    unordered_set<char> ch;
    vector<int> in(256, 0);
    queue<char> q;
    string res = "";
    for (auto a : words) ch.insert(a.begin(), a.end());
    for (int i = 0; i < (int) words.size() - 1; ++i) {
        int mn = min(words[i].size(), words[i + 1].size()), j = 0;
        for (; j < min(words[i].size(), words[i + 1].size()); ++j) {
            if (words[i][j] != words[i + 1][j]) {
                st.insert(make_pair(words[i][j], words[i + 1][j]));
                break;
            }
        }
        if (j == mn && words[i].size() > words[i + 1].size()) return "";
    }
    for (auto a : st) {
        ++in[a.second];
    }
    for (auto a : ch) {
        if (in[a] == 0) {
            q.push(a);
        }
    }
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        res += c;
        for (auto a : st) {
            if (a.first == c) {
                --in[a.second];
                if (in[a.second] == 0) {
                    q.push(a.second);
                }
            }
        }
    }
    return res.size() == ch.size() ? res : "";
}


/**
 * http://www.cnblogs.com/grandyang/p/4484571.html
 */
bool GraphQuiz::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);
    for (auto &i : prerequisites) {
        graph[i[1]].push_back(i[0]);
        in[i[0]]++;
    }
    queue<int> que;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int front = que.front();
        que.pop();
        for (auto &i : graph[front]) {
            if (--in[i] == 0) {
                que.push(i);
            }
        }
    }
    for (auto &i:in) {
        if (i != 0) return false;
    }
    return true;
}

vector<int> GraphQuiz::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);
    for (auto &i : prerequisites) {
        graph[i[1]].push_back(i[0]);
        in[i[0]]++;
    }
    queue<int> que;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0) {
            que.push(i);
        }
    }

    vector<int> res;
    while (!que.empty()) {
        int front = que.front();
        que.pop();
        res.push_back(front);
        for (auto &i : graph[front]) {
            if (--in[i] == 0) {
                que.push(i);
            }
        }
    }
    if (res.size() != numCourses) res.clear();
    return res;
}

int GraphQuiz::scheduleCourse(vector<vector<int>> &courses) {
    std::sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    int curTime = 0;
    priority_queue<int> q;
    for (auto course : courses) {
        curTime += course[0];
        q.push(course[0]);
        if (curTime > course[1]) {
            curTime -= q.top();
            q.pop();
        }
    }
    return q.size();
}