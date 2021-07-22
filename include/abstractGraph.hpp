// abstract class for Graph Data Structure

#pragma once

struct Vertex
{
    int value;
    Vertex *next;
    Vertex():value(NULL), next(NULL){}
    Vertex(int v, Vertex n):value(v), next(n){}
};

class AbstractGraph{
public:
    virtual bool isEmpty() const = 0;
    virtual bool isDirected() const = 0;
    virtual void addVertex(Vertex newVertex) = 0;
    virtual void addEdge(Vertex v1, Vertex v2) = 0;
    virtual Vertex removeVertex(Vertex vertexToRemove) = 0;
    virtual void removeEdge(Vertex v1, Vertex v2) = 0;
    virtual int numVertices() const = 0;
    virtual int numEdges() const = 0;
    virtual int indegree(Vertex v) const = 0;
    virtual int outdegree(Vertex v) const = 0;
    virtual int degree(Vertex v) const = 0;
    virtual *Vertex neighbours(Vertex v) const = 0;
    virtual bool neighbour(Vertex v1, Vertex v2) const = 0;
};