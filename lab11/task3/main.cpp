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

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();

    std::cout << "G1 props:\n";
    std::cout << "Is route?:\n";
    std::cout << G1->isRoute({(*G1)[2], (*G1)[3], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6]}) << std::endl;
    std::cout << G1->isRoute({(*G1)[4], (*G1)[1], (*G1)[6], (*G1)[7], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << G1->isRoute({(*G1)[1], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isRoute({(*G1)[1], (*G1)[2], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isRoute({(*G1)[2], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << "Is chain?:\n";
    std::cout << G1->isChain({(*G1)[2], (*G1)[3], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6]}) << std::endl;
    std::cout << G1->isChain({(*G1)[4], (*G1)[1], (*G1)[6], (*G1)[7], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << G1->isChain({(*G1)[1], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isChain({(*G1)[1], (*G1)[2], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isChain({(*G1)[2], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << "Is simple chain?:\n";
    std::cout << G1->isSimpleChain({(*G1)[2], (*G1)[3], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6]}) << std::endl;
    std::cout << G1->isSimpleChain({(*G1)[4], (*G1)[1], (*G1)[6], (*G1)[7], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << G1->isSimpleChain({(*G1)[1], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isSimpleChain({(*G1)[1], (*G1)[2], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isSimpleChain({(*G1)[2], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << "Is cycle?:\n";
    std::cout << G1->isCycle({(*G1)[2], (*G1)[3], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6]}) << std::endl;
    std::cout << G1->isCycle({(*G1)[4], (*G1)[1], (*G1)[6], (*G1)[7], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << G1->isCycle({(*G1)[1], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isCycle({(*G1)[1], (*G1)[2], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isCycle({(*G1)[2], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << "Is simple cycle?:\n";
    std::cout << G1->isSimpleCycle({(*G1)[2], (*G1)[3], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6]}) << std::endl;
    std::cout << G1->isSimpleCycle({(*G1)[4], (*G1)[1], (*G1)[6], (*G1)[7], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << G1->isSimpleCycle({(*G1)[1], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isSimpleCycle({(*G1)[1], (*G1)[2], (*G1)[4], (*G1)[3], (*G1)[2], (*G1)[1]}) << std::endl;
    std::cout << G1->isSimpleCycle({(*G1)[2], (*G1)[4], (*G1)[1], (*G1)[7], (*G1)[6], (*G1)[1], (*G1)[2]}) << std::endl;
    std::cout << "\n\n";

    

    std::cout << "G2 props:\n";
    std::cout << "Is route?:\n";
    std::cout << G2->isRoute({(*G2)[2], (*G2)[3], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6]}) << std::endl;
    std::cout << G2->isRoute({(*G2)[4], (*G2)[1], (*G2)[6], (*G2)[7], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << G2->isRoute({(*G2)[1], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isRoute({(*G2)[1], (*G2)[2], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isRoute({(*G2)[2], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << "Is chain?:\n";
    std::cout << G2->isChain({(*G2)[2], (*G2)[3], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6]}) << std::endl;
    std::cout << G2->isChain({(*G2)[4], (*G2)[1], (*G2)[6], (*G2)[7], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << G2->isChain({(*G2)[1], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isChain({(*G2)[1], (*G2)[2], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isChain({(*G2)[2], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << "Is simple chain?:\n";
    std::cout << G2->isSimpleChain({(*G2)[2], (*G2)[3], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6]}) << std::endl;
    std::cout << G2->isSimpleChain({(*G2)[4], (*G2)[1], (*G2)[6], (*G2)[7], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << G2->isSimpleChain({(*G2)[1], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isSimpleChain({(*G2)[1], (*G2)[2], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isSimpleChain({(*G2)[2], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << "Is cycle?:\n";
    std::cout << G2->isCycle({(*G2)[2], (*G2)[3], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6]}) << std::endl;
    std::cout << G2->isCycle({(*G2)[4], (*G2)[1], (*G2)[6], (*G2)[7], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << G2->isCycle({(*G2)[1], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isCycle({(*G2)[1], (*G2)[2], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isCycle({(*G2)[2], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << "Is simple cycle?:\n";
    std::cout << G2->isSimpleCycle({(*G2)[2], (*G2)[3], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6]}) << std::endl;
    std::cout << G2->isSimpleCycle({(*G2)[4], (*G2)[1], (*G2)[6], (*G2)[7], (*G2)[1], (*G2)[2]}) << std::endl;
    std::cout << G2->isSimpleCycle({(*G2)[1], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isSimpleCycle({(*G2)[1], (*G2)[2], (*G2)[4], (*G2)[3], (*G2)[2], (*G2)[1]}) << std::endl;
    std::cout << G2->isSimpleCycle({(*G2)[2], (*G2)[4], (*G2)[1], (*G2)[7], (*G2)[6], (*G2)[1], (*G2)[2]}) << std::endl;

    return 0;
}