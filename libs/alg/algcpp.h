#ifndef DISCRETE_MATH_ALGCPP_H
#define DISCRETE_MATH_ALGCPP_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>

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

typedef std::vector<int> FactorSet;

class BoolMatrixRelation
{
protected:
    std::vector<std::vector<bool>> data;
    int size;

    static BoolMatrixRelation getDefault()
    {
        return BoolMatrixRelation();
    }

public:
    BoolMatrixRelation(const int size, std::function<bool(int, int)> pred);
    BoolMatrixRelation()
    {
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
    static BoolMatrixRelation getRandom(int size, int pairs);

    bool isEmpty();

    bool isReflexive(std::pair<int, int> &failed);
    bool isAntiReflexive(std::pair<int, int> &failed);
    bool isSymmetric(std::pair<int, int> &failed);
    bool isAntiSymmetric(std::pair<int, int> &failed);
    bool isTransitive(std::pair<int, int> &failed);
    bool isAntiTransitive(std::pair<int, int> &failed);
    bool isFull(std::pair<int, int> &failed);
    bool isTolerant();
    bool isEquivalent();
    bool isOrdered();
    bool isOrderedNonStrict();
    bool isOrderedStrict();
    bool isOrderedLinear();
    bool isOrderedLinearNonStrict();
    bool isOrderedLinearStrict();

    BoolMatrixRelation transitiveClosurePowUnite(unsigned long long *steps = NULL);
    BoolMatrixRelation transitiveClosureWarshall(unsigned long long *steps = NULL);

    FactorSet getPackedFactorSet();

    friend std::ostream &operator<<(std::ostream &out, BoolMatrixRelation &val)
    {
        out << std::setw(3) << ""
            << " ";
        for (int i = 1; i <= val.size; i++)
        {
            out << std::setw(3) << i << " ";
        }
        out << "\n";

        for (int x = 0; x < val.size; x++)
        {
            out << std::setw(3) << x + 1 << " ";
            for (int y = 0; y < val.size; y++)
            {
                out << std::setw(3) << val.data[x][y] << " ";
            }

            out << "\n";
        }

        return out;
    }

    std::ostream &printAsAdjMatrix(std::ostream &out)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                out << data[i][j] << ",";
            }

            out << "\n";
        }

        return out;
    }
};

template <typename T>
class DominantRelation;

template <typename T>
class Relation : public BoolMatrixRelation
{
protected:
    std::vector<T> origin;

public:
    Relation(std::vector<T> origin, std::function<bool(T, T)> pred) : BoolMatrixRelation(origin.size(), [&origin, &pred](int x, int y)
                                                                                         { return pred(origin[x - 1], origin[y - 1]); })
    {
        this->origin = origin;
    };

    DominantRelation<T> getDominantRelation();
};

template <typename T>
class DominantRelation : public Relation<T>
{
public:
    DominantRelation(std::vector<T> origin, std::function<bool(T, T)> pred) : Relation<T>(origin, pred) {};

    std::vector<std::vector<T>> getTopologicalSort();
};

#include "lab10/task2.tpp"
#include "lab10/task3.tpp"

#endif // DISCRETE_MATH_ALGCPP_H
