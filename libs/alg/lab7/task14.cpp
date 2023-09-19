#include "../alg.h"

bool BoolMatrixRelation::includes(BoolMatrixRelation b)
{
    if (this->size != b.size) return false;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] && !b.data[i][j])
                return false;
        }
    }
    return true;
}
bool BoolMatrixRelation::equals(BoolMatrixRelation b)
{
    if (this->size != b.size) return false;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i][j] != b.data[i][j])
                return false;
        }
    }
    return true;
}
bool BoolMatrixRelation::includesStrict(BoolMatrixRelation b)
{
    return (*this).includes(b) && !(*this).equals(b);
}
BoolMatrixRelation BoolMatrixRelation::unite(BoolMatrixRelation b)
{
    if (this->size != b.size) return BoolMatrixRelation::getDefault();

    return BoolMatrixRelation(size, [this, &b](int x, int y) {
        return data[x - 1][y - 1] || b.data[x - 1][y - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::intersect(BoolMatrixRelation b)
{
    if (this->size != b.size) return BoolMatrixRelation::getDefault();

    return BoolMatrixRelation(size, [this, &b](int x, int y) {
        return data[x - 1][y - 1] && b.data[x - 1][y - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::diff(BoolMatrixRelation b)
{
    if (this->size != b.size) return BoolMatrixRelation::getDefault();

    return BoolMatrixRelation(size, [this, &b](int x, int y) {
        return data[x - 1][y - 1] && !b.data[x - 1][y - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::symDiff(BoolMatrixRelation b)
{
    if (this->size != b.size) return BoolMatrixRelation::getDefault();

    return BoolMatrixRelation(size, [this, &b](int x, int y) {
        return data[x - 1][y - 1] ^ b.data[x - 1][y - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::non()
{
    return BoolMatrixRelation(size, [this](int x, int y) {
        return !data[x - 1][y - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::transpose()
{
    return BoolMatrixRelation(size, [this](int x, int y) {
        return data[y - 1][x - 1];
    });
}
BoolMatrixRelation BoolMatrixRelation::compose(BoolMatrixRelation b)
{
    if (this->size != b.size) return BoolMatrixRelation::getDefault();
    BoolMatrixRelation composeResult(size, [](int x, int y){return false;});

    for (int z = 0; z < size; z++) {
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                if (data[x][z] && data[z][y])
                composeResult.data[x][y] = true;
            }
        }
    }

    return composeResult;
}
BoolMatrixRelation BoolMatrixRelation::pow(int p)
{
    if (p < 0) return transpose();
    if (p == 0) return BoolMatrixRelation(size, [](int x, int y){return x == y;});
    if (p == 1) return *this;

    BoolMatrixRelation lowP = pow(p - 1);
    return compose(lowP);
}