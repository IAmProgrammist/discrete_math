#include "../alg.h"

template <typename E>
std::pair<Forest<E>, std::vector<E>> getEdgesToDeleteToDivideGraphInNLinkedComponents(Graph<E> *g, std::vector<E> edges, int linkedComponentsAmount) {
    for (int deleteAmount = 0; deleteAmount <= edges.size(); deleteAmount++) {
        for (auto &comb : getCombinations<E>(edges, deleteAmount)){
            auto originClone = g->clone();
            
            for (auto &edge : comb)
                originClone->deleteEdge(edge);
            
            auto forest = originClone->getSpanningForest();
            delete originClone;

            if (forest.roots.size() == linkedComponentsAmount) 
                return {forest, comb};

            delete forest.trees;
        }
    }

    return {{nullptr, {}, {}}, std::vector<E>(0)};
}