//oriyati0701@gmail.com | 327510616
#include "doctest.h"
#include "Algorithms.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 1, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 1, 1, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph5 = {
        {0, 23, 0, 0, 0, 0, 0},
        {-1, 0, 0, 10, 0, 0, 0}, 
        {0, 0, 0, 13, 0, 0, 0}, 
        {0, 123, 12, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 12}, 
        {0, 0, 0, 0, 0, 0, 134}, 
        {0, 0, 0, -13, -1, 11, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph6 = {
        {0, 0, 0, 0, 0, 0, 0},
        {-1, 0, 0, 10, 0, 0, 0}, 
        {0, 0, 0, 13, 0, 0, 0}, 
        {0, 123, 12, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 12}, 
        {0, 0, 0, 0, 0, 0, 134}, 
        {0, 0, 0, -13, -1, 11, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0-->1-->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1 :(there is no path between 0 to 4)");

    vector<vector<int>> graph3 = {
        {0, 3, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, -2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 5}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, -1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 6, 0, 0, 0, 0, 0, 0}, 
        {0, -1, 0, 31, 0, 0, 4, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "0-->1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1-->2-->8-->3");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 5) == "1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1-->2-->8-->3");
    CHECK(ariel::Algorithms::shortestPath(g, 8, 5) == "8-->1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 7) == "-1 :(there is no path between 0 to 7)");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 5) == "-1 :(there is no path between 3 to 5)");
    CHECK(ariel::Algorithms::shortestPath(g, 6, 1) == "-1 :(there is no path between 6 to 1)");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 2, 0, 0, -5, 0, 0, 0}, 
        {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0}, 
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, -1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 6, 10) == "6-->10");
    CHECK(ariel::Algorithms::shortestPath(g, 5, 0) == "5-->9-->0");

    vector<vector<int>>graph5 = {
    {0, 1, 0, 0, 0}, 
    {1, 0, 0, -5, 0}, 
    {0, 1, 0, 0, 0}, 
    {0, -5, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "There is a negative cycle");


    vector<vector<int>>graph6 = {
        {0, -5, 0, 0, 0, 0, 0, 8}, 
        {-5, 0, 7, 3, 7, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 7, 0, 0, 0, 0, 8, 40}, 
        {0, 0, 0, 0, 0, 0, 4, 2}, 
        {0, 0, 0, 0, 8, 4, 0, 5}, 
        {8, 0, 0, 0, 40, 2, 5, 0}, 
    };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "There is a negative cycle");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "There is a negative cycle");

}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");



    vector<vector<int>> gr = {
    {0, 0, 5, 0}, 
    {3, 0, 0, 0}, 
    {0, 7, 0, 1}, 
    {0, 0, 0, 0}, 
    };
    g.loadGraph(gr);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->2-->1-->0");

    vector<vector<int>> gr2 = {
        {0, 0, 5, 0}, 
        {3, 0, 0, 0}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 0} 
    };
    g.loadGraph(gr2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycles");

    vector<vector<int>> gr3= {
        {0, 7}, 
        {7, 0} 
    };
    g.loadGraph(gr3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");



    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "{0 2 } {1 }");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph isn't bipartite");

    vector<vector<int>> graph4 =
    {
        {0, 7, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 7}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 7, 0}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 7, 7, 0, 0} 
    };

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "{0 4 5 } {1 2 3 }");


}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> gg = {
        {0, 7, 0, 0}, 
        {0, 7, 7, 0}, 
        {0, 0, 0, 0}, 
        {0, 7, 7, 0} 

    };
    CHECK_THROWS(g.loadGraph(gg));



}
