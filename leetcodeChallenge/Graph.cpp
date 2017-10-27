/*
 * Graph.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: johnny
 */

#include "Graph.hpp"

/**
 * LeetCode 133  Clone Graph 23.8%  Medium
 * Clone an undirected graph. Each node in the graph contains a label and a list
 *of its neighbors.
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label
 *and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as
 *separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a
 *self-cycle.
 *
 * Visually, the graph looks like the following:
 *
 *       1
 *      / \
 *     /   \
 *    0 --- 2
 *         / \
 *         \_/
 */
UNodeInt *Graph::cloneGraph(UNodeInt *node) {
    if (node == nullptr) { return node; }
    // <original node, clone node>
    std::unordered_map<UNodeInt *, UNodeInt *> map;
    auto head = new UNodeInt(node->label);
    map[node] = head;
    queue<UNodeInt *> que;
    que.push(node);
    while (!que.empty()) {

        auto current = que.front();
        que.pop();
        auto n = current->neighbors.size();
        for (auto i = 0; i < n; ++i) {
            auto child = current->neighbors[i];
            if (map.find(child) != map.end()) {
                // find in map
                map[current]->neighbors.push_back(map[child]);
            } else {
                // not found, create new one
                auto cloneChild = new UNodeInt(child->label);
                map[current]->neighbors.push_back(cloneChild);
                // put into map
                map[child] = cloneChild;
                // put into queue
                que.push(child);
            }
        }
    }
    return head;
}
void Graph::test133() { cout << "LeetCode 133  Clone Graph 23.8%  Medium" << endl; }

/**
 * LeetCode 207  Course Schedule  21.4%  Medium
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to
 *first take course 1,
 * which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs,
 * is it possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 *
 * There are a total of 2 courses to take. To take course 1 you should have
 *finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 *
 * There are a total of 2 courses to take. To take course 1 you should have
 *finished course 0,
 *
 * and to take course 0 you should also have finished course 1. So it is
 *impossible.
 * http://www.cnblogs.com/grandyang/p/4484571.html
 */
bool Graph::canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    queue<int> que;
    vector<int> inn(numCourses, 0);
    vector<vector<int>> graph(numCourses, vector<int>(0, 0));

    for (auto i = 0; i < prerequisites.size(); ++i) {
        //	 put in degree count
        inn[prerequisites[i].first]++;
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    for (auto i = 0; i < inn.size(); i++) {
        if (inn[i] == 0) que.push(i);
    }
    for (auto i : graph) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (auto i = 0; i < inn.size(); i++) {
        cout << i << " " << inn[i] << endl;
    }
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        for (auto i : graph[cur]) {
            --inn[i];
            if (inn[i] == 0) { que.push(i); }
        }
    }
    for (auto &i : inn) {
        if (i != 0) return false;
    }
    return true;
}
void Graph::test207() {
    cout << "LeetCode 207  Course Schedule  21.4%  Medium" << endl;

    std::pair<int, int> p1(1, 0);
    std::pair<int, int> p2(2, 0);
    std::pair<int, int> p3(3, 1);
    std::pair<int, int> p4(3, 2);
    //	std::pair<int, int> p5(0, 0);
    //	std::pair<int, int> p1(0, 1);
    vector<pair<int, int>> prerequisites = {p1, p2, p3, p4};

    cout << canFinish(4, prerequisites) << endl;
    //	for (auto &i : prerequisites) {
    //		cout << i.first << " " << i.second << endl;
    //	}
    //	prerequisites.push_back(p1)
}
/**
Prim's algorithm
http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

 Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9
Output:

Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5
*/
void Graph::printPrim(const vector<vector<int>> &graph) {

    vector<int> minPaths(graph.size(), INT_MAX);

    auto comp = [&](pair<int, int> a, pair<int, int> b) {
        return graph[a.first][a.second] > graph[b.first][b.second];
    };

    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp);

    // que.push(std::make_pair(2, 4));
    // que.push(std::make_pair(0, 3));
    // que.push(std::make_pair(0, 1));

    // while(!que.empty()){
    //     auto p = que.top();
    //     que.pop();
    //     cout<<p.first<<" "<<p.second<<" w = "<<graph[p.first][p.second]<<endl;
    // }
    // for(int i=0; i<graph.size(); i++){
    // }
}
void Graph::testPrim() {
    cout << "Prim's Algorithm - get Minimum spanning tree" << endl;

    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0}, //
        {2, 0, 3, 8, 5}, //
        {0, 3, 0, 0, 7}, //
        {6, 8, 0, 0, 9}, //
        {0, 5, 7, 9, 0}, //
    };
    printPrim(graph);
}
void Graph::test() {
    // test133();
    // test207();
    testPrim();
}
