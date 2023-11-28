#ifndef GRAPH_ROUTE
#define GRAPH_ROUTE

template <typename N>
class PointRoute {
public:
    std::vector<N> route;

    PointRoute(std::vector<N> route) {
        this->route = route;
    }
};

#endif