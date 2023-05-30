#include "../../libs/alg/alg.h"

int main() {
    assert(getDecision(1, (Point){0, 0}, 1) == 1);
    assert(getDecision(1, (Point){0, 0}, 12) == 0);
    assert(getDecision(5, (Point){3, 2}, 1) == 25);
    assert(getDecision(5, (Point){3, 3}, 2) == 27);
    assert(getDecision(5, (Point){3, 3}, 4) == 4);
    assert(getDecision(0, (Point){0, 0}, 0) == 0);
}