// abstract class for Graph Data Structure

#pragma once

#include <unordered_map>
#include <list>

using std::unordered_map;
using std::list;

struct Vertex
{
    int value; // stores the value of vertex
    list<int> neighbours; // stores all the neighbours of vertex in a list format
    unordered_map<int, list<int> > um; // maps vertex and its neighbours
    Vertex():value(NULL), neighbours(NULL), um(NULL){}
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
    virtual list<int> neighbours(Vertex v1) const = 0;
    virtual bool neighbour(Vertex v1, Vertex v2) const = 0;
};