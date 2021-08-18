#include <iostream>
#include <set>
#include <ctime>
#include "graphDec.hpp"

using std::cout;
using std::endl;
using std::set;

// bonus question
Graph randomGen(){
    Graph g;
    Vertex v1, v2, v3, v4, v5;
    set<int> randSet; // using set for unique vertices
    srand(time(NULL));
    while (randSet.size() < 5)
    {
        randSet.insert(rand()%10);
    }
    int randArray[5];
    int c = 0;
    for (auto &&i : randSet)
    {
        randArray[c] = i;
        c++;
    }
    
    v1.value = randArray[0];
    v2.value = randArray[1];
    v3.value = randArray[2];
    v4.value = randArray[3];
    v5.value = randArray[4];

    v1.neighbours.addToHead(randArray[1]);
    v2.neighbours.addToHead(randArray[2]);
    v3.neighbours.addToHead(randArray[3]);
    v4.neighbours.addToHead(randArray[4]);
    v5.neighbours.addToHead(randArray[0]);

    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addVertex(v4);
    g.addVertex(v5);
    return g;
}

int main(){

    Graph g1; //assuming it is an undirected graph
    cout << g1.isEmpty() << endl;

    Vertex v1, v2, v3,v4,v5;
    v1.value = 5;
    v2.value = 6;
    v3.value = 7;
    v4.value = 8;
    v5.value = 9;

    v2.neighbours.addToHead(5);
    v2.neighbours.addToHead(7);
    v2.neighbours.addToHead(9);
    v3.neighbours.addToHead(9);
    v4.neighbours.addToHead(6);
    v4.neighbours.addToHead(9);
    v5.neighbours.addToHead(6);
    v5.neighbours.addToHead(8);

    g1.addVertex(v1);
    g1.addVertex(v2);
    g1.addVertex(v3);
    g1.addVertex(v4);
    g1.addVertex(v5);

    g1.removeVertex(v1);

    cout << "graph size: " << g1.numVertices() << endl;
    cout << "after adding isEmpty: " << g1.isEmpty() << endl;
    cout << "outdegree(v2): " << g1.outdegree(v2) << endl;
    cout << "neighbour(v4,v2): " << g1.neighbour(v4, v2) << endl;

    List l1 = g1.neighbours(v2);
    l1.traverse();
    cout << "indegree of v2: " << g1.indegree(v2) << endl;
    cout << "degree of v2: " << g1.degree(v2) << endl;

    cout << "no. of edges in graph: " << g1.numEdges() << endl;
    g1.removeEdge(v5, v4);
    g1.removeEdge(v4, v2);
    cout << "no. of edges in graph: " << g1.numEdges() << endl;
    cout << "no. of vertices in graph: " << g1.numVertices() << endl;
    cout << "isDirected: " << g1.isDirected() << endl;
    return 0;
}