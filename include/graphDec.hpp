#pragma once

class Graph::public AbstractGraph{
public:
    bool isEmpty() const = 0;
    bool isDirected() const = 0;
    void addVertex(Vertex newVertex) = 0;
    void addEdge(Vertex v1, Vertex v2) = 0;
    Vertex removeVertex(Vertex vertexToRemove) = 0;
    void removeEdge(Vertex v1, Vertex v2) = 0;
    int numVertices() const = 0;
    int numEdges() const = 0;
    int indegree(Vertex v) const = 0;
    int outdegree(Vertex v) const = 0;
    int degree(Vertex v) const = 0;
    *Vertex neighbours(Vertex v) const = 0;
    bool neighbour(Vertex v1, Vertex v2) const = 0;
};