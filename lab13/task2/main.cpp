#include "../../libs/alg/alg.h"

template <typename E>
void testGraph(std::string graphName, Graph<E>* g, std::vector<E> edges) {
    auto res = getEdgesToDeleteToDivideGraphInNLinkedComponents(g, edges, 3);
    assert(res.first.trees != nullptr);

    // Проверка на наличие 3 связных компонентов
    assert(res.first.bouquets.size() == 3);
    std::cout << "Edges to delete in graph \"" << graphName << "\": ";

    // Удаление границ из графа
    for (auto& edge : res.second) {
        g->deleteEdge(edge);
        std::cout << edge.name << " ";
    }

    std::cout << std::endl;

    std::set<Node<int>*> bNodes;

    // Проверка на то, что вершины из разных букетов не будут иметь цепь в обновлённом графе
    // А из одного букета - будут. 
    for (int i = 0; i < res.first.bouquets.size(); i++)
        for (auto &nodeA : res.first.bouquets[i]) {
            bNodes.insert(nodeA);

            for (int j = 0; j < res.first.bouquets.size(); j++)      
                for (auto &nodeB : res.first.bouquets[j]) {
                    if (i == j) assert(g->isChainBetweenNodesExist(nodeA, nodeB));
                    else assert(!g->isChainBetweenNodesExist(nodeA, nodeB));
                }
        }

    // Проверка на то, что в букетах содержатся все вершины
    assert(bNodes.size() == g->getNodesSize());

    delete res.first.trees;
}

void testThreeNodes() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, int>> g;

    Node N1(1);
    Node N2(2);
    Node N3(3);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);

    NamedEdge E1({&N1, &N2}, 1, false);
    NamedEdge E2({&N1, &N3}, 2, false);
    NamedEdge E3({&N2, &N3}, 3, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);

    testGraph("Three points", &g, edges);
}

void testFigureHome() {
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

    testGraph("Home", &g, edges);
}

void testFull5() {
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
    NamedEdge E3({&N1, &N4}, 3, false);
    NamedEdge E4({&N1, &N5}, 4, false);
    NamedEdge E5({&N2, &N3}, 5, false);
    NamedEdge E6({&N2, &N4}, 6, false);
    NamedEdge E7({&N2, &N5}, 7, false);
    NamedEdge E8({&N3, &N4}, 8, false);
    NamedEdge E9({&N3, &N5}, 9, false);
    NamedEdge E10({&N4, &N5}, 10, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3, E4, E5, E6, E7, E8, E9, E10};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);
    g.addEdge(E4);
    g.addEdge(E5);
    g.addEdge(E6);
    g.addEdge(E7);
    g.addEdge(E8);
    g.addEdge(E9);
    g.addEdge(E10);

    testGraph("Full with 5 nodes", &g, edges);
}

void testFull6() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, int>> g;

    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);
    Node N6(6);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);

    NamedEdge E1({&N1, &N2}, 1, false);
    NamedEdge E2({&N1, &N3}, 2, false);
    NamedEdge E3({&N1, &N4}, 3, false);
    NamedEdge E4({&N1, &N5}, 4, false);
    NamedEdge E5({&N1, &N6}, 5, false);
    NamedEdge E6({&N2, &N3}, 6, false);
    NamedEdge E7({&N2, &N4}, 7, false);
    NamedEdge E8({&N2, &N5}, 8, false);
    NamedEdge E9({&N2, &N6}, 9, false);
    NamedEdge E10({&N3, &N4}, 10, false);
    NamedEdge E11({&N3, &N5}, 11, false);
    NamedEdge E12({&N3, &N6}, 12, false);
    NamedEdge E13({&N4, &N5}, 13, false);
    NamedEdge E14({&N4, &N6}, 14, false);
    NamedEdge E15({&N5, &N6}, 15, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);
    g.addEdge(E4);
    g.addEdge(E5);
    g.addEdge(E6);
    g.addEdge(E7);
    g.addEdge(E8);
    g.addEdge(E9);
    g.addEdge(E10);
    g.addEdge(E11);
    g.addEdge(E12);
    g.addEdge(E13);
    g.addEdge(E14);
    g.addEdge(E15);

    testGraph("Full with 6 nodes", &g, edges);
}

void testThreeTriangles() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, int>> g;

    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);
    Node N6(6);
    Node N7(7);
    Node N8(8);
    Node N9(9);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);
    g.addNode(N7);
    g.addNode(N8);
    g.addNode(N9);

    NamedEdge E1({&N1, &N2}, 1, false);
    NamedEdge E2({&N1, &N3}, 2, false);
    NamedEdge E3({&N2, &N3}, 3, false);
    NamedEdge E4({&N2, &N4}, 4, false);
    NamedEdge E5({&N4, &N5}, 5, false);
    NamedEdge E6({&N4, &N6}, 6, false);
    NamedEdge E7({&N6, &N5}, 7, false);
    NamedEdge E8({&N6, &N7}, 8, false);
    NamedEdge E9({&N8, &N7}, 9, false);
    NamedEdge E10({&N7, &N9}, 10, false);
    NamedEdge E11({&N8, &N9}, 11, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);
    g.addEdge(E4);
    g.addEdge(E5);
    g.addEdge(E6);
    g.addEdge(E7);
    g.addEdge(E8);
    g.addEdge(E9);
    g.addEdge(E10);
    g.addEdge(E11);

    testGraph("Three triangles", &g, edges);
}

void testThreeTrianglesStronglyLinked() {
    AdjacencyMatrixGraph<NamedEdge<Node<int>, int>> g;

    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);
    Node N6(6);
    Node N7(7);
    Node N8(8);
    Node N9(9);

    g.addNode(N1);
    g.addNode(N2);
    g.addNode(N3);
    g.addNode(N4);
    g.addNode(N5);
    g.addNode(N6);
    g.addNode(N7);
    g.addNode(N8);
    g.addNode(N9);

    NamedEdge E1({&N1, &N2}, 1, false);
    NamedEdge E2({&N1, &N3}, 2, false);
    NamedEdge E3({&N2, &N3}, 3, false);
    NamedEdge E4({&N2, &N4}, 4, false);
    NamedEdge E5({&N4, &N5}, 5, false);
    NamedEdge E6({&N4, &N6}, 6, false);
    NamedEdge E7({&N6, &N5}, 7, false);
    NamedEdge E8({&N6, &N7}, 8, false);
    NamedEdge E9({&N8, &N7}, 9, false);
    NamedEdge E10({&N7, &N9}, 10, false);
    NamedEdge E11({&N8, &N9}, 11, false);
    NamedEdge E12({&N4, &N7}, 12, false);
    NamedEdge E13({&N2, &N7}, 13, false);
    NamedEdge E14({&N3, &N7}, 14, false);
    NamedEdge E15({&N3, &N6}, 15, false);
    std::vector<NamedEdge<Node<int>, int>> edges = {E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15};

    g.addEdge(E1);
    g.addEdge(E2);
    g.addEdge(E3);
    g.addEdge(E4);
    g.addEdge(E5);
    g.addEdge(E6);
    g.addEdge(E7);
    g.addEdge(E8);
    g.addEdge(E9);
    g.addEdge(E10);
    g.addEdge(E11);
    g.addEdge(E12);
    g.addEdge(E13);
    g.addEdge(E14);
    g.addEdge(E15);

    testGraph("Three triangles strongly linked", &g, edges);
}

void test() {
    testThreeNodes();
    testFigureHome();
    testFull5();
    testFull6();
    testThreeTriangles();
    testThreeTrianglesStronglyLinked();
}

int main() {
    test();

    return 0;
}