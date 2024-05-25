//oriyati0701@gmail.com | 327510616
#include "Algorithms.hpp"
#include <string>

using namespace std;
using namespace ariel;


void Algorithms::bellmanFord(Graph g, size_t start, vector<int> &d, vector<int> &pi)
{
    // Initialize the distance from the start vertex to itself as 0.
    d[start] = 0;
    
    // Iterate over all vertices - 1 times.
    for (int i = 0; i < g.countVer() - 1; i++)
    {
        // Iterate over all edges.
        for (size_t j = 0; j < g.countVer(); j++)
        {
            for (size_t k = 0; k < g.countVer(); k++)
            {
                // Relax edges if shorter path found.
                if (g.getWeight(j, k) != 0 && d[j] != INT32_MAX && d[k] > d[j] + g.getWeight(j, k))
                {
                    d[k] = d[j] + g.getWeight(j, k);
                    pi[k] = j;
                }
            }
        }
    }

    // Check for negative cycles.
    for (size_t i = 0; i < g.countVer(); i++)
    {
        for (size_t j = 0; j < g.countVer(); j++)
        {
            // If a shorter path exists after all iterations, it indicates a negative cycle.
            if (g.getWeight(i, j) != 0 && d[i] != INT32_MAX && (d[j] > d[i] + g.getWeight(i, j) || d[i] == INT32_MIN))
            {
                // Set the distance to negative infinity to indicate the presence of a negative cycle.
                d[j] = INT32_MIN;
                // Update the predecessor to indicate the vertex involved in the cycle.
                pi[j] = i;
            }
        }
    }
}

bool Algorithms::isConnected(Graph g)
{
    // Iterate over each vertex in the graph.
    for (size_t s = 0; s < g.countVer(); s++)
    {
        // Initialize vectors to store distances and predecessors for the Bellman-Ford algorithm.
        vector<int> d(g.countVer(), INT32_MAX);
        vector<int> pi(g.countVer(), -1);
        
        // Apply Bellman-Ford algorithm from the current vertex.
        bellmanFord(g, s, d, pi);
        
        // Check if any vertex is unreachable from the current vertex.
        for (size_t i = 0; i < g.countVer(); i++)
        {
            if (d[i] == INT32_MAX)
                return false; // If any vertex is unreachable, the graph is disconnected.
        }
    }
    // If all vertices are reachable from each other, the graph is connected.
    return true;
}



string Algorithms::shortestPath(Graph g, size_t start, size_t end)
{
    string str = ""; 
    
    str += std::to_string(end); // Append the destination vertex to the path.

    // Initialize vectors to store distances and predecessors for the Bellman-Ford algorithm.
    vector<int> d(g.countVer(), INT32_MAX);
    std::vector<int> pi(g.countVer(), -1);
    
    // Apply Bellman-Ford algorithm to find shortest paths from the starting vertex.
    bellmanFord(g, start, d, pi);
    
    // Check if there is a negative cycle in the graph.
    if (d[end] == INT32_MIN) {
        return "There is a negative cycle"; // If there is a negative cycle, return an appropriate message.
    }
    
    // If there is no path from the starting vertex to the destination vertex, return a message.
    if (pi[end] == -1)
    {
        str = std::to_string(-1) + " :(there is no path between " + std::to_string(start) + " to " + std::to_string(end) + ")";
        return str;
    }
    
    int t = (int)end; 

    // Backtrack through the predecessors to construct the shortest path.
    while (t != start)
    {
        str = std::to_string(pi[(size_t)t]) + "-->" + str; // Append the predecessor to the path.
        t = pi[(size_t)t]; // Move to the predecessor.
    }

    return str; // Return the shortest path.
}



string Algorithms::isContainsCycle(Graph g)
{
    string str = "No cycles"; // Initialize the result string assuming no cycles are found.
    
    // Initialize vectors to store colors and predecessors for DFS.
    vector<int> colors(g.countVer(), 0); // Colors: white (0), gray (1), black (2)
    vector<size_t> pi(g.countVer(), SIZE_MAX); //Parent
    
    // Perform DFS from each vertex to check for cycles.
    for (size_t i = 0; i < g.countVer(); i++)
    {
        // If the vertex has not been visited yet, perform DFS from it.
        if (colors[i] == 0)
        { 
            size_t s = DFS_VISIT(g, i, pi, colors); // Perform DFS visit from vertex i.

            // If a cycle is found during DFS visit, construct a string representing the cycle.
            if (s != SIZE_MAX)
            {
                str = std::to_string(s); // Initialize the string with the start of the cycle.

                size_t parent = pi[s]; 

                while (parent != s)
                {
                    str = std::to_string(parent) + "-->" + str; // Append the vertex to the cycle string.
                    parent = pi[parent]; 
                }

                str = std::to_string(s) + "-->" + str; 
                
                // Return a message indicating the cycle found in the graph.
                return "The cycle is:" + str;
            }
        }
    }   
    
    // Return the result string indicating that no cycles were found in the graph.
    return str;
}



