#ifndef GRAPH
#define GRAPH

#include "node.tpp"
#include "edge.tpp"

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
    //virtual bool isChain(std::vector<N*> chain);
    //virtual bool isSimpleChain(std::vector<N*> simpleChain);
    //virtual bool isCycle(std::vector<N*> cycle);
    //virtual bool isSimpleCycle(std::vector<N*> simpleCycle);
};

template <typename E, typename N = typename E::NodeType>
class AdjacencyMatrixGraph : public Graph<E, N> {
public:
    using NodeValueType = typename N::NodeValueType;

    std::vector<N*> nodes;
    std::vector<std::vector<std::vector<E>*>> edges;

    void addNode(N& node) override {
        for (auto &pNode : nodes) 
            if (pNode->equals(node)) 
                throw std::invalid_argument("Node is already present");

        nodes.push_back(node.clone());

        for (int i = 0; i < edges.size(); i++) {
            edges[i].resize(edges.size() + 1);
            edges[i][edges[i].size() - 1] = nullptr;
        }

        edges.push_back(std::vector<std::vector<E>*>(edges.size() + 1, nullptr));
    }

    void addEdge(E edge) {
        addEdge(edge, false);
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

    // Ищет среди вершин нужную с value. Если вершина не найдена - возвращает null. Иначе - возвращает ссылку на него. 
    N* operator[](const NodeValueType value) {
        for (auto &n : this->nodes) 
            if (n->getValue() == value)
                return n;
        
        return nullptr;
    }

    // Ищет и возвращает указатель на массив, все грани в котором начинаются с точки с значением a и заканчивается b
    const std::vector<E>* findByBeginEndPoint(const NodeValueType begin, const NodeValueType end) {
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
private:
    void deleteEdge(E edge, bool nonDirectionalDelete) {
        reinterpretNodes(edge.nodes);

        std::vector<E>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) throw std::invalid_argument("Edge doesn't exist in graph");
        
        
        for (int i = 0; i < (*edgePos).size(); i++) {
            E& currentEdge = (*edgePos)[i];

            if (!currentEdge.equals(edge)) continue;

            for (auto &name : edge.names) {
                auto namePos = std::find(currentEdge.names.begin(), currentEdge.names.end(), name);
                if (namePos == currentEdge.names.end()) throw std::invalid_argument("Edge doesn't exist in graph");

                currentEdge.names.erase(namePos);
            }

            if (currentEdge.names.size() == 0) (*edgePos).erase((*edgePos).begin() + i);
            if ((*edgePos).size() == 0) {
                delete edgePos;
                edgePos = nullptr;
            }

            if (!nonDirectionalDelete && !edge.isDirected) {
                std::reverse(edge.nodes.begin(), edge.nodes.end());
                deleteEdge(edge, true);
            }

            return;
        }

        throw std::invalid_argument("Edge doesn't exist in graph");
    }

    void addEdge(E edge, bool nonDirectionalAdd) {
        reinterpretNodes(edge.nodes);

        std::vector<E>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) edgePos = new std::vector<E>();

        for (auto& graphEdge : *edgePos)
            // Два случая - либо мы нашли Edge, тогда просто добавляем ему новое имя...
            if (graphEdge.equals(edge)) {
                for (auto &name : edge.names) 
                    graphEdge.addName(name);

                if (!nonDirectionalAdd && !edge.isDirected) {
                    std::reverse(edge.nodes.begin(), edge.nodes.end());
                    addEdge(edge, true);
                }

                return;
            }

        // Либо добавляем Edge в массив
        (*edgePos).push_back(edge);

        if (!nonDirectionalAdd && !edge.isDirected) {
            std::reverse(edge.nodes.begin(), edge.nodes.end());
            addEdge(edge, true);
        }
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

    std::vector<E>*& at(N* from, N* to) {
        if (from == nullptr || to == nullptr) throw std::invalid_argument("Node is not present");

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