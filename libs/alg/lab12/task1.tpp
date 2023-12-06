#include "../lab11/graph.tpp"

template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::isHamiltonian() {
    if (this->nodes.size() < 3) return false;
    // От теоремы Оре и Диррака пришось отказаться, так как мы можем 
    // получить ориентированный граф, теоремы расчитаны только для 
    // неориентированных графов.
    std::vector<bool> cache(this->nodes.size(), false);

    return hasHamiltonianCycle(0, 0, cache);
}

template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::hasHamiltonianCycle(int originIndex, int startIndex, std::vector<bool>& takenNodes) {
    takenNodes[startIndex] = true;

    bool anyElementFound = false;
    for (int i = 0; i < this->nodes.size(); i++) {
        if (takenNodes[i] || this->edges[startIndex][i] == nullptr) continue;

        anyElementFound = true;
        
        if (hasHamiltonianCycle(originIndex, i, takenNodes)) return true;
    }

    if (!anyElementFound) {
        if (this->edges[startIndex][originIndex] == nullptr) {
            takenNodes[startIndex] = false;

            return false;
        }

        for (auto takenFlag : takenNodes) 
            if (!takenFlag) {
                takenNodes[startIndex] = false;

                return false;
            }

        return true;
    }

    takenNodes[startIndex] = false;
    return false;
}

// Для данной задачи метод был упрощён в угоду скорости выполнения, 
// мы игнорируем наличие мультиграфов, орграфов.
// TODO: Переделать перед использованием!
template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::isEuler() {
    if (this->nodes.size() < 3) return false;

    

    return false;
}