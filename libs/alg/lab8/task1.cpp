#include "../alg.h"

BoolMatrixRelation BoolMatrixRelation::transitiveClosurePowUnite(unsigned long long *steps)
{
    BoolMatrixRelation ctran = *this;
    BoolMatrixRelation c2 = ctran.pow(2);

    for (int i = 2; i <= size; i++)
    {
        ctran = ctran.unite(c2);
        
        // Самым вложенным является цикл композиции, поэтому
        // вычислять композицию будем вручную, а не при помощи 
        // реализованного ранее метода pow
        c2 = BoolMatrixRelation(size, [steps, &ctran](int x, int y)
                                {
        for (int z = 0; z < ctran.size; z++) {
            (*steps)++;
            if (ctran.data[x - 1][z] && ctran.data[z][y - 1])
                return true;
        }

        return false; 
        });
    }

    return ctran;
}

BoolMatrixRelation BoolMatrixRelation::transitiveClosureWarshall(unsigned long long *steps)
{
    BoolMatrixRelation res(size, [this](int x, int y)
                           { return data[x - 1][y - 1]; });

    for (int z = 0; z < size; z++)
    {
        for (int x = 0; x < size; x++)
        {
            if (!res.data[x][z]) continue;
            for (int y = 0; y < size; y++)
            {
                if (steps != NULL)
                    (*steps)++;

                res.data[x][y] = res.data[x][y] || res.data[x][z] && res.data[z][y];
            }
        }
    }

    return res;
}