#ifndef DISCRETE_MATH_ALGCPP_H
#define DISCRETE_MATH_ALGCPP_H

#include <vector>
#include <iostream>

template <class T>
class Sett {
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
std::vector<std::vector<T>> getSubsets(std::vector<T>& baseSet, std::vector<T> currentSet,
                                       size_t count);

template <typename T>
std::vector<std::vector<T>> getSubsets(std::vector<T>& baseSet);

#include "./lab5/subsets.tpp"

template<typename T>
std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, std::vector<T> currentSet, size_t minIndex, size_t k, size_t count);

template<typename T> std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, size_t k);

#include "./lab5/combinations.tpp"

template<typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> baseSet, std::vector<T> currentSet);

template<typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> &baseSet);

#include "./lab5/permutations.tpp"

template<typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> baseSet, std::vector<T> currentSet, size_t k);

template<typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> &baseSet, size_t k);

#include "./lab5/placements.tpp"

#endif //DISCRETE_MATH_ALGCPP_H
