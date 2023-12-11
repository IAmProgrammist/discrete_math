#include <vector>
#include <iostream>

typedef std::pair<int, int> Vec2;

std::ostream& operator<<(std::ostream& out, Vec2& o) {
    out << "(" << o.first << ", " << o.second << ")";

    return out;
}

#include "../../libs/alg/alg.h"

bool predicate(Vec2 a, Vec2 b) {
    return a.first <= b.second;
}

int main() {
    std::vector<Vec2> M1 = {{-1,  1}, {0,  1}, {1,  1},
                                           {-1,  0}, {0,  0}, {1,  0},
                                           {-1, -1}, {0, -1}, {1, -1}};

    Relation<Vec2> m1Ordered(M1, predicate);
    auto dominationRelM1 = m1Ordered.getDominantRelation();
    auto m1levels = dominationRelM1.getTopologicalSort();
    for (auto it = m1levels.end() - 1; it >= m1levels.begin(); it--) {
        for (auto element : *it) {
            std::cout << "(" << element.first << ", " << element.second << ") ";
        }

        std::cout << "\n";
    }

    std::cout << std::endl;


    std::vector<Vec2> M2 = {
                                               { 0,  2},
                                     {-1,  1}, { 0,  1}, { 1,  1},
                           {-2,  0}, {-1,  0}, { 0,  0}, { 1,  0}, { 2,  0},
                                     {-1, -1}, { 0, -1}, { 1, -1},
                                               { 0, -2}};

    Relation<Vec2> m2Ordered(M2, predicate);
    auto dominationRelM2 = m2Ordered.getDominantRelation();
    auto m2levels = dominationRelM2.getTopologicalSort();
    for (auto it = m2levels.end() - 1; it >= m2levels.begin(); it--) {
        for (auto element : *it) {
            std::cout << "(" << element.first << ", " << element.second << ") ";
        }

        std::cout << "\n";
    }

    return 0;
}