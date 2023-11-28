#ifndef GRAPH
#define GRAPH

#include "node.tpp"
#include "edge.tpp"
#include "routes.tpp"

#include <set>

// Абстрактный класс граф, содержит виртуальные методы
template <typename E, typename N = typename E::NodeType>
class Graph {

public:
    using NodeValueType = typename N::NodeValueType;

    virtual void addNode(N& node) = 0;
    virtual void addEdge(E edge) = 0;
    virtual N* operator[](const NodeValueType value) = 0;
    virtual void deleteEdge(E edge) = 0;
    virtual void deleteNode(const N& node) = 0;

    virtual bool isRoute(std::vector<N*> route) = 0;
    virtual bool isChain(std::vector<N*> chain) = 0;
    virtual bool isSimpleChain(std::vector<N*> simpleChain) = 0;
    virtual bool isCycle(std::vector<N*> cycle) = 0;
    virtual bool isSimpleCycle(std::vector<N*> simpleCycle) = 0;

    virtual const std::vector<N*> getAdjacentNodes(N* node) = 0;
    virtual std::vector<PointRoute<N*>> getAllRoutes(N* start, int steps) = 0;

    virtual int countAllRoutesBetweenAllNodes(int steps) = 0;

    virtual std::vector<PointRoute<N*>> getAllRoutesBetweenTwoNodes(N* start, N* end, int steps) = 0;
};

template <typename E, typename N = typename E::NodeType>
class AdjacencyMatrixGraph : public Graph<E, N> {
public:
    class EdgeContainer {
        public:
        E current;
        EdgeContainer* linked = nullptr;

        EdgeContainer(E curr) : current(curr) {};

        EdgeContainer(E current, EdgeContainer* linked) {
            this->current = current;
            this->linked = linked;
        }

        bool operator==(const EdgeContainer& b) {
            return current.equals(b.current) && this->linked == b.linked;
        }
    };

    using NodeValueType = typename N::NodeValueType;

    std::vector<N*> nodes;
    std::vector<std::vector<std::vector<EdgeContainer>*>> edges;

    void addNode(N& node) override {
        for (auto &pNode : nodes) 
            if (pNode->equals(node)) 
                throw std::invalid_argument("Node is already present");

        nodes.push_back(node.clone());

        for (int i = 0; i < edges.size(); i++) {
            edges[i].resize(edges.size() + 1);
            edges[i][edges[i].size() - 1] = nullptr;
        }

        edges.push_back(std::vector<std::vector<EdgeContainer>*>(edges.size() + 1, nullptr));
    }

    void addEdge(E edge) {
        reinterpretNodes(edge.nodes);

        std::vector<EdgeContainer>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) edgePos = new std::vector<EdgeContainer>();

