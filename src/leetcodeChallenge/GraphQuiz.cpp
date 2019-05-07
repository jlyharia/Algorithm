//
// Created by Yihung Lee on 2019-04-30.
//

#include "GraphQuiz.hpp"
#include <unordered_map>
#include <queue>

string GraphQuiz::alienOrder(vector<string> &words) {

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