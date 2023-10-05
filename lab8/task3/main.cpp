#include "../../libs/alg/alg.h"

void experiment(int N, int pairs) {
    srand(time(nullptr));
    
    unsigned long long minKUP = ULLONG_MAX;
    unsigned long long maxKUP = 0;
    unsigned long long minKWarshall = ULLONG_MAX;
    unsigned long long maxKWarshall = 0;
    for (int i = 0; i < 1000; i++) {
        BoolMatrixRelation rel = BoolMatrixRelation::getRandom(N, pairs);

        unsigned long long kPow = 0;
        BoolMatrixRelation powUnite = rel.transitiveClosurePowUnite(&kPow);
        unsigned long long kWarshall = 0;
        BoolMatrixRelation warshall = rel.transitiveClosureWarshall(&kWarshall);

        std::pair<int, int> ignored;
        assert(powUnite.isTransitive(ignored));
        assert(warshall.isTransitive(ignored));

        maxKUP = std::max(maxKUP, kPow);
        minKUP = std::min(minKUP, kPow);
        maxKWarshall = std::max(maxKWarshall, kWarshall);
        minKWarshall = std::min(minKWarshall, kWarshall);
    }

    std::cout << minKUP << " " << maxKUP << " " << minKWarshall << " " << maxKWarshall << std::endl;
}

int main() {
    for (int i = 5; i <= 15; i += 5) {
        experiment(i, 1);
        experiment(i, (i * i) / 4);
        experiment(i, (i * i) / 2);
        experiment(i, (i * i * 2) / 3);
        experiment(i, i * i);
    }

    return 0;
}