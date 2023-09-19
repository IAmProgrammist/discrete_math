#ifndef DISCRETE_MATH_ALGCPP_H
#define DISCRETE_MATH_ALGCPP_H

#include <vector>
#include <iostream>
#include <iomanip>

template <class T>
class Sett
{
public:
    std::vector<T> elements;

    Sett<T>(std::vector<T> elms);

    Sett<T> operator*(Sett<T> anotherSet);

    Sett<T> operator-(Sett<T> anotherSet);

    Sett<T> operator+(Sett<T> anotherSet);

    Sett<T> non(Sett<T> universum);

    Sett<T> operator^(Sett<T> anotherSet);

    bool operator==(Sett<T> other);

    bool operator!=(Sett<T> other);
};

#include "./lab3/set.tpp"

template <typename T>
std::vector<std::vector<T>> getSubsets(std::vector<T> &baseSet, std::vector<T> currentSet,
                                       size_t count);

template <typename T>
std::vector<std::vector<T>> getSubsets(std::vector<T> &baseSet);

#include "./lab5/subsets.tpp"

template <typename T>
std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, std::vector<T> currentSet, size_t minIndex, size_t k, size_t count);

template <typename T>
std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, size_t k);

#include "./lab5/combinations.tpp"

template <typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> baseSet, std::vector<T> currentSet);

template <typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> &baseSet);

#include "./lab5/permutations.tpp"

template <typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> baseSet, std::vector<T> currentSet, size_t k);

template <typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> &baseSet, size_t k);

#include "./lab5/placements.tpp"

struct Point
{
    long long x;
    long long y;
};

size_t getDecision(size_t n, Point a, size_t k);

class BoolMatrixRelation
{
private:
    std::vector<std::vector<bool>> data;
    int size;

    static BoolMatrixRelation getDefault() {
        return BoolMatrixRelation();
    }

public:
    BoolMatrixRelation(const int size, std::function<bool (int, int)> pred);
    BoolMatrixRelation() {
        this->size = 0;
    }
    ~BoolMatrixRelation();

    bool includes(BoolMatrixRelation b);
    bool equals(BoolMatrixRelation b);
    bool includesStrict(BoolMatrixRelation b);
    BoolMatrixRelation unite(BoolMatrixRelation b);
    BoolMatrixRelation intersect(BoolMatrixRelation b);
    BoolMatrixRelation diff(BoolMatrixRelation b);
    BoolMatrixRelation symDiff(BoolMatrixRelation b);
    BoolMatrixRelation non();
    BoolMatrixRelation transpose();
    BoolMatrixRelation compose(BoolMatrixRelation b);
    BoolMatrixRelation pow(int p);

    static BoolMatrixRelation getIdentity(int size);
    static BoolMatrixRelation getUniversum(int size);

    bool isEmpty();

    bool isReflexive();
    bool isAntiReflexive();
    bool isSymmetric();
    bool isAntiSymmetric();
    bool isTransitive();
    bool isAntiTransitive();
    bool isFull();
    bool isTolerant();
    bool isEquivalent();
    bool isOrdered();
    bool isOrderedNonStrict();
    bool isOrderedStrict();
    bool isOrderedLinear();
    bool isOrderedLinearNonStrict();
    bool isOrderedLinearStrict();

    friend std::ostream& operator<<(std::ostream& out, BoolMatrixRelation &val) {
        out << std::setw(3) << "" << " ";
        for (int i = 1; i <= val.size; i++) {
            out << std::setw(3) << i << " ";
        }
        out << "\n";

        for (int x = 0; x < val.size; x++) {
            out << std::setw(3) << x + 1 << " ";
            for (int y = 0; y < val.size; y++) {
                out << std::setw(3) << val.data[x][y] << " ";
            }

            out << "\n";
        }

        return out;
    }
};

#endif // DISCRETE_MATH_ALGCPP_H
