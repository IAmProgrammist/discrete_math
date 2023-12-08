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
    std::vector<int> bouquet(this->nodes.size());
    for (int i = 0; i < this->nodes.size(); i++) {
        bouquet[i] = i;
        trees->addNode(*this->nodes[i]);
    }

    for (int i = 0; i < this->nodes.size(); i++) {
        for (int j = 0; j < this->nodes.size(); j++) {
            // Ребра между i и j нет, пропускаем.
            if (this->edges[i][j] == nullptr) continue;

            int bI = bouquet[i];
            int bJ = bouquet[j];

            // Обе концевые вершины принадлежат одному букету, ребро не добавляем.
            if (bI == bJ) continue;

            // Концевые вершины принадлежат разным букетам, поэтому нужно их объединить в один.
            for (int k = 0; k < bouquet.size(); k++)
                if (bouquet[k] == bI)
                    bouquet[k] = bJ;

            for (auto& edge : *this->edges[i][j])
                trees->addEdge((*edge).current);
        }
    }

    Forest<E, N> result;
    result.trees = trees;
    for (int i = 0; i < this->nodes.size(); i++) {
        std::set<N*> rBouquet;
        
        for (int j = 0; j < this->nodes.size(); j++)
            if (bouquet[j] == i) rBouquet.insert(trees->nodes[j]);

        if (!rBouquet.empty()) 
            result.bouquets.push_back(rBouquet);
    }

    return result;
}