        (*edgePos).push_back(EdgeContainer(edge));
        EdgeContainer* added = &(*edgePos).back();
        if (!edge.isDirected) {
            std::reverse(edge.nodes.begin(), edge.nodes.end());

            std::vector<EdgeContainer>*& revEdgePos = this->at(edge.nodes.front(), edge.nodes.back());
            if (!revEdgePos) revEdgePos = new std::vector<EdgeContainer>();

            (*revEdgePos).push_back(EdgeContainer(edge));

            EdgeContainer* nonDirectAdded = &(*revEdgePos).back();

            added->linked = nonDirectAdded;
            nonDirectAdded->linked = added;
        }
    }

    void deleteEdge(E edge) {
        deleteEdge(edge, false);
    }

    void deleteNode(const N& node) {
        int deleteIndex = this->nodes.size();
        for (int i = 0; i < this->nodes.size() && deleteIndex == this->nodes.size(); i++) {
            if ((*this->nodes[i]).getValue() == node.getValue())
                deleteIndex = i;
        }

        if (deleteIndex == this->nodes.size()) throw std::invalid_argument("Node does not belongs to graph");

        for (auto &colEdge : this->edges[deleteIndex]) {
            delete colEdge;
        }
        this->nodes.erase(this->nodes.begin() + deleteIndex);

        for (auto &rowEdge : this->edges) {
            delete rowEdge[deleteIndex];
            rowEdge.erase(rowEdge.begin() + deleteIndex);
        }
    }

    bool isRoute(std::vector<N*> route) {
        reinterpretNodes(route);

        // Если две вершины смежны, то они инцидентны одному ребру.
        // Проверкой на смежность будем сразу проверять, что вершина i
        // инцидентна какому-то ребру, и вершина i + 1 тоже инцидентна
        // тому же ребру.
        for (int i = 0; i < route.size() - 1; i++) {
            if (!isNodesAdjacent(*route[i], *route[i + 1])) return false;
        }

        return true;
    }

    bool isChain(std::vector<N*> chain) {
        if (!isRoute(chain)) return false;
        reinterpretNodes(chain);
        
        std::vector<EdgeContainer> visitedEdges;
        for (int i = 0; i < chain.size() - 1; i++) {
            auto edges = *findByBeginEndPoint((*chain[i]).getValue(), (*chain[i + 1]).getValue());

            // Отдаём приоритет направленным рёбрам
            // Можем обратиться к 0 элементу безопасно из-за проверки на маршрут выше.
            EdgeContainer searchEdge = edges[0];
            bool found = false;
            bool foundDirected = false;
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j].linked == nullptr && std::find(visitedEdges.begin(), visitedEdges.end(), edges[j]) == visitedEdges.end()) {
                    foundDirected = true;
                    found = true;
                    visitedEdges.push_back(edges[j]);
                    break;
                } else if (edges[j].linked != nullptr && std::find(visitedEdges.begin(), visitedEdges.end(), edges[j]) == visitedEdges.end()) {
                    found = true;
                    searchEdge = edges[j];
                }
            }
            
            if (!found) 
                return false;
            else if (found && !foundDirected) {
                visitedEdges.push_back(searchEdge);
                visitedEdges.push_back(*searchEdge.linked);
            } 
        }

        return true;
    }

    bool isSimpleChain(std::vector<N*> simpleChain) {
        // Проверяем, что рёбра не повторяются
        if (!isRoute(simpleChain)) return false;

        for (int i = 0; i < simpleChain.size() - 1; i++) {
            for (int j = i + 1; j < simpleChain.size(); j++) {
                if ((simpleChain[i])->equals(*(simpleChain[j]))) return false;
            }
        }

        return true;
    }

    bool isCycle(std::vector<N*> cycle) {
        if (!isChain(cycle)) return false;

        return (*(cycle.front())).equals(*(cycle.back()));
    }

    bool isSimpleCycle(std::vector<N*> cycle) {
        if (!isCycle(cycle)) return false;

        for (int i = 0; i < cycle.size() - 2; i++) {
            for (int j = i + 1; j < cycle.size() - 1; j++) {
                if ((cycle[i])->equals(*(cycle[j]))) return false;
            }
        }

        return true;
    }

    // Ищет среди вершин нужную с value. Если вершина не найдена - возвращает null. Иначе - возвращает ссылку на него. 
    N* operator[](const NodeValueType value) {
        for (auto &n : this->nodes) 
            if (n->getValue() == value)
                return n;
        
        return nullptr;
    }

    // Ищет и возвращает указатель на массив, все грани в котором начинаются с точки с значением a и заканчивается b
    const std::vector<EdgeContainer>* findByBeginEndPoint(const NodeValueType begin, const NodeValueType end) {
        return at((*this)[begin], (*this)[end]);
    }

    ~AdjacencyMatrixGraph() {
        // Удаляем рёбра
        for (auto row : this->edges) {
            for (auto element : row) {
                delete element;
            }
        }

        // Удаляем вершины
        for (auto node: this->nodes) {
            delete node;
        }
    }

    const std::vector<N*> getAdjacentNodes(N* node) {
        int nodeIndex = -1;
        for (int i = 0; i < this->nodes.size(); i++) {
            if ((*(this->nodes[i])).equals(*node)) { 
                nodeIndex = i;
            
                break;
            }
        }

        if (nodeIndex == -1) throw std::invalid_argument("Node does not belongs to graph");

        std::vector<N*> result;
        for (int i = 0; i < this->nodes.size(); i++) {
            if (this->edges[nodeIndex][i] != nullptr)
                result.push_back(this->nodes[i]);
        }

        return result;
    }

    std::vector<PointRoute<N*>> getAllRoutes(N* start, int steps) {
        std::vector<PointRoute<N*>> result;
        if (steps <= 1) {
            result.push_back(PointRoute<N*>({start}));
            return result;
        }

        for (auto &adjNode : getAdjacentNodes(start)) {
            auto routes = getAllRoutes(adjNode, steps - 1);
            for (auto &route : routes) {
                route.route.insert(route.route.begin(), start);

                result.push_back(route);
            }
        }

        return result;
    }

    int countAllRoutesBetweenAllNodes(int steps) {
        int count = 0;
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < nodes.size(); j++) {
                count += getAllRoutesBetweenTwoNodes(this->nodes[i], this->nodes[j], steps).size();
            }
        }

        return count;
    }

    std::vector<PointRoute<N*>> getAllRoutesBetweenTwoNodes(N* start, N* end, int steps) {
        std::vector<PointRoute<N*>> result;
        if (steps < 1) {
            if (start->equals(*end))
                result.push_back(PointRoute<N*>({start}));
            
            return result;
        }

        for (auto &adjNode : getAdjacentNodes(start)) {
            auto routes = getAllRoutesBetweenTwoNodes(adjNode, end, steps - 1);
            if (routes.size() == 0) continue;
            
            for (auto &route : routes) {
                route.route.insert(route.route.begin(), start);

                result.push_back(route);
            }
        }

        return result;
    }

