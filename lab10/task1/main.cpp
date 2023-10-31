#include "../../libs/alg/alg.h"

bool predicate(std::pair<int, int> a, std::pair<int, int> b) {
    return (a.first - b.first) < (b.second - a.second);
}

int main() {
    std::vector<std::pair<int, int>> M1 = {{-1,  1}, {0,  1}, {1,  1},
                                           {-1,  0}, {0,  0}, {1,  0},
                                           {-1, -1}, {0, -1}, {1, -1}};

    Relation<std::pair<int, int>> m1Ordered(M1, predicate);


    std::vector<std::pair<int, int>> M2 = {
                                               { 0,  2},
                                     {-1,  1}, { 0,  1}, { 1,  1},
                           {-2,  0}, {-1,  0}, { 0,  0}, { 1,  0}, { 2,  0},
                                     {-1, -1}, { 0, -1}, { 1, -1},
                                               { 0, -2}};

    Relation<std::pair<int, int>> m2Ordered(M2, predicate);

    m2Ordered.printAsAdjMatrix(std::cout);

    return 0;
}