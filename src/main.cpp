#include <iostream>
#include "graphDec.hpp"

using std::cout;
using std::endl;

int main(){
    Graph g1;
    cout << g1.isEmpty() << endl;

    Vertex v1, v2, v3;
    v1.value = 5;
    v2.value = 6;
    v3.value = 7;
    v2.neighbours.addToHead(6);
    v2.neighbours.addToHead(5);
    v2.neighbours.addToHead(7);
    g1.addVertex(v1);
    g1.addVertex(v2);
    g1.addVertex(v3);
    g1.removeVertex(v1);

    cout << g1.numVertices() << endl;
    cout << g1.isEmpty() << endl;
    cout << g1.outdegree(v2) << endl;

    cout << g1.neighbour(v2, v1);
    return 0;
}