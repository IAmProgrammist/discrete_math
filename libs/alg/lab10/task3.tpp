template <typename T>
std::vector<std::vector<T>> DominantRelation<T>::getTopologicalSort() {
    std::vector<int> W(this->size, 0);

    for (int x = 0; x < this->size; x++) {
        for (int y = 0; y < this->size; y++) {
            W[y] += this->data[x][y];
        }
    }

    int ind = 0;

    while (true)
    {
        std::vector<int> indices;
        
        // Поиск нулевых элементов и сохранение их индексов
        auto iter = W.begin();
        while ((iter = std::find(iter, W.end(), 0)) != W.end()) {
            indices.push_back(iter - W.begin());

            iter++;
        }

        if (indices.size() == 0) break;

        ind--;
        for (auto index : indices) {
            // Заменяем нулевой элемент 
            W[index] = ind;

            for (int elementIndex = 0; elementIndex < this->data[index].size(); elementIndex++) { 
                auto element = this->data[index][elementIndex];
                W[elementIndex] -= element;
            }
        }
    }

    std::vector<std::vector<T>> levels;
    for (int i = 0; i < this->size; i++) {
        std::vector<T> level;

        for (int j = 0; j < this->size; j++) {
            if (W[j] == -(1 + i)) 
                level.push_back(this->origin[j]);
        }

        if (level.empty()) break;

        levels.push_back(level);
    }
    
    return levels;
}