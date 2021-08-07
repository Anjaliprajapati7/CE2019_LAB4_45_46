#pragma once

#include "abstractGraph.hpp"

#define MAX_SIZE 10 // max no. of nodes in a graph

class Graph:public AbstractGraph{
private:
    Vertex v[MAX_SIZE];
    Vertex *HEAD = nullptr;
public:
    bool isEmpty() const = 0;
    bool isDirected() const = 0;
    void addVertex(Vertex newVertex) = 0;
    void addEdge(Vertex v1, Vertex v2) = 0;
    void removeVertex(Vertex vertexToRemove) = 0;
    void removeEdge(Vertex v1, Vertex v2) = 0;
    int numVertices() const = 0;
    int numEdges() const = 0;
    int indegree(Vertex v1) const = 0;
    int outdegree(Vertex v1) const = 0;
    int degree(Vertex v1) const = 0;
    List neighbours(Vertex v1) const = 0;
    bool neighbour(Vertex v1, Vertex v2) const = 0;
};