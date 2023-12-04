#include "task1/task1.h"

int main() {
    while (true) {
        auto g = generateRandomGraph(4, 5);

        if (!g->isEuler() && g->isHamiltonian()) {
            std::cout << "CRAP HERE";
            g = g;
            g->isHamiltonian();
            g->isEuler();
        }
    }
}