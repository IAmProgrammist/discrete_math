#include "../alg.h"

BoolMatrixRelation BoolMatrixRelation::transitiveClosurePowV1(int *steps = NULL)
{
    BoolMatrixRelation ctran = *this;
    BoolMatrixRelation c2 = ctran.pow(2);

    while (c2.includes(ctran))
    {
        ctran = ctran.unite(c2);
        c2 = ctran.pow(2);
        (*steps)++;
    }

    return ctran;
}

BoolMatrixRelation BoolMatrixRelation::transitiveClosureWarshall(int *steps = NULL)
{
    BoolMatrixRelation res(size, [this](int x, int y)
                           { return data[x - 1][y - 1]; });

    for (int z = 0; z < size; z++)
    {
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                if (steps != NULL) (*steps)++;

                if (res.data[x][y]) break;

                res.data[x][y] = res.data[x][y] || res.data[x][z] && res.data[z][y];
            }
        }
    }
}