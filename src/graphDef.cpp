#include <iostream>
#include "graphDec.hpp"

using std::cout;
using std::endl;

bool Graph::isEmpty() const{
    // if all vertices are NULL then the graph is empty
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        if (v[i].value != NULL){
            return false;
        }
    }
    return true;
}

bool Graph::isDirected() const{
    // *return false if all edges go from
    // v1 to v2 as well as v2 to v1

}

void Graph::addVertex(Vertex newVertex){
    // add the vertex at new position in v array

}

void Graph::addEdge(Vertex v1, Vertex v2){
    // add the edge to the list of v1

}

void Graph::removeVertex(Vertex vertexToRemove){
    // remove the vertex at v[position] and also
    // remove all other occurances of vertex from the list of neighbours

}

void Graph::removeEdge(Vertex v1, Vertex v2){
    // remove the element from the list of neighbours of v1
}

int Graph::numVertices() const{
    // get all the vertices from array v that are not NULL
}


int Graph::numEdges() const{
    // get sum of all the list associated with array v
}


int Graph::indegree(Vertex v) const{
    // sum of all the occuraces of vertex v in neighbours of other vertices
}


int Graph::outdegree(Vertex v) const{
    // size of neighbour list
}

int Graph::degree(Vertex v) const{
    // sum of indegree and outdegree
}

list<int> Graph::neighbours(Vertex v) const{
    // return the neighbour list associated with the vertex
}

bool Graph::neighbour(Vertex v1,Vertex v2) const{
	// returns true if v2 exists in neighbour list of v1 and vice versa
}