size_t Algorithms::DFS_VISIT(Graph g, size_t u, vector<size_t> &pi, vector<int> &colors)
{
    colors[u] = 1; // Mark the current vertex as visited (gray).
    
    // Loop through the adjacent vertices of vertex u.
    for (size_t j = 0; j < g.countVer(); j++)
    {
        // If there's no edge between u and j, continue to the next adjacent vertex.
        if (g.getWeight(u, j) == 0)
        {
            continue;
        }

        // If the adjacent vertex j has not been visited yet, recursively visit it.
        if (colors[j] == 0)
        {
            pi[j] = u; // Set the parent of j as u.
            
            // Recursively visit vertex j.
            size_t res = DFS_VISIT(g, j, pi, colors);
            
            // If a cycle is detected in the subtree rooted at vertex j, return the starting vertex of the cycle.
            if (res != SIZE_MAX)
            {
                return res;
            }
        }

        // If the adjacent vertex j is already visited (gray) and it's not the parent of u (to avoid visiting the parent itself), 
        // then a cycle is detected and return the starting vertex of the cycle.
        else if (colors[j] == 1 && j != u)
        {
            pi[j] = u; 
            return j; // Return the starting vertex of the cycle.
        }
    }
    
    colors[u] = 2; // Mark the current vertex as finished (black).
    return SIZE_MAX; // No cycle detected in the subtree rooted at vertex u, return SIZE_MAX.
}


string Algorithms::isBipartite(Graph g)
{
    // Initialize a vector to store colors of vertices during DFS (white:0, pink:1, blue:2).
    vector<int> colors(g.countVer(), 0);

    // Iterate over each vertex in the graph.
    for(size_t i = 0; i < g.countVer(); i++)
    {
        // If the current vertex is already colored, skip to the next vertex.
        if(colors[i] != 0)
        {
            continue;
        }

        // Iterate over each adjacent vertex of the current vertex.
        for(size_t j = 0; j < g.countVer(); j++)
        {
            // If the adjacent vertex j is already colored and there's an edge between i and j, determine the color of vertex i.
            if(colors[j] != 0 && (g.getWeight(i,j) != 0 || g.getWeight(j,i) != 0 ) && i != j)
            {
                colors[i] = 3 - colors[j]; // Assign a color to vertex i that's different from the color of vertex j.
                break;
            }
        }
        
        // If vertex i is not yet colored, assign it the color pink (1).
        if(colors[i] == 0)
        {
            colors[i] = 1;
        }

        // Perform DFS to check if the graph remains bipartite after coloring vertex i.
        bool b = DFS_colors(g, i, colors);
        
        // If the graph is not bipartite after coloring vertex i, return a message indicating so.
        if(!b){
            return "The graph isn't bipartite";
        }
    }

    // If the graph is bipartite, construct strings representing the two sets of vertices (s1 and s2) in the bipartition.
    string s1 = "{";
    string s2 = "{";

    // Iterate over each vertex and categorize them into s1 or s2 based on their colors.
    for(size_t i = 0; i < g.countVer(); i++)
    {
        if(colors[i] == 1)
        {
            s1 += std::to_string(i) + " "; 
        }
        else{
            s2 += std::to_string(i) + " "; 
        }
    }    
    
    s1 += "}"; 
    s2 += "}"; 

    // Return a string representing the bipartition of the graph.
    return s1 +" "+ s2;
}



bool Algorithms::DFS_colors(Graph g, size_t u, vector<int> &colors)
{
    // Iterate over each adjacent vertex of the current vertex u.
    for (size_t j = 0; j < g.countVer(); j++)
    {
        // If there is no edge between vertex u and vertex j, skip to the next adjacent vertex.
        if (g.getWeight(u, j) == 0)
        {
            continue;
        }

        // If vertex j is not yet colored, assign it a color different from vertex u and perform DFS on it.
        if (colors[j] == 0)
        {
            colors[j] = 3 - colors[u]; // Assign a color to vertex j that's different from the color of vertex u.
            bool res = DFS_colors(g, j, colors); // Recursively perform DFS on vertex j.
            if (!res) // If DFS returns false, indicating that the graph is not bipartite, return false.
            {
                return res;
            }
        }

        // If vertex j has the same color as vertex u and they are not the same vertex, return false (graph is not bipartite).
        else if (colors[j] == colors[u] && j != u)
        {
            return false;
        }
    }
    
    // If DFS completes without detecting a violation of bipartiteness, return true (graph is bipartite).
    return true;
}


string Algorithms::negativeCycle(Graph g)
{
    string str = "There isn't a negative cycle"; // Initialize the result string assuming no negative cycle is found.
    vector<size_t> points; // Initialize a vector to store the vertices that form a potential negative cycle.

    
    for (size_t s = 0; s < g.countVer(); s++)
    {
        vector<int> d(g.countVer(), INT32_MAX); // Initialize a vector to store the shortest distances from the source vertex s.
        vector<int> pi(g.countVer(), -1); // Initialize a vector to store the predecessor vertices in the shortest path tree.

        bellmanFord(g, s, d, pi); // Apply the Bellman-Ford algorithm to find shortest paths from vertex s.

        // Check if there is a negative distance from vertex s to itself, indicating the presence of a negative cycle.
        if (d[s] < 0)
        {
            str = ""; 
            points.push_back(s); // Add the source vertex s to the list of potential negative cycle vertices.

            // Iterate over the vertices in the potential negative cycle.
            for (size_t t = 0; t < points.size(); t++)
            {
                // Check if the parent of vertex s in the shortest path is one of the potential negative cycle vertices.
                if (pi[s] == points[t])
                {
                    // If a cycle is detected, construct a string representing the vertices forming the cycle.
                    for (size_t k = 1; k < points.size(); k++)
                    {
                        str += std::to_string(points[k]) + ", "; // Append the vertex to the result string.
                    }
                    str += std::to_string(points[0]); // Append the starting vertex to complete the cycle.
                    return str; // Return the string representing the negative cycle.
                }
                else
                {
                    points.push_back(t); // Add the parent vertex to the list of potential negative cycle vertices.
                }
            }
        }
    }

    return str; // Return the result string indicating no negative cycle was found.
}
