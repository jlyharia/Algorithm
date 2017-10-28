/*
 * Graph.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: johnny
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include "ChallengeBase.hpp"
#include "UndirectedGraphNode.hpp"
#include <utility>
using UNodeInt = UndirectedGraphNode<int>;

class Graph : public ChallengeBase {
  public:
    Graph() {}
    void test() override;

    ~Graph() {}

  private:
    // LeetCode 133  Clone Graph 23.8%  Medium
    UNodeInt *cloneGraph(UNodeInt *node);
    void test133();

    // LeetCode 134  Gas Station 25.7%  Medium

    // LeetCode 207  Course Schedule  21.4%  Medium
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites);
    void test207();

    /** Shortest Path Algorithm */
    // Prim's Minimum Spanning Tree
    void printPrim(const vector<vector<int>> &graph);
    void testPrim();

    // Disjkstra's shortest path
    void printDijkstra(vector<vector<int>> graph);

    // Bellman-Ford
    // Kruskal's algorithm Minimum Spanning Tree
};

#endif /* GRAPH_HPP_ */
