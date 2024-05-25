//327510616 | oriyati0701@gmail.com
#include "Operators.hpp"
#include "Graph.hpp"

using namespace std;
using ariel::Graph;
using std::ostream;


// ostream << Graph
std::ostream& ariel::operator<<(std::ostream& os, const Graph& graph)
{
    os<<graph.printGraph();
    return os;
}


// -Graph
Graph ariel::operator-(const Graph& graph)
{

return graph*(-1);
    
}

// +Graph
Graph ariel::operator+(const Graph& graph)
{
    return graph;

}

 // Graph + Graph
Graph ariel::operator+(const Graph& g1, const Graph& g2) {
    if (g1.countVer() != g2.countVer()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph end;
    size_t size = g1.countVer();
    std::vector<std::vector<int>> g3(size, std::vector<int>(size));

    for(size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            g3[i][j] = g1.getWeight(i, j) + g2.getWeight(i, j);
        }
    }

    end.loadGraph(g3);
    return end;
}

// Graph * Graph
Graph ariel::operator*(const Graph& g1, const Graph& g2)
{
     if (g1.countVer() != g2.countVer()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph end;
    size_t size = g1.countVer();
    std::vector<std::vector<int>> g3(size, std::vector<int>(size));

    for(size_t i = 0; i < size; i++) {

        for (size_t j = 0; j < size; j++) {
            size_t k = 0;
            while(k<size)
            {
                g3[i][j] += g1.getWeight(i,k)*g2.getWeight(k,j);
                k++;
            }
        }
    }

    for (size_t i = 0; i < size; i++) {
        g3[i][i] = 0;
    }

    end.loadGraph(g3);
    return end;
}

// Graph - Graph
Graph ariel::operator-(const Graph& g1,const Graph& g2)
{
     if (g1.countVer() != g2.countVer()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph end;
    size_t size = g1.countVer();
    std::vector<std::vector<int>> g3(size, std::vector<int>(size));

    for(size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            g3[i][j] = g1.getWeight(i, j) - g2.getWeight(i, j);
        }
    }

    end.loadGraph(g3);
    return end;
}

// Graph += Graph
Graph& ariel::operator+=(Graph& g1, const Graph& g2){
    g1 = g1 + g2;
    return g1;
    
}

// Graph *= Graph
Graph& ariel::operator*=(Graph& g1, const Graph& g2){
    g1 = g1*g2;
    return g1;
}

// Graph -= Graph
Graph& ariel::operator-=(Graph& g1, const Graph& g2){
    g1 = g1-g2;
    return g1;
}

// Graph + int
Graph ariel::operator+(const Graph& g1, int scalar){
    Graph end;
    std::vector<std::vector<int>> g3(g1.countVer(), std::vector<int>(g1.countVer()));

    for(size_t i = 0; i < g1.countVer(); i++)
    {
        for(size_t j = 0; j<g1.countVer(); j++)
        {
            if(g1.getWeight(i,j) != 0){
            g3[i][j] = g1.getWeight(i,j) + scalar;}
        }
    }

    end.loadGraph(g3);
    return end;
}

 // Graph * int
Graph ariel::operator*(const Graph& g1, int scalar)
{
      Graph end;
    std::vector<std::vector<int>> g3(g1.countVer(), std::vector<int>(g1.countVer()));


    for(size_t i = 0; i < g1.countVer(); i++)
    {
        for(size_t j = 0; j<g1.countVer(); j++)
        {
            g3[i][j] = g1.getWeight(i,j) * scalar;
        }
    }
    end.loadGraph(g3);
    return end;
}

 // Graph - int
Graph ariel::operator-(const Graph& g1, int scalar){
      Graph end;
    std::vector<std::vector<int>> g3(g1.countVer(), std::vector<int>(g1.countVer()));


    for(size_t i = 0; i < g1.countVer(); i++)
    {
        for(size_t j = 0; j<g1.countVer(); j++)
        {
           if(g1.getWeight(i,j) != 0){
            g3[i][j] = g1.getWeight(i,j) - scalar;}
        }
    }
    end.loadGraph(g3);
    return end;
}

// Graph / int
Graph ariel::operator/(const Graph& g1, int scalar)
{
      Graph end;
    std::vector<std::vector<int>> g3(g1.countVer(), std::vector<int>(g1.countVer()));


    for(size_t i = 0; i < g1.countVer(); i++)
    {
        for(size_t j = 0; j<g1.countVer(); j++)
        {
          if(g1.getWeight(i,j) != 0){
            g3[i][j] = g1.getWeight(i,j) / scalar;}
        }
    }
    end.loadGraph(g3);
    return end;
}

// Graph -= int
Graph& ariel::operator-=(Graph& g1, int scalar){
    g1 = g1 - scalar;
    return g1;
}

// Graph *= int
Graph& ariel::operator*=(Graph& g1, int scalar){
    g1 = g1 * scalar;
    return g1;
}

// Graph += int
Graph& ariel::operator+=(Graph& g1, int scalar)
{
 g1 = g1 + scalar;
 return g1;
}

// Graph /= int
Graph& ariel::operator/=(Graph& g1, int scalar){
    g1 = g1 / scalar;
    return g1;
}

// Graph++
Graph& ariel::operator++(Graph& graph) {
    graph = graph + 1;
    return graph;
}

// Graph--
Graph& ariel::operator--(Graph& graph){

     graph -= 1;
     return graph;

}

 // --Graph
Graph ariel::operator--(Graph& graph, int)
{
     graph -= 1;
     return graph+1;
}

// ++Graph
Graph ariel::operator++(Graph& graph, int)
{
    graph += 1;
    return graph-1;
}

static bool isContains(const Graph& g1, const Graph& r,size_t row, size_t col)
{
 for(size_t i = row; i< g1.countVer(); i++)
 {
    for(size_t j = col; j<g1.countVer(); j++)
    {
        if(g1.getWeight(i,j) != r.getWeight(i,j))
        {return false;}
    }
 }   
 return true;
}

// Graph < Graph
 bool ariel::operator<(const Graph& g1, const Graph& g2)
{
    size_t index_r,index_col=0;
    if(g1.countVer()<g2.countVer()){
    for(size_t i = index_r; i < g2.countVer(); i++)
    {
        for(size_t j =index_col; j<g2.countVer();j++)
        {
            if(g1.getWeight(i,j) == g2.getWeight(i,j))
            {
                index_r = i;
                index_col= j;
                return isContains(g1,g2,index_r,index_col);
            }
        }
    }
    }
    if(g1.getNumEdges() < g2.getNumEdges())
    {
        return true;
    }
   
    return (g1.countVer()<g2.countVer());

}

 // Graph > Graph
bool ariel::operator>(const Graph& g1, const Graph& g2){
    
    return operator<(g2,g1);

}

 // Graph <= Graph
bool ariel::operator<=(const Graph& g1, const Graph& g2)
{
     return (g1<g2)||(g1==g2);
}
// Graph >= Graph
bool ariel::operator>=(const Graph& g1, const Graph& g2)
{
    return (g1>g2)||(g1==g2);
}
// Graph == Graph
bool ariel::operator==(const Graph& g1, const Graph& g2)
{
     if (g1.countVer() != g2.countVer()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }


    for(size_t i = 0; i < g1.countVer(); i++) {
        for (size_t j = 0; j < g1.countVer(); j++) {
            if(g1.getWeight(i,j) != g2.getWeight(i,j))
            {
                return false;
            }
        }
    }
    return true;
}
// Graph != Graph
bool ariel::operator!=(const Graph& g1, const Graph& g2)
{
    return !(g1==g2);
   
}