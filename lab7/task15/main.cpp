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
    BoolMatrixRelation b(10, predB);
    BoolMatrixRelation c(10, predC);
    BoolMatrixRelation d = (((a.compose(b)).compose(b)).diff(c.non())).unite(c.pow(-1));

    std::cout << d << std::endl;
}