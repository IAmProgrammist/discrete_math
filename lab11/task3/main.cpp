#include "../../libs/alg/alg.h"

typedef Node<int> IntNode;

Graph<Edge<IntNode>>* constructGraph1() {
    auto G1 = new AdjacencyMatrixGraph<Edge<IntNode>>();

    IntNode N1(1);
    IntNode N2(2);
    IntNode N3(3);
    IntNode N4(4);
    IntNode N5(5);
    IntNode N6(6);
    IntNode N7(7);

    G1->addNode(N1);
    G1->addNode(N2);
    G1->addNode(N3);
    G1->addNode(N4);
    G1->addNode(N5);
    G1->addNode(N6);
    G1->addNode(N7);

    G1->addEdge({{&N1, &N2}, false});
    G1->addEdge({{&N1, &N4}, false});
    G1->addEdge({{&N1, &N5}, false});
    G1->addEdge({{&N1, &N6}, false});
    G1->addEdge({{&N1, &N7}, false});
    G1->addEdge({{&N2, &N3}, false});
    G1->addEdge({{&N2, &N5}, false});
    G1->addEdge({{&N2, &N6}, false});
    G1->addEdge({{&N3, &N4}, false});
    G1->addEdge({{&N6, &N7}, false});

    return G1;
}

Graph<Edge<IntNode>>* constructGraph2() {
    auto G2 = new AdjacencyMatrixGraph<Edge<IntNode>>();

    IntNode N1(1);
    IntNode N2(2);
    IntNode N3(3);
    IntNode N4(4);
    IntNode N5(5);
    IntNode N6(6);
    IntNode N7(7);

    G2->addNode(N1);
    G2->addNode(N2);
    G2->addNode(N3);
    G2->addNode(N4);
    G2->addNode(N5);
    G2->addNode(N6);
    G2->addNode(N7);

    G2->addEdge({{&N7, &N6}, false});
    G2->addEdge({{&N1, &N6}, false});
    G2->addEdge({{&N4, &N1}, false});
    G2->addEdge({{&N4, &N2}, false});
    G2->addEdge({{&N4, &N3}, false});
    G2->addEdge({{&N3, &N6}, false});
    G2->addEdge({{&N5, &N6}, false});
    G2->addEdge({{&N7, &N1}, false});
    G2->addEdge({{&N2, &N1}, false});
    G2->addEdge({{&N2, &N3}, false});
    G2->addEdge({{&N5, &N3}, false});

    return G2;
}

void testRoute(Graph<Edge<IntNode>>* G, std::string graphName, std::vector<int>& route) {
    std::cout << "==================================\n";
    std::cout << "----------------------------------\n\n";
    std::cout << "Testing route {";
    for (int i = 0; i < route.size(); i++) {
        if (i == route.size() - 1) {
            std::cout << route[i];
        } else {
            std::cout << route[i] << ", ";
        }
    }
    std::cout << "} for graph " << graphName << ":\n\n";
    std::vector<IntNode*> nodes;
    for (auto &element : route) {
        nodes.push_back((*G)[element]);
    }

    std::cout << (G->isRoute(nodes) ? "Is route\n" : "Is not route\n");
    std::cout << (G->isChain(nodes) ? "Is chain\n" : "Is not chain\n");
    std::cout << (G->isSimpleChain(nodes) ? "Is simple chain\n" : "Is not simple chain\n");
    std::cout << (G->isCycle(nodes) ? "Is cycle\n" : "Is not cycle\n");
    std::cout << (G->isSimpleCycle(nodes) ? "Is simple cycle\n" : "Is not simple cycle\n\n");
    std::cout << "----------------------------------\n";
    std::cout << "==================================\n\n";
}

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();

    std::vector<int> route1 {2, 3, 4, 1, 7, 6};
    std::vector<int> route2 {4, 1, 6, 7, 1, 2};
    std::vector<int> route3 {1, 4, 3, 2, 1};
    std::vector<int> route4 {1, 2, 4, 3, 2, 1};
    std::vector<int> route5 {2, 4, 1, 7, 6, 1, 2};

    testRoute(G1, "G1", route1);
    testRoute(G1, "G1", route2);
    testRoute(G1, "G1", route3);
    testRoute(G1, "G1", route4);
    testRoute(G1, "G1", route5);

    testRoute(G2, "G2", route1);
    testRoute(G2, "G2", route1);
    testRoute(G2, "G2", route1);
    testRoute(G2, "G2", route1);
    testRoute(G2, "G2", route1);

    return 0;
}