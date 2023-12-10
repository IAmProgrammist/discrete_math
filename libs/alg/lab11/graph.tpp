#ifndef GRAPH
#define GRAPH

// Abandon hope, all ye who enter here

#include "node.tpp"
#include "edge.tpp"
#include "routes.tpp"

#include <set>
#include <limits>

template <typename E, typename N = typename E::NodeType>
class Graph;

template <typename E, typename N = typename E::NodeType>
struct Forest {
    // Граф, содержащий получившийся остовый лес
    Graph<E, N>* trees;
    // Букеты
    std::vector<std::set<N*>> bouquets;
};

template <typename N, typename V>
struct ShortestWay {
    std::vector<bool> reachableNodes;
    std::vector<V> distances;
    std::vector<int> prevNodesIndices;
    std::vector<N> nodes;
    int rootNodeIndex;
    int endNodeIndex;
};

// Абстрактный класс граф, содержит виртуальные методы
template <typename E, typename N>
class Graph {
public:
    using NodeValueType = typename N::NodeValueType;
    using EdgeValueType = typename E::NameType;

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

    virtual std::vector<PointRoute<N*>> getAllSimpleMaximumChains(N* start) = 0;

    virtual bool isHamiltonian() = 0;
    virtual bool isEuler() = 0;

    virtual Forest<E, N> getSpanningForest() = 0;

    virtual ~Graph() {
    };

    virtual Graph<E>* clone() = 0;
    virtual bool isChainBetweenNodesExist(N* start, N* end) = 0;
    virtual int getNodesSize() = 0;

    virtual ShortestWay<N, EdgeValueType> getShortestWay(N* start, N* target) = 0;
};

template <typename E, typename N = typename E::NodeType>
class AdjacencyMatrixGraph : public Graph<E, N> {
public:
    class EdgeContainer {
        public:
        E current;
        EdgeContainer* linked = nullptr;

        EdgeContainer(){};

        EdgeContainer(E curr) : current(curr) {};

        EdgeContainer(E current, EdgeContainer* linked) {
            this->current = current;
            this->linked = linked;
        }

        bool operator==(const EdgeContainer& b) {
            return current.equals(b.current) && this->linked == b.linked;
        }
    };

    using EdgeValueType = typename E::NameType;
    using NodeValueType = typename N::NodeValueType;

    std::vector<N*> nodes;
    std::vector<std::vector<std::vector<EdgeContainer*>*>> edges;

    void addNode(N& node) override {
        for (auto &pNode : nodes) 
            if (pNode->equals(node)) 
                throw std::invalid_argument("Node is already present");

        nodes.push_back(node.clone());

        for (int i = 0; i < edges.size(); i++) {
            edges[i].resize(edges.size() + 1);
            edges[i][edges[i].size() - 1] = nullptr;
        }

        edges.push_back(std::vector<std::vector<EdgeContainer*>*>(edges.size() + 1, nullptr));
    }

    void addEdge(E edge) {
        reinterpretNodes(edge.nodes);

        std::vector<EdgeContainer*>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) edgePos = new std::vector<EdgeContainer*>();

