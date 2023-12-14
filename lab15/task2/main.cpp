#include "../../libs/alg/alg.h"

template<typename G, typename W>
void printPath( G& graph, W shortestWayMatrix, 
int begin, int end, bool isEnd) {
    if (begin == -1 || end == -1) return;

    if (begin != end)
        printPath(graph, shortestWayMatrix, begin, shortestWayMatrix[begin][end].second, false);

    std::cout << "(" << graph.nodes[end]->name << ")";
    if (!isEnd)
        std::cout << " ----> ";
}

template<typename T>
void analyzeTree(T& g, std::string graphName) {
    std::cout << "Graph " << graphName << ":\n";
    auto shortestWayMatrix = g.getShortestWayMatrix();
    
    for (int i = 0; i < g.nodes.size(); i++) {
        for (int j = i + 1; j < g.nodes.size(); j++) {
            if (j == i) continue;

            // Пути должны существовать
            if (shortestWayMatrix[i][j].second == -1 || shortestWayMatrix[j][i].second == -1) continue;

            // Длина путей должна быть равна
            if (shortestWayMatrix[i][j].first == shortestWayMatrix[j][i].first) continue;

            bool shouldSwap = false;
            if (shortestWayMatrix[i][j].first > shortestWayMatrix[j][i].first)  {
                shouldSwap = true;
                std::swap(i, j);
            }
        
            std::cout << "Found shortest paths with weight of " << shortestWayMatrix[i][j].first << ":\n";
            printPath(g, shortestWayMatrix, i, j, true);
            std::cout << "\n";
            printPath(g, shortestWayMatrix, j, i, true);
            std::cout << "\n" << std::endl;

            if (shouldSwap) {
                std::swap(i, j);
            }        
        }
    }
}

// Венок
void testWreath() {
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

    g.addEdge({{&N1, &N3}, 1, true});
    g.addEdge({{&N3, &N4}, 1, true});
    g.addEdge({{&N4, &N5}, 1, true});
    g.addEdge({{&N5, &N2}, 1, true});
    g.addEdge({{&N2, &N1}, 4, true});

    analyzeTree(g, "Wreath");
}

// Цепочка
void testChain() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);

    g.addEdge({{&N1, &N2}, 1, true});
    g.addEdge({{&N2, &N1}, 1, true});
    g.addEdge({{&N3, &N2}, 1, true});
    g.addEdge({{&N2, &N3}, 1, true});
    g.addEdge({{&N3, &N4}, 1, true});
    g.addEdge({{&N4, &N3}, 1, true});
    analyzeTree(g, "Chain");
}

// Сложная цепочка
void testHardChain() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, unsigned long long>> g;

    Node<int> N1(1);
    Node<int> N2(2);
    Node<int> N3(3);
    Node<int> N4(4);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);

    g.addEdge({{&N1, &N2}, 2, true});
    g.addEdge({{&N2, &N1}, 3, true});
    g.addEdge({{&N3, &N2}, 1, true});
    g.addEdge({{&N2, &N3}, 4, true});
    g.addEdge({{&N3, &N4}, 1, true});
    g.addEdge({{&N4, &N3}, 3, true});
    analyzeTree(g, "Hard chain");
}

// Кит
void testWhale() {
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

    g.addEdge({{&N5, &N4}, 2, true});
    g.addEdge({{&N4, &N5}, 2, true});
    g.addEdge({{&N4, &N3}, 2, true});
    g.addEdge({{&N3, &N2}, 2, true});
    g.addEdge({{&N2, &N1}, 2, true});
    g.addEdge({{&N1, &N6}, 4, true});
    g.addEdge({{&N6, &N4}, 2, true});
    analyzeTree(g, "Whale");
}

void test() {
    testWreath();
    testChain();
    testHardChain();
    testWhale();
}

int main() {
    test();
}