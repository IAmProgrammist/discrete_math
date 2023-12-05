#include "../lab11/graph.tpp"

template <typename E, typename N>
Graph<E>* AdjacencyMatrixGraph<E, N>::clone() {
    AdjacencyMatrixGraph<E, N>* g = new AdjacencyMatrixGraph<E, N>();
    
    std::set<EdgeContainer*> obtained;
    for (int i = 0; i < this->nodes.size(); i++) {
        g->addNode(*this->nodes[i]);
    }

    for (int i = 0; i < this->nodes.size(); i++) {
        for (int j = 0; j < this->nodes.size(); j++) {
            if (this->edges[i][j] == nullptr) continue;

            for (auto &edgeContainer : *this->edges[i][j]) {
                if (obtained.find(edgeContainer) != obtained.end()) continue;

                obtained.insert(edgeContainer);
                if (edgeContainer->linked != nullptr) 
                    obtained.insert(edgeContainer->linked);

                g->addEdge(edgeContainer->current);
            }
        }
    }

    return g;
}

template <typename E, typename N>
Forest<E, N> AdjacencyMatrixGraph<E, N>::getSpanningForest() {
    AdjacencyMatrixGraph<E> *trees = new AdjacencyMatrixGraph<E>();
    std::vector<std::set<int>> bouquets(this->nodes.size());
    for (int i = 0; i < this->nodes.size(); i++) {
        bouquets[i].insert(i);
        trees->addNode(*this->nodes[i]);
    }

    for (int i = 0; i < this->nodes.size(); i++) {
        for (int j = 0; j < this->nodes.size(); j++) {
            // Ребра между i и j нет, пропускаем.
            if (this->edges[i][j] == nullptr) continue;

            int indBI = -1;
            int indBJ = -1;

            for (int bIndex = 0; bIndex < bouquets.size() && (indBI == -1 || indBJ == -1); bIndex++) {
                if (bouquets[bIndex].find(i) != bouquets[bIndex].end()) indBI = bIndex;
                if (bouquets[bIndex].find(j) != bouquets[bIndex].end()) indBJ = bIndex;
            }

            // Обе концевые вершины принадлежат одному букету, ребро не добавляем.
            if (indBI == indBJ) continue;

            // Концевые вершины принадлежат разным букетам, поэтому нужно их объединить в один.
            bouquets[indBI].insert(bouquets[indBJ].begin(), bouquets[indBJ].end());
            bouquets[indBJ].clear();

            for (auto& edge : *this->edges[i][j])
                trees->addEdge((*edge).current);
        }
    }

    Forest<E, N> result;
    result.trees = trees;
    for (int i = 0; i < this->nodes.size(); i++) {
        auto& bouquet = bouquets[i];

        if (!bouquet.empty()) {
            std::set<N*> rBouquet;

            for (auto& elementIndex : bouquet) {
                rBouquet.insert(trees->nodes[elementIndex]);
            }

            result.bouquets.push_back(rBouquet);
        }
    }

    return result;
}