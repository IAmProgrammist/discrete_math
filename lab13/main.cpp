#include "../libs/alg/alg.h"

int main() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, int>> g;

    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);

    NamedEdge E1({&N1, &N2}, 1, false);
    NamedEdge E2({&N1, &N3}, 2, false);
    NamedEdge E3({&N2, &N3}, 3, false);
    NamedEdge E4({&N4, &N2}, 4, false);
    NamedEdge E5({&N3, &N5}, 5, false);
    NamedEdge E6({&N4, &N5}, 6, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3, E4, E5, E6};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);
    g.addEdge(E4);
    g.addEdge(E5);
    g.addEdge(E6);

    for (auto& e : getEdgesToDeleteToDivideGraphInThreeLinkedComponents(&g, edges)) {
        std::cout << e.name << " ";
    }

    return 0;
}