private:
    void deleteEdge(E edge, bool nonDirectionalDelete) {
        reinterpretNodes(edge.nodes);

        std::vector<EdgeContainer>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) throw std::invalid_argument("Edge doesn't exist in graph");
        
        
        for (int i = 0; i < (*edgePos).size(); i++) {
            EdgeContainer& currentEdge = (*edgePos)[i];

            if (!currentEdge.current.equals(edge)) continue;

            if (!edge.isDirected && !nonDirectionalDelete) {
                deleteEdge(currentEdge.linked->current, true);
            }

            (*edgePos).erase((*edgePos).begin() + i);
            if ((*edgePos).size() == 0) {
                delete edgePos;
                edgePos = nullptr;
            }

            return;
        }

        throw std::invalid_argument("Edge doesn't exist in graph");
    }

    bool isNodesAdjacent(const N& a, const N& b) {
        try {
            return findByBeginEndPoint(a.getValue(), b.getValue()) != nullptr;
        } catch (std::invalid_argument& ignore) {}

        return false;
    }

    // Обновляет вершины в edge, делая так, чтобы они принадлежали graph. Выбрасывает ошибку, если вершины не существует.
    void reinterpretNodes(std::vector<N*>& nodes) {
        for (int i = 0; i < nodes.size(); i++) {
            auto pNode = this->operator[](nodes[i]->getValue());

            if (pNode == nullptr)
                throw std::invalid_argument("Node does not belongs to graph");

            nodes[i] = pNode;
        }
    }

    std::vector<EdgeContainer>*& at(N* from, N* to) {
        if (from == nullptr || to == nullptr) throw std::invalid_argument("Node does not belongs to graph");

        int fromIndex = -1;
        int toIndex = -1;
        for (int i = 0; i < nodes.size() && (fromIndex == -1 || toIndex == -1); i++) {
            if (nodes[i] == from) fromIndex = i;
            if (nodes[i] == to)   toIndex = i;
        }

        if (fromIndex == -1 || toIndex == -1) {
            throw std::invalid_argument("Node is not present");
        }

        return edges[fromIndex][toIndex];
    }
};

#endif