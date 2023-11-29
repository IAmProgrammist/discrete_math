#include "../util.h"

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();

    std::cout << "All routes between pairs in 1 step in G1: " << G1->countAllRoutesBetweenAllNodes(1) << std::endl;
    std::cout << "All routes between pairs in 3 steps in G1: " << G1->countAllRoutesBetweenAllNodes(3) << std::endl;
    std::cout << "All routes between pairs in 2 steps in G2: " << G2->countAllRoutesBetweenAllNodes(2) << std::endl;

    return 0;
}