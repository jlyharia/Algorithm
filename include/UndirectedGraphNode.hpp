/*
 * UndirectedGraphNode.hpp
 *
 *  Created on: Jun 16, 2015
 *      Author: johnny
 */

#ifndef UNDIRECTEDGRAPHNODE_HPP_
#define UNDIRECTEDGRAPHNODE_HPP_
#include <vector>
template <typename T> struct UndirectedGraphNode {
    T label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(T x) : label(x) {}
};

#endif /* UNDIRECTEDGRAPHNODE_HPP_ */
