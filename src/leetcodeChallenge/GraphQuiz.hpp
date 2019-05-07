//
// Created by Yihung Lee on 2019-04-30.
//

#ifndef ALGORITHM_GRAPHQUIZ_HPP
#define ALGORITHM_GRAPHQUIZ_HPP

#include <Utils.hpp>
#include <string>

using namespace std;

class GraphQuiz {
public:

    // 207. Course Schedule
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites);

    // 210. Course Schedule II
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites);

    // 269. Alien Dictionary
    string alienOrder(vector<string> &words);


};


#endif //ALGORITHM_GRAPHQUIZ_HPP
