#include "../../libs/alg/alg.h"

void experiment(int N, int pairs) {
    srand(time(nullptr));
    
    int minKUP = INT_MAX;
    int maxKUP = INT_MIN;
    int minKWarshall = INT_MAX;
    int maxKWarshall = INT_MIN;
    for (int i = 0; i < 1000; i++) {
        BoolMatrixRelation rel = BoolMatrixRelation::getRandom(N, pairs);

        int kPow;
        BoolMatrixRelation powUnite = rel.transitiveClosurePowUnite(&kPow);
        int kWarshall;
        BoolMatrixRelation warshall = rel.transitiveClosureWarshall(&kWarshall);

        std::pair<int, int> ignored;
        assert(powUnite.isTransitive(ignored));
        assert(warshall.isTransitive(ignored));

        maxKUP = std::max(maxKUP, kPow);
        minKUP = std::min(minKUP, kPow);
        maxKWarshall = std::max(maxKWarshall, kPow);
        minKWarshall = std::min(minKWarshall, kPow);
    }

    std::cout << minKUP << " " << maxKUP << " " << minKWarshall << " " << maxKWarshall << std::endl;
}

int main() {
    std::cout << "Hello World!" << std::endl;
    experiment(15, 1);
    experiment(15, 56);
    experiment(15, 112);
    experiment(15, 150);
    experiment(15, 225);

    return 0;
}