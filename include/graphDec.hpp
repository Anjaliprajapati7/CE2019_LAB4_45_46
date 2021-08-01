#pragma once

#include "abstractGraph.hpp"

class Graph:public AbstractGraph{
public:
    bool isEmpty() const = 0;
    bool isDirected() const = 0;
    void addVertex(struct Vertex newVertex) = 0;
    void addEdge(struct Vertex v1, struct Vertex v2) = 0;
    void removeVertex(struct Vertex vertexToRemove) = 0;
    void removeEdge(struct Vertex v1, struct Vertex v2) = 0;
    int numVertices() const = 0;
    int numEdges() const = 0;
    int indegree(struct Vertex v) const = 0;
    int outdegree(struct Vertex v) const = 0;
    int degree(struct Vertex v) const = 0;
    list<int> neighbours(Vertex v) const = 0;
    bool neighbour(struct Vertex v1, struct Vertex v2) const = 0;
};