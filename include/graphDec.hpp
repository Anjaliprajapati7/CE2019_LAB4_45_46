#pragma once

#include "abstractGraph.hpp"

class Graph : public AbstractGraph{
private:
    Vertex *HEAD = nullptr;
    unsigned int size = 0;
public:
    bool isEmpty() const override;
    bool isDirected() const override;
    void addVertex(Vertex newVertex) override;
    void addEdge(Vertex v1, Vertex v2) override;
    void removeVertex(Vertex vertexToRemove) override;
    void removeEdge(Vertex v1, Vertex v2) override;
    int numVertices() const override;
    int numEdges() const override;
    int indegree(Vertex v1) const override;
    int outdegree(Vertex v1) const override;
    int degree(Vertex v1) const override;
    List neighbours(Vertex v1) const override;
    bool neighbour(Vertex v1, Vertex v2) const override;
};