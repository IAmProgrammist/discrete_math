#include "../alg.h"

#include <functional>

BoolMatrixRelation::BoolMatrixRelation(const int size, std::function<bool (int, int)> pred)
{
    this->size = size;

    for (int x = 1; x <= size; x++)
    {
        std::vector<bool> val;

        for (int y = 1; y <= size; y++)
        {
            val.push_back(pred(x, y));
        }

        this->data.push_back(val);
    }
}

BoolMatrixRelation::~BoolMatrixRelation() {}