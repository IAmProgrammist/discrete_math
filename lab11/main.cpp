#include "../libs/alg/alg.h"

typedef NamedNode<int, std::string> IntNode;

class IntCoolerNode : public NamedNode<int, std::string> {
public:
    int veryCoolId;

    IntCoolerNode(int veryCoolId, int value, std::string name) : NamedNode<int, std::string>(value, name), veryCoolId(veryCoolId) {};

    void print() {
        std::cout << this->name << " " << this->veryCoolId << "\n";
    }

    NamedNode<int, std::string>* clone() {
        return new IntCoolerNode(veryCoolId, value, name);
    }
};

int main() {
    AdjacencyMatrixGraph<Edge<IntNode>> graph;
    IntNode f0(11, "A");
    IntNode f1(12, "B");
    IntNode f2(13, "C");
    IntNode f3(14, "D");
    
    graph.addNode(f0);
    graph.addNode(f1);
    graph.addNode(f2);
    graph.addNode(f3);
    
    graph.addEdge({&f0, &f3});
    graph.addEdge({&f0, &f2, &f3});
    graph.addEdge({&f0, &f0});

    try {
        graph.deleteEdge({&f1, &f1});
        assert(false);
    } catch (std::invalid_argument& exception) {
        std::cout << "Yo mister white yo" << std::endl;
    }

    graph.deleteNode(f1);

    graph.deleteEdge({&f0, &f0});
    try {
        graph.deleteEdge({&f0, &f0});
        assert(false);
    } catch (std::invalid_argument& exception) {
        std::cout << "Yo mister white yo" << std::endl;
    }

    graph.deleteEdge({&f0, &f3});
    assert(graph.findByBeginEndPoint(f0.getValue(), f3.getValue()) != nullptr);
    assert((*graph.findByBeginEndPoint(f0.getValue(), f3.getValue()))[0].nodes.size() == 3);
    try {
        graph.deleteEdge({&f0, &f3});
        assert(false);
    } catch (std::invalid_argument& exception) {
        std::cout << "Yo mister white yo" << std::endl;
    }

    graph.deleteEdge({&f0, &f2, &f3});
    assert(graph.findByBeginEndPoint(f0.getValue(), f3.getValue()) == nullptr);
    try {
        graph.deleteEdge({&f0, &f2, &f3});
        assert(false);
    } catch (std::invalid_argument& exception) {
        std::cout << "Yo mister white yo" << std::endl;
    }

    return 0;
}