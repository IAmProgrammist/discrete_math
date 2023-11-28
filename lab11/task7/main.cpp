#include "../util.h"

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();


    std::cout << "Simple maximum chains, starting in 4 in G1:\n"; 
    auto r = G1->getAllSimpleMaximumChains((*G1)[4]);
    for (auto &route : r) {
        for (int i = 0; i < route.route.size(); i++) {
            if (i == route.route.size() - 1) {
                std::cout << route.route[i]->name;
            } else {
                std::cout << route.route[i]->name << ", ";
            }
        }

        std::cout << std::endl;
    }

    std::cout << "Simple maximum chains, starting in 2 in G2:\n";
    r = G1->getAllSimpleMaximumChains((*G1)[2]);
    for (auto &route : r) {
        for (int i = 0; i < route.route.size(); i++) {
            if (i == route.route.size() - 1) {
                std::cout << route.route[i]->name;
            } else {
                std::cout << route.route[i]->name << ", ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}