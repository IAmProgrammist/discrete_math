#include "../libs/alg/alg.h"

int main() {
    AdjacencyMatrixGraph<Edge<Node<int>>> G1;
    std::cout << G1.isHamiltonian();

    return 0;
}