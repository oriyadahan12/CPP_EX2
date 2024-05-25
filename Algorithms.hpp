/**
 * //oriyati0701@gmail.com | 327510616
 * @file Algorithms.hpp
 * @brief Header file containing declarations of the Algorithms class.
 
 */

#ifndef ALGORITHMS_HPP_
#define ALGORITHMS_HPP_

#include <iostream>
#include <stdexcept>
#include <limits>
#include "Graph.hpp"

namespace ariel {

/**
 * @class Algorithms
 * @brief A class containing implementations of various graph algorithms.
 */
class Algorithms {
private:
    /**
     * @brief Applies the Bellman-Ford algorithm to find the shortest paths from a given start vertex.
     * 
     * This function computes shortest paths from the start vertex to all other vertices in the graph using the Bellman-Ford algorithm.
     * It updates the input vectors 'd' and 'pi' to store the shortest distances and predecessors respectively.
     * 
     * @param g The graph on which to perform the algorithm.
     * @param start The index of the starting vertex.
     * @param d Vector to store the distances from the start vertex to each other vertex.
     * @param pi Vector to store the predecessors of each vertex in the shortest paths.
     */
    static void bellmanFord(Graph g, size_t start, std::vector<int>& d, std::vector<int>& pi);

    /**
     * @brief Performs Depth First Search (DFS) visit on the graph to detect cycles.
     * 
     * This function performs a DFS traversal on the graph to detect cycles.
     * It returns the index of the first vertex encountered in the cycle, or SIZE_MAX if no cycle is found.
     * 
     * @param g The graph to perform DFS on.
     * @param u The index of the current vertex being visited.
     * @param pi Vector to store the predecessors of each vertex during DFS.
     * @param colors Vector representing colors of vertices during DFS.
     * @return Index of the first vertex encountered in the cycle, or SIZE_MAX if no cycle found.
     */
    static size_t DFS_VISIT(Graph g, size_t u, std::vector<size_t>& pi, std::vector<int>& colors);

    /**
     * @brief Performs Depth First Search (DFS) to check if the graph is bipartite and assigns colors to vertices.
     * 
     * This function performs a DFS traversal on the graph to check if it is bipartite.
     * It assigns colors to vertices and checks if adjacent vertices have different colors.
     * 
     * @param g The graph to perform DFS on.
     * @param u The index of the current vertex being visited.
     * @param colors Vector representing colors of vertices during DFS.
     * @return True if the graph is bipartite, false otherwise.
     */
    static bool DFS_colors(Graph g, size_t u, std::vector<int>& colors);

public:
    /**
     * @brief Checks if the given graph is connected.
     * 
     * This function determines if the graph is connected by performing a BFS traversal from each vertex.
     * If any vertex cannot be reached from another, the graph is considered disconnected.
     * 
     * @param g The graph to check.
     * @return True if the graph is connected, false otherwise.
     */
    static bool isConnected(Graph g);

    /**
     * @brief Finds the shortest path between two vertices in the graph using the Bellman-Ford algorithm.
     * 
     * This function computes the shortest path between two vertices using the Bellman-Ford algorithm.
     * It returns a string representation of the shortest path from the start vertex to the end vertex.
     * 
     * @param g The graph on which to find the shortest path.
     * @param start The index of the starting vertex.
     * @param end The index of the destination vertex.
     * @return A string representing the shortest path from start to end vertex.
     */
    static std::string shortestPath(Graph g, size_t start, size_t end);

    /**
     * @brief Checks if the given graph contains a cycle.
     * 
     * This function detects cycles in the graph using Depth First Search (DFS).
     * If a cycle is found, it returns a string representing the cycle; otherwise, it returns "No cycles".
     * 
     * @param g The graph to check.
     * @return A string describing the cycle if found, otherwise "No cycles".
     */
    static std::string isContainsCycle(Graph g);

    /**
     * @brief Checks if the given graph is bipartite.
     * 
     * This function checks if the graph is bipartite by assigning colors to vertices using Depth First Search (DFS).
     * If the graph is bipartite, it returns a string representing the bipartition; otherwise, it returns "The graph isn't bipartite".
     * 
     * @param g The graph to check.
     * @return A string describing the bipartition if the graph is bipartite, otherwise "The graph isn't bipartite".
     */
    static std::string isBipartite(Graph g);
    
    /**
     * @brief Finds a negative cycle in the graph if it exists.
     * 
     * This function searches for a negative cycle in the graph using the Bellman-Ford algorithm.
     * If a negative cycle is found, it returns a string representing the vertices forming the cycle; otherwise, it returns "There isn't a negative cycle".
     * 
     * @param g The graph to search for a negative cycle.
     * @return A string describing the vertices forming the negative cycle if found, otherwise "There isn't a negative cycle".
     */
    static std::string negativeCycle(Graph g);
};

} // namespace ariel

#endif /* ALGORITHMS_HPP_ */
