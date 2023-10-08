#include "../alg.h"

BoolMatrixRelation BoolMatrixRelation::getRandom(int size, int pairs) {
    if (pairs >= size * size) return BoolMatrixRelation (size, [](int x, int y){return true;});
    
    BoolMatrixRelation res(size, [](int x, int y){return false;});
    while (pairs > 0) {
        int rX = rand() % size, rY = rand() % size;

        if (!res.data[rX][rY]) {
            res.data[rX][rY] = true;
            pairs--;
        }
    }

    return res;
}