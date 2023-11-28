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
    G1->addEdge({{&N1, &N7}, false});
    G1->addEdge({{&N7, &N2}, false});
    G1->addEdge({{&N6, &N2}, false});
    G1->addEdge({{&N7, &N6}, false});
    G1->addEdge({{&N6, &N3}, false});
    G1->addEdge({{&N6, &N5}, false});
    G1->addEdge({{&N3, &N5}, false});
    G1->addEdge({{&N3, &N4}, false});
    G1->addEdge({{&N4, &N5}, false});

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

    G2->addEdge({{&N1, &N2}, false});

    return G2;
}

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
}