        (*edgePos).push_back(new EdgeContainer(edge));
        EdgeContainer* added = (*edgePos).back();
        if (!edge.isDirected) {
            std::reverse(edge.nodes.begin(), edge.nodes.end());

            std::vector<EdgeContainer*>*& revEdgePos = this->at(edge.nodes.front(), edge.nodes.back());
            if (!revEdgePos) revEdgePos = new std::vector<EdgeContainer*>();

            (*revEdgePos).push_back(new EdgeContainer(edge));

            EdgeContainer* nonDirectAdded = (*revEdgePos).back();

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
        reinterpretNodes(chain);
        
        std::vector<EdgeContainer> visitedEdges;
        for (int i = 0; i < chain.size() - 1; i++) {
            auto pedges = findByBeginEndPoint((*chain[i]).getValue(), (*chain[i + 1]).getValue());
            if (pedges == nullptr) return false;
            auto edges = *pedges;

            // Отдаём приоритет направленным рёбрам
            // Можем обратиться к 0 элементу безопасно из-за проверки на маршрут выше.
            EdgeContainer searchEdge;
            bool found = false;
            bool foundDirected = false;
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j]->linked == nullptr && std::find(visitedEdges.begin(), visitedEdges.end(), *edges[j]) == visitedEdges.end()) {
                    foundDirected = true;
                    found = true;
                    visitedEdges.push_back(*edges[j]);
                    break;
                } else if (edges[j]->linked != nullptr && std::find(visitedEdges.begin(), visitedEdges.end(), *edges[j]) == visitedEdges.end()) {
                    found = true;
                    searchEdge = *edges[j];
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
    const std::vector<EdgeContainer*>* findByBeginEndPoint(const NodeValueType begin, const NodeValueType end) {
        return at((*this)[begin], (*this)[end]);
    }

    ~AdjacencyMatrixGraph() override {
        // Удаляем рёбра
        for (auto row : this->edges) {
            for (auto element : row) {
                if (element == nullptr) continue;

                for (auto& container : *element) {
                    delete container;
                }

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
        if (steps < 1) {
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
        for (int i = 0; i < nodes.size(); i++)
            for (int j = 0; j < nodes.size(); j++) 
                count += countAllRoutesBetweenTwoNodes(i, j, steps);


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
            
            for (auto &route : routes) {
                route.route.insert(route.route.begin(), start);

                result.push_back(route);
            }
        }

        return result;
    }

    std::vector<PointRoute<N*>> getAllSimpleMaximumChains(N* start) {
        return getAllSimpleMaximumChains(start, {});
    }

    bool isChainBetweenNodesExist(N* start, N* end) {
        int sIndex = -1;
        int eIndex = -1;
        for (int i = 0; i < this->nodes.size() && (sIndex == -1 || eIndex == -1); i++) {
            if (this->nodes[i]->equals(*start)) sIndex = i;
            if (this->nodes[i]->equals(*end))   eIndex = i;
        }

        if (sIndex == -1 || eIndex == -1) throw std::invalid_argument("Node does not belongs to graph");
    
        return isChainBetweenNodesExist(sIndex, eIndex, {});
    }

    bool isHamiltonian();
    bool isEuler();
    Forest<E, N> getSpanningForest();
    Graph<E>* clone();

    int getNodesSize() {
        return this->nodes.size();
    }

    ShortestWay<N, EdgeValueType> getShortestWay(N* start, N* target) {
        int root = -1;
        int end = -1;
        for (int i = 0; i < this->nodes.size() && (root == -1 || end == -1); i++) {
            if (root == -1 && start->equals(*this->nodes[i])) root = i;
            if (end == -1 && target->equals(*this->nodes[i])) end = i;
        }

        if (root == -1 || end == -1) throw std::invalid_argument("Node doesn't belong to graph");

        ShortestWay<N, EdgeValueType> result;
        result.rootNodeIndex = root;
        result.endNodeIndex = end;

        // Шаг 1
        for (int i = 0; i < this->nodes.size(); i++) {
            result.reachableNodes.push_back(i == root);
            result.distances.push_back(i == root ? 0 : std::numeric_limits<EdgeValueType>::max());
            result.prevNodesIndices.push_back(i == root ? root : -1);
            result.nodes.push_back(*this->nodes[i]);
        }

        // Шаг 4
        // Условие root != end было заменено, чтобы строить полное дерево кратчайших путей.
        while (true) {
            // Шаг 2
            for (int i = 0; i < this->nodes.size(); i++) {
                if (this->edges[root][i] == nullptr || result.reachableNodes[i]) continue;

                for (auto& edge : *this->edges[root][i]) {
                    EdgeValueType dist = result.distances[root] + edge->current.name;
                    if (dist > result.distances[i]) continue;
                
                    result.distances[i] = dist;
                    result.prevNodesIndices[i] = root;
                }
            }

            // Шаг 3
            int minLenNode = -1;
            for (int i = 0; i < this->nodes.size(); i++) {
                if (result.reachableNodes[i]) continue;

                if (minLenNode == -1) {
                    minLenNode = i;
                    continue;
                }

                if (result.distances[minLenNode] > result.distances[i])
                    minLenNode = i;
            }

            if (minLenNode == -1 || result.distances[minLenNode] == std::numeric_limits<EdgeValueType>::max()) break;

            result.reachableNodes[minLenNode] = true;

            root = minLenNode;
        }  

        return result;
    }

private:
    bool hasHamiltonianCycle(int originIndex, int startIndex, std::vector<bool>& takenNodes);
    bool hasEulerCycle(int originIndex, int startIndex, 
std::vector<std::vector<bool>>& visited, int visitedSize, int totalEdgesCount);

    bool isChainBetweenNodesExist(int start, int end, std::set<EdgeContainer*> visitedEdges) {
        if (start == end) return true;
        
        for (int i = 0; i < this->nodes.size(); i++) {
            if (this->edges[start][i] == nullptr) continue;;

            for (auto& edge : *this->edges[start][i]) {
                if (visitedEdges.find(edge) != visitedEdges.end()) continue;

                std::set<EdgeContainer*> newVisitedEdges(visitedEdges);
                newVisitedEdges.insert(edge);

                if (edge->linked != nullptr) newVisitedEdges.insert(edge->linked);
            
                if (isChainBetweenNodesExist(i, end, newVisitedEdges)) return true;
            }
        }

        return false;
    }

    int countAllRoutesBetweenTwoNodes(int start, int end, int steps) {
        if (steps <= 1) {
            return edges[start][end] != nullptr;
        }

        int count = 0;
        for (int i = 0; i < edges.size(); i++) {
            count += countAllRoutesBetweenTwoNodes(start, i, steps - 1) * (edges[i][end] != nullptr);
        }

        return count;
    }

    std::vector<PointRoute<N*>> getAllSimpleMaximumChains(N* start, std::vector<N*> takenNodes) {
        std::vector<PointRoute<N*>> result;
        takenNodes.push_back(start);

        bool anyElementFound = false;
        for (auto &adjNode : getAdjacentNodes(start)) {
            if (std::find(takenNodes.begin(), takenNodes.end(), adjNode) != takenNodes.end()) continue;
 
            anyElementFound = true;
            auto adjacentNodesForCurrentNode = getAdjacentNodes(adjNode);
            
            auto routes = getAllSimpleMaximumChains(adjNode, takenNodes);
            for (auto &route : routes) {
                route.route.insert(route.route.begin(), start);

                result.push_back(route);
            }
        }

        if (!anyElementFound) {
            result.push_back(PointRoute<N*>({start}));
        }

        return result;
    }

    void deleteEdge(E edge, bool nonDirectionalDelete) {
        reinterpretNodes(edge.nodes);

        std::vector<EdgeContainer*>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) throw std::invalid_argument("Edge doesn't exist in graph");
        
        
        for (int i = 0; i < (*edgePos).size(); i++) {
            EdgeContainer*& currentEdge = (*edgePos)[i];

            if (!currentEdge->current.equals(edge)) continue;

            if (!edge.isDirected && !nonDirectionalDelete) {
                deleteEdge(currentEdge->linked->current, true);
            }
            
            delete currentEdge;
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

    std::vector<EdgeContainer*>*& at(N* from, N* to) {
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