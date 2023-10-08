#include "../../libs/alg/alg.h"

#include <fstream>
#include <dir.h>
#include <filesystem>

void experiment(int N, int pairs) {
    mkdir("output");
    srand(time(nullptr));
    
    unsigned long long minKUP = ULLONG_MAX;
    BoolMatrixRelation minUPM = BoolMatrixRelation::getIdentity(1);
    BoolMatrixRelation minUPO = BoolMatrixRelation::getIdentity(1);
    unsigned long long maxKUP = 0;
    BoolMatrixRelation maxUPM = BoolMatrixRelation::getIdentity(1);
    BoolMatrixRelation maxUPO = BoolMatrixRelation::getIdentity(1);
    unsigned long long minKWarshall = ULLONG_MAX;
    BoolMatrixRelation minWarshallM = BoolMatrixRelation::getIdentity(1);
    BoolMatrixRelation minWarshallO = BoolMatrixRelation::getIdentity(1);
    unsigned long long maxKWarshall = 0;
    BoolMatrixRelation maxWarshallM = BoolMatrixRelation::getIdentity(1);
    BoolMatrixRelation maxWarshallO = BoolMatrixRelation::getIdentity(1);
    for (int i = 0; i < 1000; i++) {
        BoolMatrixRelation rel = BoolMatrixRelation::getRandom(N, pairs);

        unsigned long long kPow = 0;
        BoolMatrixRelation powUnite = rel.transitiveClosurePowUnite(&kPow);
        unsigned long long kWarshall = 0;
        BoolMatrixRelation warshall = rel.transitiveClosureWarshall(&kWarshall);

        std::pair<int, int> ignored;
        assert(powUnite.isTransitive(ignored));
        assert(warshall.isTransitive(ignored));
        assert(powUnite.equals(warshall));

        if (kPow >= maxKUP) {
            maxKUP = kPow;
            maxUPM = powUnite;
            maxUPO = rel;
        }
        if (kPow <= minKUP) {
            minKUP = kPow;
            minUPM = powUnite;
            minUPO = rel;
        }

        if (kWarshall >= maxKWarshall) {
            maxKWarshall = kWarshall;
            maxWarshallM = warshall;
            maxWarshallO = rel;
        }
        if (kWarshall <= minKWarshall) {
            minKWarshall = kWarshall;
            minWarshallM = warshall;
            minWarshallO = rel;
        }
    }

    std::string prefix = "output/";
    // U  - объединение степенией / W - воршэлл
    // M  - транзитивное замыкание / O - оригинал
    // Mi - минимальное кол-во выполнений тела самого вложенного цикла / Ma - максимальное кол-во выполнений тела самого вложенного цикла
    // N  - Мощность
    // P  - Кол-во сгенерированных пар 
    std::ofstream wrMinUPM(prefix + "N" + std::to_string(N) + "U" + "M" + "Mi" + std::to_string(minKUP)       + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMinUPO(prefix + "N" + std::to_string(N) + "U" + "O" + "Mi" + std::to_string(minKUP)       + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMaxUPM(prefix + "N" + std::to_string(N) + "U" + "M" + "Ma" + std::to_string(maxKUP)       + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMaxUPO(prefix + "N" + std::to_string(N) + "U" + "O" + "Ma" + std::to_string(maxKUP)       + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMinWPM(prefix + "N" + std::to_string(N) + "W" + "M" + "Mi" + std::to_string(minKWarshall) + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMinWPO(prefix + "N" + std::to_string(N) + "W" + "O" + "Mi" + std::to_string(minKWarshall) + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMaxWPM(prefix + "N" + std::to_string(N) + "W" + "M" + "Ma" + std::to_string(maxKWarshall) + "P" + std::to_string(pairs) + ".txt");
    std::ofstream wrMaxWPO(prefix + "N" + std::to_string(N) + "W" + "O" + "Ma" + std::to_string(maxKWarshall) + "P" + std::to_string(pairs) + ".txt");
    
    minUPM.printAsAdjMatrix(wrMinUPM);
    minUPO.printAsAdjMatrix(wrMinUPO);
    maxUPM.printAsAdjMatrix(wrMaxUPM);
    maxUPO.printAsAdjMatrix(wrMaxUPO);
    minWarshallM.printAsAdjMatrix(wrMinWPM);
    minWarshallO.printAsAdjMatrix(wrMinWPO);
    maxWarshallM.printAsAdjMatrix(wrMaxWPM);
    maxWarshallO.printAsAdjMatrix(wrMaxWPO);
}

int main() {
    std::filesystem::remove_all("output/");

    for (int i = 5; i <= 15; i += 5) {
        experiment(i, 1);
        experiment(i, (i * i) / 4);
        experiment(i, (i * i) / 2);
        experiment(i, (i * i * 2) / 3);
        experiment(i, i * i);
    }

    return 0;
}