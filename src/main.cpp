#include <iostream>
#include "graphDec.hpp"

using std::cout;

int main(){
    Graph g1;
    Vertex vn;
    vn(5, NULL, NULL);
    g1.addVertex(vn);
    cout << g1.isEmpty();
    return 0;
}