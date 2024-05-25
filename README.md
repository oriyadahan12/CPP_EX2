t"g oriyati0701@gmail.com | 327510616

# SYSTEM PROGRAMMING 2- ASSIGNMENT 2

My code deals with graphs and looking at all kinds of features in the graph.
In this task, we also added a part of redefining operators, the way we were asked to implement them.
We represent the matrix in an adjacency matrix in which the weight of the edges it has with the other vertices is written for each vertex (if it doesn't have a common edge, the matrix has a value of 0).
I built some methods for extracting information and data from the graph we will receive.
And I'll start with an explanation of loading a graph into a matrix:
But before that, I'll explain about the operators I made:

The << operator:
   
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

Here is the explanation about the graph's part:

 The loading-graph function:
 
    /* @brief Initializes the graph with the provided adjacency matrix.
    * 
    * This function initializes the graph's adjacency matrix with the provided matrix.
    * It checks if the matrix is square and throws an invalid_argument exception if not.
    * It also checks if there is any vertex with an edge to itself and throws an exception if found.
    * 
    * @param adjacencyMatrix The adjacency matrix representing the graph.
    * @throw std::invalid_argument If the matrix is not square or if there is a vertex with an edge to itself.
    */
     void ariel::Graph::loadGraph(vector<vector<int>>adjacencyMatrix){}

After loading the graph into our matrix, we can start running the methods.
We will start with simple functions such as printing the graph and finding the number of vertices in the graph.

The print function:

    /*
    * @brief Prints information about the graph.
    * 
    * This function prints the number of vertices and edges in the graph.
    */
       void ariel::Graph::printGraph(){}


 The function that find the number of vertex in the graph:

    /**
        * @brief Returns the number of vertices in the graph.
        * 
        * @return The number of vertices in the graph.
        */
       size_t countVer();

 Now we will continue with the functions with the more complex algorithms that I wrote:

I will start by detailing my privacy functions.

Bellman-Ford function:
Goes through all the edges n-1 times and makes a placement for each edge on the minimum weight that can be reached in it.
The function can work with negative weights and find negative circles in the graph (if they exist).

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
  
Another function we will use later is the DFS function.
This is a deep search function that goes over a vertex and all its children and colors the vertices in several different colors according to their current state (whether we are done with them or not, etc.)

We used this function to find circles in the graph.

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


Similar to the previous function, the DFS-COLORS function also locates the colors, and we will use it to find a bipartite graph.


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

Now we will focus on my public functions:

The first function,IS CONNECTED, checks whether the graph is connected or not.
  
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


A function to find the minimum distance of all vertices from our starting vertex.  

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


The following function checks whether there is a circle in the graph.

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

The following function checks whether the graph is bipartite, that is, whether the vertices in the graph can be divided into two groups of vertices so that there is no edge that passes between two vertices from the same group.


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

The function looks for a negative circle in the graph, in the middle of which is the Belman-Ford algorithm.
    
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


If somehow you got this far, first of all, thank you very much!
And I appreciate you much more now.
So smile, thank God, and have a successful day.
