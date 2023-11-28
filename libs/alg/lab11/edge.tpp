#ifndef GRAPH_EDGE
#define GRAPH_EDGE

template <typename T, typename V>
class NamedEdge {
public:
    using NodeType = T;
    using NameType = V;

    std::vector<T*> nodes;
    std::vector<V> names;

    NamedEdge(std::initializer_list<T*> nodes, V name) {
        if (nodes.size() < 2) throw std::invalid_argument("You can't create edge with less than two nodes");
        this->nodes.insert(this->nodes.begin(), nodes.begin(), nodes.end());
        names.push_back(name);
    }

    virtual void addName(V& name) {
        names.push_back(name);
    }

    bool operator==(const T& b) const {
        for (auto &n : this->nodes)
            if (*n != *b) return false;
        
        return true;
    }
};

template <typename T>
class Edge : public NamedEdge<T, std::string> {
public:
    Edge(std::initializer_list<T*> nodes) : NamedEdge<T, std::string>(nodes, "") {};

    void addName(std::string& name) {
        this->addName();
    }

    void addName() {
        this->names.push_back("");
    }

    bool operator==(const T& b) const {
        return NamedEdge<T, std::string>::operator==(b);
    }
};

#endif