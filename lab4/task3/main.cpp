#include "../../libs/alg/alg.h"

int main() {
    Sett<int> nothing(std::vector<int>({}));
    Sett<int> U(std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    Sett<int> A(std::vector<int>({4, 5, 7, 8, 9, 10}));
    Sett<int> B(std::vector<int>({2, 3, 4, 5, 6, 10}));
    Sett<int> C(std::vector<int>({4, 5, 7, 8, 10}));

    Sett<int> phiNothing = ((A * (B + nothing)) ^ C) ^ (A - ((B * nothing.non(U)) ^ (C * nothing)));
    Sett<int> nonPhiU = (((A * (B + U)) ^ C) ^ (A - ((B * U.non(U)) ^ (C * U)))).non(U);

    phiNothing.print();
    nonPhiU.print();
}