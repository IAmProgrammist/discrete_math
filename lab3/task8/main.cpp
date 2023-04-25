#include "../../libs/alg/alg.h"

int main() {
    Sett<int> A(std::vector<int>({1, 3, 5, 7}));
    Sett<int> B(std::vector<int>({2, 3, 6, 7}));
    Sett<int> C(std::vector<int>({4, 5, 6, 7}));
    Sett<int> U(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7}));

    Sett<int> F3 = A.non(U) - C;
    Sett<int> F4 = B - A - C;

    F3.print();
    F4.print();

    return 0;
}