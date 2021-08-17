// abstract class for Graph Data Structure

#pragma once

#include <list.hpp>

struct Vertex
{
    int value = NULL; // stores the value of vertex
    List neighbours; // stores all the neighbours of vertex in a list format
    Vertex *next; // points to next vertex to form a linked list
    Vertex(){}
    Vertex(int value, List neighbours){
        this->value = value;
        this->neighbours = neighbours;
    }
};

class AbstractGraph{
public:
    virtual bool isEmpty() const = 0;
    virtual bool isDirected() const = 0;
    virtual void addVertex(Vertex newVertex) = 0;
    virtual void addEdge(Vertex v1, Vertex v2) = 0;
    virtual void removeVertex(Vertex vertexToRemove) = 0;
    virtual void removeEdge(Vertex v1, Vertex v2) = 0;
    virtual int numVertices() const = 0;
    virtual int numEdges() const = 0;
    virtual int indegree(Vertex v1) const = 0;
    virtual int outdegree(Vertex v1) const = 0;
    virtual int degree(Vertex v1) const = 0;
    virtual List neighbours(Vertex v1) const = 0;
    virtual bool neighbour(Vertex v1, Vertex v2) const = 0;
};