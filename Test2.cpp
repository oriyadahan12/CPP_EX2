//327510616 | oriyati0701@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;
using namespace ariel;


// Test unary operator+
TEST_CASE("UnaryPlusOperator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph result = +g1;
    CHECK(result.countVer() == g1.countVer());
}

// Test unary operator-
TEST_CASE("UnaryMinusOperator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph result = -g1;

    CHECK(result.getWeight(0, 1) == -1);
}

// Test binary operator+ for graph addition
TEST_CASE("BinaryPlusOperator") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    ariel::Graph result = g1 + g2;

    CHECK(result.getWeight(0, 0) == 0);
    CHECK(result.getWeight(0, 1) == 2);
    CHECK(result.getWeight(1, 1) == 0);
    CHECK(result.getWeight(2, 2) == 0);
}

// Test binary operator+ with invalid dimensions
TEST_CASE("BinaryPlusOperatorInvalidDimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {2, 4, 5, 0}
    };
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 + g2);
}

// Test binary operator- for graph subtraction
TEST_CASE("BinaryMinusOperator") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    ariel::Graph result = g1 - g2;

    CHECK(result.getWeight(0, 1) == 2);
    CHECK(result.getWeight(1, 1) == 0);
    CHECK(result.getWeight(2, 2) == 0);
}

// Test binary operator- with invalid dimensions
TEST_CASE("BinaryMinusOperatorInvalidDimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 2, 3, 0}
    };
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 - g2);
}

// Test binary operator* for graph multiplication
TEST_CASE("BinaryMultiplyOperator") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    ariel::Graph result = g1 * g2;

    CHECK(result.getWeight(0, 1) == 0);
     CHECK(result.printGraph() == "[0,0,2]\n[2,0,2]\n[2,0,0]\n");
    CHECK(result.getWeight(1, 1) == 0);
    CHECK(result.getWeight(2, 2) == 0);
}

// Test binary operator* with invalid dimensions
TEST_CASE("BinaryMultiplyOperatorInvalidDimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 3, 4, 0}
    };
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 * g2);
}

TEST_CASE("Invalid operations") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 3, 4, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g5;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g5.loadGraph(graph2);

    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g6.loadGraph(graph3);

    CHECK_THROWS(g1 + g6);
}

// Test operator+=
TEST_CASE("OperatorPlusEqual") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    g1 += g2;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 2);
    CHECK(g1.getWeight(1, 1) == 0);
    CHECK(g1.getWeight(2, 2) == 0);
}

// Test operator-=
TEST_CASE("OperatorMinusEqual") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    g1 -= g2;

    CHECK(g1.getWeight(0, 1) == 2);
    CHECK(g1.getWeight(1, 1) == 0);
    CHECK(g1.getWeight(2, 2) == 0);
}

// Test operator*=
TEST_CASE("OperatorMultiplyEqual") {
    ariel::Graph g1;
    ariel::Graph g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    g1 *= g2;

    CHECK(g1.getWeight(0, 1) == 0);
    CHECK(g1.getWeight(1, 1) == 0);
    CHECK(g1.getWeight(2, 2) == 0);
    CHECK(g1.printGraph() == "[0,0,2]\n[2,0,2]\n[2,0,0]\n");
}

// Test operator+ with scalar
TEST_CASE("OperatorPlusScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);

    ariel::Graph result = g1 + 5;

    CHECK(result.getWeight(0, 0) == 0);
    CHECK(result.getWeight(0, 1) == 6);
    CHECK(result.getWeight(1, 0) == 6);
    CHECK(result.getWeight(1, 1) == 0);
}

// Test operator- with scalar
TEST_CASE("OperatorMinusScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);

    ariel::Graph result = g1 - 1;

    CHECK(result.getWeight(0, 0) ==0);
    CHECK(result.getWeight(0, 1) == 0);
    CHECK(result.getWeight(1, 0) == 0);
    CHECK(result.getWeight(1, 1) == 0);
}

