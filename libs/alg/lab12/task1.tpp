#include "../lab11/graph.tpp"

template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::isHamiltonian() {
    return true;
}

template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::isEuler() {
    return true;
}