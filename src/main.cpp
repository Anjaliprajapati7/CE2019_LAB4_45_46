#include <iostream>
#include "graphDec.hpp"

using std::cout;
using std::endl;

int main(){
    Graph g1;
    cout << g1.isEmpty() << endl;
    Vertex v1;
    v1.value = 5;
    g1.addVertex(v1);
    cout << g1.isEmpty() << endl;
    return 0;
}