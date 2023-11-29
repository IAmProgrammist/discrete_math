#include "../util.h"

void testRoute(Graph<Edge<IntNode>>* G, std::string graphName, std::vector<int>& route) {
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
    testRoute(G2, "G2", route2);
    testRoute(G2, "G2", route3);
    testRoute(G2, "G2", route4);
    testRoute(G2, "G2", route5);

    return 0;
}