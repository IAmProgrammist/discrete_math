#include "../alg.h"

FactorSet BoolMatrixRelation::getPackedFactorSet() {
    if (!isEquivalent()) throw std::invalid_argument("The relation is not equivalence relation");

    FactorSet result(size, -1);
    for (int x = 0; x < size; x++) {
        bool generatingEquivalenceClass = false;

        for (int y = 0; y < size; y++) {
            if (generatingEquivalenceClass && data[x][y])  {
                result[y] = x + 1;
                continue;
            } else if (result[y] == -1 && data[x][y]) {
                result[y] = x + 1;
                generatingEquivalenceClass = true;
            } else if (result[y] != -1 && data[x][y]) break;
        }
    }

    return result;
}