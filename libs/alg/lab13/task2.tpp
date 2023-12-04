#include "../alg.h"

template <typename E>
std::vector<E> getEdgesToDeleteToDivideGraphInThreeLinkedComponents(Graph<E> *g, std::vector<E> edges) {
    for (int deleteAmount = 0; deleteAmount <= edges.size(); deleteAmount++) {
        for (auto &comb : getCombinations<E>(edges, deleteAmount)){
            auto originClone = g->clone();
            
            for (auto &edge : comb)
                originClone->deleteEdge(edge);
            
            auto forest = originClone->getSpanningForest();
            delete originClone;

            if (forest.roots.size() == 3) {
                delete forest.trees;

                return comb;
            }

            delete forest.trees;
        }
    }

    return std::vector<E>(0);
}