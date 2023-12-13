#include "../../libs/alg/alg.h"

int main() {
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

    auto a = g.getShortestWayMatrix();

    for (int i = 0; i < g.nodes.size(); i++) {
        for (int j = 0; j < g.nodes.size(); j++) {
            std::cout << (a[i][j].second == -1 ? "-" : std::to_string(a[i][j].first)) << " ";
        }

        std::cout << "\n";
    }
}