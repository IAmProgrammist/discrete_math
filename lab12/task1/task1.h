#include "../../libs/alg/alg.h"

#include <random>

typedef Node<int> IntNode;

Graph<Edge<IntNode>>* generateRandomGraph(int nodesCount, int edgeCount) {
    auto graph = new AdjacencyMatrixGraph<Edge<IntNode>>();

    for (int i = 1; i <= nodesCount; i++) {
        Node<int> n(i);

        graph->addNode(n);
    }

    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i <= nodesCount; i++) {
        for (int j = i + 1; j <= nodesCount; j++) {
            if (i == j) continue;

            edges.push_back({i, j});
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(edges.begin(), edges.end(), g);

    for (int i = 0; i < edgeCount && i < edges.size(); i++) 
        graph->addEdge({{(*graph)[edges[i].first], 
        (*graph)[edges[i].second]}, false});

    return graph;
}