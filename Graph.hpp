/**
 * //oriyati0701@gmail.com | 327510616
 * @file Graph.hpp
 * @brief Header file containing declarations of the Graph class.
 */


#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Operators.hpp"

namespace ariel {

/**
 * @class Graph
 * @brief A class representing a graph using an adjacency matrix.
 */
class Graph {
private:
    std::vector<std::vector<int>> Matrix; /**< The adjacency matrix representing the graph. */

public:
    /**
     * @brief Loads the graph from an adjacency matrix.
     * 
     * This function initializes the graph's adjacency matrix with the provided matrix.
     * 
     * @param adjacencyMatrix The adjacency matrix representing the graph.
     */
    void loadGraph(std::vector<std::vector<int>> adjacencyMatrix);

    /**
     * @brief Prints the graph's adjacency matrix.
     * 
     * This function prints the adjacency matrix of the graph to the standard output.
     */
    std::string printGraph()const;

    /**
     * @brief Returns the number of vertices in the graph.
     * 
     * @return The number of vertices in the graph.
     */
    size_t countVer()const;

    /**
     * @brief Gets the weight of the edge between two vertices.
     * 
     * This function returns the weight of the edge between vertices 'u' and 'v' in the graph.
     * 
     * @param u The index of the source vertex.
     * @param v The index of the destination vertex.
     * @return The weight of the edge between vertices 'u' and 'v'.
     */
    int getWeight(size_t u, size_t v)const;

    int getNumEdges()const;
};

} 

#endif /* GRAPH_HPP_ */