// Test operator* with scalar
TEST_CASE("OperatorMultiplyScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);

    ariel::Graph result = g1 * 2;

    CHECK(result.getWeight(0, 0) == 0);
    CHECK(result.getWeight(0, 1) == 2);
    CHECK(result.getWeight(1, 0) == 2);
    CHECK(result.getWeight(1, 1) == 0);
}

// Test operator/ with scalar
TEST_CASE("OperatorDivideScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };

    g1.loadGraph(g1Weights);

    ariel::Graph result = g1 / 2;

    CHECK(result.getWeight(0, 0) == 0);
    CHECK(result.getWeight(0, 1) == 1);
    CHECK(result.getWeight(1, 0) == 1);
    CHECK(result.getWeight(1, 1) == 0);
}

// Test operator+= with scalar
TEST_CASE("OperatorPlusEqualScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g1 += 2;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 3);
    CHECK(g1.getWeight(1, 0) == 3);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test operator-= with scalar
TEST_CASE("OperatorMinusEqualScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g1 -= 1;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 0);
    CHECK(g1.getWeight(1, 0) == 0);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test operator*= with scalar
TEST_CASE("OperatorMultiplyEqualScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g1 *= 2;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 2);
    CHECK(g1.getWeight(1, 0) == 2);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test operator/= with scalar
TEST_CASE("OperatorDivideEqualScalar") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };

    g1.loadGraph(g1Weights);
    g1 /= 2;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 1);
    CHECK(g1.getWeight(1, 0) == 1);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test operator++ (prefix)
TEST_CASE("OperatorPrefixIncrement") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    ++g1;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 2);
    CHECK(g1.getWeight(1, 0) == 2);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test operator++ (postfix)
TEST_CASE("OperatorPostfixIncrement") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    ariel::Graph g2 = g1++;
    ariel::Graph g3 = g1;

    CHECK(g2.getWeight(0, 0) == 0);
    CHECK(g2.getWeight(0, 1) == 1);
    CHECK(g2.getWeight(1, 0) == 1);
    CHECK(g2.getWeight(1, 1) == 0);

    CHECK(g3.getWeight(0, 0) == 0);
    CHECK(g3.getWeight(0, 1) == 2);
    CHECK(g3.getWeight(1, 0) == 2);
    CHECK(g3.getWeight(1, 1) == 0);
}

// Test operator-- (prefix)
TEST_CASE("OperatorPrefixDecrement") {
    ariel::Graph g1;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    --g1;

    CHECK(g1.getWeight(0, 0) == 0);
    CHECK(g1.getWeight(0, 1) == 0);
    CHECK(g1.getWeight(1, 0) == 0);
    CHECK(g1.getWeight(1, 1) == 0);
}

// Test < operator
TEST_CASE("LessThanOperator") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    CHECK((g1 < g2) == false);
}

// Test operator> (greater than)
TEST_CASE("OperatorGreaterThan") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    CHECK((g1 > g2) == false);
    CHECK((g2 > g1) == false);
}

// Test operator<= (less than or equal)
TEST_CASE("OperatorLessThanOrEqual") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    CHECK((g1 <= g2) == true);
    CHECK((g2 <= g1) == true);
}

// Test operator>= (greater than or equal)
TEST_CASE("OperatorGreaterThanOrEqual") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    CHECK((g1 >= g2) == true);
    CHECK((g2 >= g1) == true);
}

// Test operator== (equal)
TEST_CASE("OperatorEqual") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);

    CHECK((g1 == g2) == true);

    std::vector<std::vector<int>> g3Weights = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    ariel::Graph g3;
    g3.loadGraph(g3Weights);

    CHECK((g1 == g3) == false);
}

// Test operator!= (not equal)
TEST_CASE("OperatorNotEqual") {
    ariel::Graph g1, g2;

    std::vector<std::vector<int>> g1Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> g2Weights = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    g1.loadGraph(g1Weights);
    g2.loadGraph(g2Weights);  
}

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0,2,1]\n[2,0,3]\n[1,3,0]\n");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0,0,2]\n[1,0,1]\n[1,0,0]\n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {2, 4, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
        };
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}


