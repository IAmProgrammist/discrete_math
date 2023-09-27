#include "../../libs/alg/alg.h"

#include <stdint.h>

bool predA(int x, int y) {
    return (x < y && y < (9 - x)) || ((9 - x) < y && y < x);
}

bool predB(int x, int y) {
    return x % 2 == 0 && y % 2 != 0;
}

bool predC(int x, int y) {
    return (x * y) % 3 == 0 ;
}

void outputProperties(std::string name, BoolMatrixRelation a) {
    std::pair<int, int> failedAt;
    std::cout << "Properties for " << name << "\n";
    if (a.isReflexive(failedAt)) {
        std::cout << "Reflexive\n";
    } else {
        std::cout << "Non reflexive, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    if (a.isAntiReflexive(failedAt)) {
        std::cout << "Antireflexive\n";
    } else {
        std::cout << "Non antireflexive, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    
    if (a.isSymmetric(failedAt)) {
        std::cout << "Symmetric\n";
    } else {
        std::cout << "Non symmetric, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    
    if (a.isAntiSymmetric(failedAt)) {
        std::cout << "AntiSymmetric\n";
    } else {
        std::cout << "Non antisymmetric, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    
    if (a.isTransitive(failedAt)) {
        std::cout << "Transitive\n";
    } else {
        std::cout << "Non transitive, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    
    if (a.isAntiTransitive(failedAt)) {
        std::cout << "AntiTransitive\n";
    } else {
        std::cout << "Non antitransitive, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    
    if (a.isFull(failedAt)) {
        std::cout << "Full\n";
    } else {
        std::cout << "Non full, failed pair: (" << failedAt.first << ", " << failedAt.second << ")\n";
    }
    std::cout << (a.isTolerant() ? "Tolerant" : "Non tolerant") << "\n";
    std::cout << (a.isEquivalent() ? "Equivalent" : "Non equivalent") << "\n";
    std::cout << (a.isOrdered() ? "Ordered" : "Non ordered") << "\n";
    std::cout << (a.isOrderedNonStrict() ? "Ordered non strict" : "Non ordered non strict") << "\n";
    std::cout << (a.isOrderedStrict() ? "Ordered strict" : "Non ordered strict") << "\n";
    std::cout << (a.isOrderedLinear() ? "Ordered linear" : "Non ordered linear") << "\n";
    std::cout << (a.isOrderedLinearNonStrict() ? "Ordered linear non strict" : "Non ordered linear non strict") << "\n";
    std::cout << (a.isOrderedLinearStrict() ? "Ordered linear strict" : "Non ordered linear strict") << "\n" << std::endl;
}

int main() {
    BoolMatrixRelation a(10, predA);
    BoolMatrixRelation b(10, predB);
    BoolMatrixRelation c(10, predC);

    outputProperties("A", a);
    outputProperties("B", b);
    outputProperties("C", c);
}