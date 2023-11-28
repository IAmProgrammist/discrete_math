#ifndef GRAPH_EDGE
#define GRAPH_EDGE

template <typename T, typename V>
class NamedEdge {
public:
    using NodeType = T;
    using NameType = V;

    std::vector<T*> nodes;
    std::vector<V> names;
    bool isDirected;

    NamedEdge(std::initializer_list<T*> nodes, V name, bool isDirected) {
        if (nodes.size() < 2) throw std::invalid_argument("You can't create edge with less than two nodes");
        this->nodes.insert(this->nodes.begin(), nodes.begin(), nodes.end());
        names.push_back(name);
        this->isDirected = isDirected;
    }

    virtual void addName(V& name) {
        names.push_back(name);
    }

    virtual bool equals(const NamedEdge<T, V>& b) const {
        if (isDirected != b.isDirected || nodes.size() != b.nodes.size()) return false;

        for (int i = 0; i < nodes.size(); i++)
            if (!(*this->nodes[i]).equals(*b.nodes[i])) return false;
        
        return true;
    }
};

template <typename T>
class Edge : public NamedEdge<T, std::string> {
public:
    Edge(std::initializer_list<T*> nodes, bool isDirected) : NamedEdge<T, std::string>(nodes, "", isDirected) {};

    void addName(std::string& name) {
        this->addName();
    }

    void addName() {
        this->names.push_back("");
    }
};

#endif