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
};

template <typename E, typename N = typename E::NodeType>
class AdjacencyMatrixGraph : public Graph<E, N> {
public:
    using NodeValueType = typename N::NodeValueType;

    std::vector<N*> nodes;
    std::vector<std::vector<std::vector<E>*>> edges;

    void addNode(N& node) override {
        for (auto &pNode : nodes) 
            if (*pNode == node) 
                throw std::invalid_argument("Node is already present");

        nodes.push_back(node.clone());

        for (int i = 0; i < edges.size(); i++) {
            edges[i].resize(edges.size() + 1);
            edges[i][edges[i].size() - 1] = nullptr;
        }

        edges.push_back(std::vector<std::vector<E>*>(edges.size() + 1, nullptr));
    }

    void addEdge(E edge) {
        reinterpretEdgeNodes(edge);

        std::vector<E>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) edgePos = new std::vector<E>();

        for (auto& graphEdge : *edgePos)
            // Два случая - либо мы нашли Edge, тогда просто добавляем ему новое имя...
            if (graphEdge.nodes == edge.nodes) {
                for (auto &name : edge.names) 
                    graphEdge.addName(name);

                return;
            }

        // Либо добавляем Edge в массив
        (*edgePos).push_back(edge);
    }

    void deleteEdge(E edge) {
        reinterpretEdgeNodes(edge);

        std::vector<E>*& edgePos = this->at(edge.nodes.front(), edge.nodes.back());
        if (!edgePos) throw std::invalid_argument("Edge doesn't exist in graph");
        
        
        for (int i = 0; i < (*edgePos).size(); i++) {
            E& currentEdge = (*edgePos)[i];

            if (currentEdge.nodes != edge.nodes) continue;

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

            return;
        }

        throw std::invalid_argument("Edge doesn't exist in graph");
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
    // Обновляет вершины в edge, делая так, чтобы они принадлежали graph. Выбрасывает ошибку, если вершины не существует.
    void reinterpretEdgeNodes(E& edge) {
        for (int i = 0; i < edge.nodes.size(); i++) {
            auto pNode = this->operator[](edge.nodes[i]->getValue());

            if (pNode == nullptr)
                throw std::invalid_argument("Node does not belongs to graph");

            edge.nodes[i] = pNode;
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