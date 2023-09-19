#include "../../libs/alg/alg.h"

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
    std::cout << "Properties for " << name << "\n";
    std::cout << "Is reflexive? " << a.isReflexive() << "\n";
    std::cout << "Is antireflexive? " << a.isAntiReflexive() << "\n";
    std::cout << "Is symmetric? " << a.isSymmetric() << "\n";
    std::cout << "Is antisymmetric? " << a.isAntiSymmetric() << "\n";
    std::cout << "Is transitive? " << a.isTransitive() << "\n";
    std::cout << "Is antitransitive? " << a.isAntiTransitive() << "\n";
    std::cout << "Is full? " << a.isFull() << "\n";
    std::cout << "Is tolerant? " << a.isTolerant() << "\n";
    std::cout << "Is equivalent? " << a.isEquivalent() << "\n";
    std::cout << "Is ordered? " << a.isOrdered() << "\n";
    std::cout << "Is ordered non strict? " << a.isOrderedNonStrict() << "\n";
    std::cout << "Is ordered strict? " << a.isOrderedStrict() << "\n";
    std::cout << "Is ordered linear? " << a.isOrderedLinear() << "\n";
    std::cout << "Is ordered linear non strict? " << a.isOrderedLinearNonStrict() << "\n";
    std::cout << "Is ordered linear strict? " << a.isOrderedLinearStrict() << "\n" << std::endl;
}

int main() {
    BoolMatrixRelation a(10, predA);
    BoolMatrixRelation b(10, predB);
    BoolMatrixRelation c(10, predC);

    outputProperties("A", a);
    outputProperties("B", b);
    outputProperties("C", c);
}