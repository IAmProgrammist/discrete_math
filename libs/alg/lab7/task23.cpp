#include "../alg.h"

#include <functional>

bool BoolMatrixRelation::isEmpty() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j]) return false;
        }
    }

    return true;
}

BoolMatrixRelation BoolMatrixRelation::getIdentity(int size) {
    return BoolMatrixRelation(size, [](int x, int y) {
        return x == y;
    });
}
BoolMatrixRelation BoolMatrixRelation::getUniversum(int size) {
return BoolMatrixRelation(size, [](int x, int y) {
        return true;
    });
}

bool BoolMatrixRelation::isReflexive(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        if (!data[i][i]) {
            failed = {i + 1, i + 1};
            return false;
        }
    }

    return true;
}
bool BoolMatrixRelation::isAntiReflexive(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        if (data[i][i]) {
            failed = {i + 1, i + 1};
            return false;
        }
    }

    return true;
}
bool BoolMatrixRelation::isSymmetric(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] && !data[j][i]) {
                failed = {i + 1, j + 1};
                return false;
            }
        }
    }

    return true;
}
bool BoolMatrixRelation::isAntiSymmetric(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] && data[j][i]) {
                failed = {i + 1, j + 1};
                return false;
            }
        }
    }

    return true;
}
bool BoolMatrixRelation::isTransitive(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int z = 0; z < size; z++) {
                if ((data[i][z] && data[z][j]) && !data[i][j]) {
                    failed = {i + 1, j + 1};
                    return false;
                }
            }
        }
    }

    return true;
}
bool BoolMatrixRelation::isAntiTransitive(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int z = 0; z < size; z++) {
                if ((data[i][z] && data[z][j]) && data[i][j]) {
                    failed = {i + 1, j + 1};
                    return false;
                }
            }
        }
    }

    return true;
}
bool BoolMatrixRelation::isFull(std::pair<int, int> &failed)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(data[i][j] || data[j][i])) {
                failed = {i + 1, j + 1};
                return false;
            }
        }
    }

    return true;
}
bool BoolMatrixRelation::isTolerant()
{
    std::pair<int, int> ignored;
    return isReflexive(ignored) && isSymmetric(ignored);
}
bool BoolMatrixRelation::isEquivalent()
{
    std::pair<int, int> ignored;
    return isReflexive(ignored) && isSymmetric(ignored) && isTransitive(ignored);
}
bool BoolMatrixRelation::isOrdered()
{
    std::pair<int, int> ignored;
    return isAntiSymmetric(ignored) && isTransitive(ignored);
}
bool BoolMatrixRelation::isOrderedNonStrict()
{
    std::pair<int, int> ignored;
    return isOrdered() && isReflexive(ignored);
}
bool BoolMatrixRelation::isOrderedStrict()
{
    std::pair<int, int> ignored;
    return isOrdered() && isAntiReflexive(ignored);
}
bool BoolMatrixRelation::isOrderedLinear()
{
    std::pair<int, int> ignored;
    return isOrdered() && isFull(ignored);
}
bool BoolMatrixRelation::isOrderedLinearNonStrict()
{
    std::pair<int, int> ignored;
    return isOrderedNonStrict() && isFull(ignored);
}
bool BoolMatrixRelation::isOrderedLinearStrict()
{
    std::pair<int, int> ignored;
    return isOrderedStrict() && isFull(ignored);
}