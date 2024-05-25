//oriyati0701@gmail.com | 327510616
#include "Graph.hpp"

 
using namespace std;
    
/* @brief Initializes the graph with the provided adjacency matrix.
 * 
 * This function initializes the graph's adjacency matrix with the provided matrix.
 * It checks if the matrix is square and throws an invalid_argument exception if not.
 * It also checks if there is any vertex with an edge to itself and throws an exception if found.
 * 
 * @param adjacencyMatrix The adjacency matrix representing the graph.
 * @throw std::invalid_argument If the matrix is not square or if there is a vertex with an edge to itself.
 */

   void ariel::Graph::loadGraph(vector<vector<int>>adjacencyMatrix) {
        
        Matrix.resize(adjacencyMatrix.size());
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            if(adjacencyMatrix[i].size() != adjacencyMatrix.size())
                {
                    throw invalid_argument("The matrix isn't a squre");
                }
            Matrix[i].resize(adjacencyMatrix[i].size());
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {

                Matrix[i][j] = adjacencyMatrix[i][j];
            }
        }

        for(size_t j = 0; j < adjacencyMatrix.size(); j++)
        {
            if(adjacencyMatrix[j][j] != 0)
            {
                throw invalid_argument("There is a vertex with an edge to himself");
            }
        }
    }


/*
 * @brief Prints information about the graph.
 * 
 * This function prints the number of vertices and edges in the graph.
 */

    string ariel::Graph::printGraph()const
    {
        int count = 0;
        string str = "";
        for(size_t i = 0; i < Matrix.size(); ++i){
            str += "[";
            for(size_t j = 0; j < Matrix[i].size()-1; ++j)
            {
                str.append(std::to_string(Matrix[i][j])+",");
            }
            
            str.append(std::to_string(Matrix[i][Matrix[i].size()-1]));
            str += "]\n";
        }

        return str;
    }

/**
 * @brief Returns the number of vertices in the graph.
 * 
 * @return The number of vertices in the graph.
 */
        size_t ariel::Graph::countVer()const{
            return Matrix.size();
        }


/**
 * @brief Gets the weight of the edge between two vertices.
 * 
 * This function returns the weight of the edge between vertices 'u' and 'v' in the graph.
 * 
 * @param u The index of the source vertex.
 * @param v The index of the destination vertex.
 * @return The weight of the edge between vertices 'u' and 'v'.
 */
        int ariel::Graph::getWeight(size_t u, size_t v)const{
            return Matrix[u][v];
        }


int ariel::Graph::getNumEdges()const
{
    int num=0;
    for(size_t i = 0; i<Matrix.size(); i++)
    {
        for(size_t j = 0; j<Matrix.size(); j++)
        {
            if(Matrix[i][j] != 0)
            {num++;}
        }
    }
    return num;
}