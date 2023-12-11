#include "../../libs/alg/alg.h"

#include <map>

template<typename N, typename EV>
void printPath( ShortestWayTree<N, EV> shortestWayTree, 
int index, bool isEnd) {
    if (index != shortestWayTree.rootNodeIndex)
        printPath(shortestWayTree, shortestWayTree.prevNodesIndices[index], false);

    std::cout << "(" << shortestWayTree.nodes[index].name << ")";
    if (!isEnd)
        std::cout << " ----> ";
}

template<typename T, typename N>
bool analyzeTree(N* start, T& g, std::string graphName) {
    std::map<typename T::EdgeValueType, std::pair<int, ShortestWayTree<N, typename T::EdgeValueType>>> results;
    
    for (int i = 0; i < g.nodes.size(); i++) {
        if (start->equals(*g.nodes[i])) continue;
        auto res = g.getShortestWay(start, g.nodes[i]);

        if (res.distances[i] == std::numeric_limits<unsigned long long>::max()) continue;
        if (results.find(res.distances[i]) == results.end()) {
            results[res.distances[i]] = {i, res};
            continue;
        }

        std::cout << "Found shortest paths with weight of " << res.distances[i] << " in graph '" << graphName << "':\n";
        printPath(results[res.distances[i]].second, results[res.distances[i]].first, true);
        std::cout << "\n";
        printPath(res, i, true);
        std::cout << "\n" << std::endl;

        return true;
    }

    std::cout << "No shortest paths with same weight in graph '" << graphName << "':\n" << std::endl;
    return false;
}

bool testTree1(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<std::string>, unsigned long long>> g;

    Node<std::string> N1("v1");
    Node<std::string> N2("v2");
    Node<std::string> N3("v3");
    Node<std::string> N4("v4");
    Node<std::string> N5("v5");
    Node<std::string> N6("v6");

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);

    g.addEdge({{&N1, &N2}, 1, true});
    g.addEdge({{&N1, &N3}, 9, true});
    g.addEdge({{&N2, &N3}, 7, true});
    g.addEdge({{&N2, &N4}, 2, true});
    g.addEdge({{&N4, &N3}, 2, true});
    g.addEdge({{&N3, &N5}, 1, true});
    g.addEdge({{&N4, &N5}, 8, true});
    g.addEdge({{&N4, &N6}, 2, true});
    g.addEdge({{&N5, &N6}, 5, true});
    g.addEdge({{&N6, &N5}, 4, true});

    return analyzeTree(&N1, g, graphName);
}

bool testTree2(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<std::string>, unsigned long long>> g;

    Node<std::string> N1("v1");
    Node<std::string> N2("v2");
    Node<std::string> N3("v3");
    Node<std::string> N4("v4");
    Node<std::string> N5("v5");
    Node<std::string> N6("v6");

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);

    g.addEdge({{&N1, &N2}, 1, true});
    g.addEdge({{&N1, &N3}, 9, true});
    g.addEdge({{&N2, &N3}, 7, true});
    g.addEdge({{&N2, &N4}, 2, true});
    g.addEdge({{&N4, &N3}, 4, true});
    g.addEdge({{&N3, &N5}, 1, true});
    g.addEdge({{&N4, &N5}, 8, true});
    g.addEdge({{&N4, &N6}, 2, true});
    g.addEdge({{&N5, &N6}, 5, true});
    g.addEdge({{&N6, &N5}, 4, true});

    return analyzeTree(&N1, g, graphName);
}

bool testTree3(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);
    Node<int> N5(5);
    Node<int> N6(6);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);

    g.addEdge({{&N1, &N2}, 1, true});
    g.addEdge({{&N2, &N5}, 1, true});
    g.addEdge({{&N5, &N6}, 1, true});
    g.addEdge({{&N6, &N3}, 1, true});
    g.addEdge({{&N1, &N4}, 4, true});

    return analyzeTree(&N1, g, graphName);
}

bool testTree4(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);
    Node<int> N5(5);
    Node<int> N6(6);
    Node<int> N7(7);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);
    g.addNode(N7);

    g.addEdge({{&N1, &N2}, 1, true});
    g.addEdge({{&N2, &N5}, 1, true});
    g.addEdge({{&N5, &N6}, 1, true});
    g.addEdge({{&N6, &N3}, 1, true});
    g.addEdge({{&N1, &N4}, 4, true});
    g.addEdge({{&N7, &N3}, 4, true});

    return analyzeTree(&N7, g, graphName);
}

bool testTree5(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);
    Node<int> N5(5);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);

    g.addEdge({{&N1, &N4}, 3, true});
    g.addEdge({{&N4, &N2}, 1, true});
    g.addEdge({{&N2, &N3}, 3, true});
    g.addEdge({{&N2, &N5}, 7, true});
    g.addEdge({{&N3, &N5}, 1, true});
    g.addEdge({{&N1, &N5}, 8, true});

    return analyzeTree(&N1, g, graphName);
}

bool testTree6(std::string graphName) {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);
    Node<int> N5(5);
    Node<int> N6(6);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);

    g.addEdge({{&N1, &N4}, 3, true});
    g.addEdge({{&N4, &N2}, 1, true});
    g.addEdge({{&N2, &N3}, 3, true});
    g.addEdge({{&N2, &N5}, 7, true});
    g.addEdge({{&N3, &N5}, 1, true});
    g.addEdge({{&N1, &N5}, 8, true});
    g.addEdge({{&N2, &N6}, 4, true});

    return analyzeTree(&N1, g, graphName);
}

void test() {
    assert(testTree1("Graph 1"));
    assert(!testTree2("Graph 2"));
    assert(testTree3("Graph 3"));
    assert(!testTree4("Graph 4"));
    assert(!testTree5("Graph 5"));
    assert(testTree6("Graph 6"));
}

int main() {
    test();
}