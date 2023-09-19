#include "../alg.h"

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

bool BoolMatrixRelation::isReflexive()
{
    return BoolMatrixRelation::getIdentity(size).includes(*this);
}
bool BoolMatrixRelation::isAntiReflexive()
{
    return (*this).intersect(BoolMatrixRelation::getIdentity(size)).isEmpty();
}
bool BoolMatrixRelation::isSymmetric()
{
    return (*this).equals((*this).pow(-1));
}
bool BoolMatrixRelation::isAntiSymmetric()
{
    return (*this).intersect((*this).pow(-1)).includes(BoolMatrixRelation::getIdentity(size));
}
bool BoolMatrixRelation::isTransitive()
{
    return ((*this).pow(2)).includes((*this));
}
bool BoolMatrixRelation::isAntiTransitive()
{
    return ((*this).pow(2)).intersect((*this)).isEmpty();
}
bool BoolMatrixRelation::isFull()
{
    return (*this).unite(BoolMatrixRelation::getIdentity(size)).unite((*this).pow(-1)).equals(BoolMatrixRelation::getUniversum(size));
}
bool BoolMatrixRelation::isTolerant()
{
    return isReflexive() && isSymmetric();
}
bool BoolMatrixRelation::isEquivalent()
{
    return isReflexive() && isSymmetric() && isTransitive();
}
bool BoolMatrixRelation::isOrdered()
{
    return isAntiSymmetric() && isTransitive();
}
bool BoolMatrixRelation::isOrderedNonStrict()
{
    return isOrdered() && isReflexive();
}
bool BoolMatrixRelation::isOrderedStrict()
{
    return isOrdered() && isAntiReflexive();
}
bool BoolMatrixRelation::isOrderedLinear()
{
    return isOrdered() && isFull();
}
bool BoolMatrixRelation::isOrderedLinearNonStrict()
{
    return isOrderedNonStrict() && isFull();
}
bool BoolMatrixRelation::isOrderedLinearStrict()
{
    return isOrderedStrict() && isFull();
}