#ifndef GRAPH_NODE
#define GRAPH_NODE

template <typename T, typename V>
class NamedNode {
protected:    
    T value;

public:
    using NodeValueType = T;

    V name;

    NamedNode(T value, V name) {
        this->value = value;
        this->name  = name;
    };

    virtual NamedNode<T, V>* clone() {
        return new NamedNode<T, V>(value, name);
    }

    bool operator==(const NamedNode<T, V>& b) const {
        return this->value == b.value;
    }

    const T& getValue() const {
        return value;
    }
};

template <typename T>
class Node : public NamedNode<T, T> {
public:
    Node(T value) : NamedNode<T, T>(value, value) {};

    NamedNode<T, T>* clone() {
        return new Node<T>(this->value);
    }
};

#endif