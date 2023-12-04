#include "../lab11/graph.tpp"

template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::isHamiltonian() {
    if (this->nodes.size() < 3) return false;
    // От теоремы Оре и Диррака пришось отказаться, так как мы можем 
    // получить ориентированный граф, теоремы расчитаны только для 
    // неориентированных графов.
    std::vector<bool> cache(this->nodes.size(), false);

    for (int i = 0; i < this->nodes.size(); i++)
        if (hasHamiltonianCycle(i, i, cache)) return true;

    return false;
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

    int edgeCount = 0;
    for (int i = 0; i < this->nodes.size(); i++) 
        for (int j = 0; j < this->nodes.size(); j++) 
            if (this->edges[i][j] != nullptr) edgeCount++;

    for (int i = 0; i < this->nodes.size(); i++) {
        std::vector<std::vector<bool>> empty(this->nodes.size(), 
        std::vector<bool>(this->nodes.size(), false));
        if (hasEulerCycle(i, i, empty, 0, edgeCount)) return true;
    }

    return false;
}

// Для данной задачи метод был упрощён в угоду скорости выполнения, 
// мы игнорируем наличие мультиграфов, орграфов.
// TODO: Переделать перед использованием!
template <typename E, typename N>
bool AdjacencyMatrixGraph<E, N>::hasEulerCycle(int originIndex, int startIndex, 
std::vector<std::vector<bool>>& visited, int visitedSize, int totalEdgesCount) {
    if (visitedSize == totalEdgesCount && originIndex == startIndex) return true;
    if (visitedSize > totalEdgesCount) return false;

    for (int i = 0; i < this->nodes.size(); i++) {
        if (this->edges[startIndex][i] == nullptr) continue;
        if (visited[startIndex][i]) continue;

        visited[startIndex][i] = true;
        visited[i][startIndex] = this->edges[i][startIndex] != nullptr;

        if (hasEulerCycle(originIndex, i, visited, visitedSize + 1 + (this->edges[i][startIndex] != nullptr), totalEdgesCount)) return true;

        visited[startIndex][i] = false;
        visited[i][startIndex] = false;
    }

    return false;
}