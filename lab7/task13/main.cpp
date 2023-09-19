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

int main() {
    BoolMatrixRelation a(10, predA);
    std::cout << a << std::endl;

    BoolMatrixRelation b(10, predB);
    std::cout << b << std::endl;
    
    BoolMatrixRelation c(10, predC);
    std::cout << c << std::endl;
}