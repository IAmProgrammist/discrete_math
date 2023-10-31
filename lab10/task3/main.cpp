#include "../../libs/alg/alg.h"

bool predicate(std::pair<int, int> a, std::pair<int, int> b) {
    return (a.first - b.first) < (b.second - a.second);
}

int main() {
    std::vector<std::pair<int, int>> M1 = {{-1,  1}, {0,  1}, {1,  1},
                                           {-1,  0}, {0,  0}, {1,  0},
                                           {-1, -1}, {0, -1}, {1, -1}};

    Relation<std::pair<int, int>> m1Ordered(M1, predicate);
    auto dominationRelM1 = m1Ordered.getDominantRelation();

    std::cout << m1Ordered << std::endl << dominationRelM1 << std::endl << std::endl;

    auto m1levels = dominationRelM1.getTopologicalSort();
    for (auto it = m1levels.end() - 1; it >= m1levels.begin(); it--) {
        for (auto element : *it) {
            std::cout << "(" << element.first << ", " << element.second << ") ";
        }

        std::cout << "\n";
    }


    std::vector<std::pair<int, int>> M2 = {
                                               { 0,  2},
                                     {-1,  1}, { 0,  1}, { 1,  1},
                           {-2,  0}, {-1,  0}, { 0,  0}, { 1,  0}, { 2,  0},
                                     {-1, -1}, { 0, -1}, { 1, -1},
                                               { 0, -2}};

    Relation<std::pair<int, int>> m2Ordered(M2, predicate);
    auto dominationRelM2 = m2Ordered.getDominantRelation();

    std::cout << m2Ordered << std::endl << dominationRelM2 << std::endl << std::endl;

    auto m2levels = dominationRelM2.getTopologicalSort();
    for (auto it = m2levels.end() - 1; it >= m2levels.begin(); it--) {
        for (auto element : *it) {
            std::cout << "(" << element.first << ", " << element.second << ") ";
        }

        std::cout << "\n";
    }

    return 0;
}