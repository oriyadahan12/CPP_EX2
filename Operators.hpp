/*327510616 | oriyati0701@gmail.com*/

#include "Graph.hpp"

#include <ostream>

#include <ostream>

namespace ariel {

    class Graph;

    /** 
     * Outputs the graph to the provided output stream.
     */
    std::ostream& operator<<(std::ostream& os, const Graph& graph);

    /**
     * Unary minus operator for Graph.
     * Defines the negation of a graph.
     */
    Graph operator-(const Graph& graph);

    /**
      Unary plus operator for Graph.
     * Defines a unary plus operation for a graph.
     */
    Graph operator+(const Graph& graph);

    /**
     *Binary subtraction operator for Graph. 
     * Subtracts one graph from another.
     */
    Graph operator-(const Graph& g1, const Graph& g2);

    /**
     *Binary multiplication operator for Graph.
     * Multiplies two graphs together.
     */
    Graph operator*(const Graph& g1, const Graph& g2);

    /**
     *Binary addition operator for Graph.
     * Adds two graphs together.
     */
    Graph operator+(const Graph& g1, const Graph& g2);

    /**
     * Multiplies a graph by another graph and assigns the result to the first graph.
     */
    Graph& operator*=(Graph& g1, const Graph& g2);

    /**
     * Adds a graph to another graph and assigns the result to the first graph.
     */
    Graph& operator+=(Graph& g1, const Graph& g2);

    /**
     * Subtracts a graph from another graph and assigns the result to the first graph.
     */
    Graph& operator-=(Graph& g1, const Graph& g2);

    /**
     * Subtracts a scalar value from all elements of the graph and assigns the result to the graph.
     */
    Graph& operator-=(Graph& g1, int scalar);

    /**
     * Adds a scalar value to all elements of the graph and assigns the result to the graph.
     */
    Graph& operator+=(Graph& g1, int scalar);

    /**
     * Multiplies all elements of the graph by a scalar value and assigns the result to the graph.
     */
    Graph& operator*=(Graph& g1, int scalar);

    /**
     * Divides all elements of the graph by a scalar value and assigns the result to the graph.
     */
    Graph& operator/=(Graph& g1, int scalar);

    /**
     * Binary addition operator for Graph with scalar.
     * Adds a scalar value to all elements of the graph.
     */
    Graph operator+(const Graph& g1, int scalar);

    /**
     * Multiplies all elements of the graph by a scalar value.
     */
    Graph operator*(const Graph& g1, int scalar);

    /**
     * Subtracts a scalar value from all elements of the graph.
     */
    Graph operator-(const Graph& g1, int scalar);

    /**
     * Divides all elements of the graph by a scalar value.
     */
    Graph operator/(const Graph& g1, int scalar);

    /**
     * Greater than comparison operator for Graph.
     * Compares two graphs.
     */
    bool operator>(const Graph& g1, const Graph& g2);

    /**
     * Less than comparison operator for Graph.
     * Compares two graphs.
     */
    bool operator<(const Graph& g1, const Graph& g2);

    /**
     * Less than or equal to comparison operator for Graph.
     */
    bool operator<=(const Graph& g1, const Graph& g2);

    /**
     * Greater than or equal to comparison operator for Graph.
     */
    bool operator>=(const Graph& g1, const Graph& g2);

    /**
     * Equality comparison operator for Graph.
     */
    bool operator==(const Graph& g1, const Graph& g2);

    /**
     * Inequality comparison operator for Graph.
     */
    bool operator!=(const Graph& g1, const Graph& g2);

    /**
     * Pre-increment operator for Graph.
     * Increments the graph.
     */
    Graph& operator++(Graph& graph);

    /**
     * Post-increment operator for Graph.
     * Increments the graph
     */
    Graph operator++(Graph& graph, int);

    /**
     * Pre-decrement operator for Graph.
     * Decrements the graph.
     */
    Graph& operator--(Graph& graph);

    /**
     * Post-decrement operator for Graph.
     * Decrements the graph.
     */
    Graph operator--(Graph& graph, int);

}
