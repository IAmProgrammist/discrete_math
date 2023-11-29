#include "../util.h"

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();

    std::cout << "All routes that start in 5 in G1 that has 3 edges: \n";
    auto r = G1->getAllRoutes((*G1)[5], 3);

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

    std::cout << "All routes that start in 2 in G2 that has 4 edges: \n";
    r = G2->getAllRoutes((*G1)[2], 4);

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