#include "../util.h"

int main() {
    Graph<Edge<IntNode>> *G1 = constructGraph1();
    Graph<Edge<IntNode>> *G2 = constructGraph2();

    std::cout << "All routes between adjacent elements 1 and 7 in 1 step in G1: \n";
    
    auto r = G1->getAllRoutesBetweenTwoNodes((*G1)[1], (*G1)[7], 1);
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

    std::cout << "All routes between non-adjacent elements 3 and 4 in 4 steps in G1: \n";
    r = G1->getAllRoutesBetweenTwoNodes((*G1)[3], (*G1)[7], 4);
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

    std::cout << "All routes between non-adjacent elements 7 and 5 in 4 steps in G2: \n";
    r = G2->getAllRoutesBetweenTwoNodes((*G2)[7], (*G2)[5], 4);
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

    //std::cout << "All routes between pairs in 1 steps in G2: " << G2->countAllRoutesBetweenAllNodes(1) << std::endl;

    return 0;
}