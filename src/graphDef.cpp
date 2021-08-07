#include <iostream>
#include "graphDec.hpp"

bool Graph::isEmpty() const{
    // if occupied == 0 return true
    if (this->occupied == 0) return true;
    else return false;
}

bool Graph::isDirected() const{
    // *return false if all edges go from
    // v1 to v2 as well as v2 to v1
    return true;

}

void Graph::addVertex(Vertex newVertex){
    // add the vertex at new position in v array
    this->v[this->occupied] = newVertex;
    this->occupied++;
}

void addEdge(Vertex v1, Vertex v2){
    // add the edge to the list of v1
    for (size_t i = 0; i <= this->occupied; i++)
    {
        if (v[i].value == v1.value)
        {
            v[i].neighbours.push_back(v2.value);
        }
    }
}

void Graph::removeVertex(Vertex vertexToRemove){
    // remove the vertex at v[position] and also
    // remove all other occurances of vertex from the list of neighbours
    for (size_t i = 0; i < this->occupied; i++)
    {
        if (v[i].value == vertexToRemove.value)
        {
            v[i].value = v[occupied].value;
            v[i].neighbours = v[occupied].neighbours;
            v[i].um = v[occupied].um;

            v[occupied].value = NULL;
            v[occupied].neighbours.clear();
            v[occupied].um.clear();

            this->occupied--;

            // if (i != this->occupied)
            // {
            //     for (size_t j = i; j <= occupied; j++)
            //     {
            //         v[j].value = v[j+1].value;
            //         v[j].neighbours = v[j+1].neighbours;
            //         v[j].um = v[j+1].um;
            //     }
                
            // }
            
        }
        
    }
    
}

void Graph::removeEdge(Vertex v1, Vertex v2){
    // remove the element from the list of neighbours of v1
    for (size_t i = 0; i <= occupied; i++)
    {
        if (v[i].value == v1.value){
            v1.neighbours.remove(v2.value);
        }
    }
    
}

int Graph::numVertices() const{
    // get all the vertices from array v that are not NULL
    return occupied + 1;
}


int Graph::numEdges() const{
    // get sum of all the list associated with array v
    unsigned int sum = 0;
    for (size_t i = 0; i <= occupied; i++)
    {
        sum += v[i].neighbours.size();
    }
    return sum;
}


int Graph::indegree(Vertex v1) const{
    // sum of all the occuraces of vertex v in neighbours of other vertices
    return 0;
}


int Graph::outdegree(Vertex v1) const{
    // size of neighbour list
    for (size_t i = 0; i <= occupied; i++)
    {
        if (v[i].value == v1.value)
        {
            return v[i].neighbours.size();
        }
    }
    return 0;
}

int Graph::degree(Vertex v1) const{
    // sum of indegree and outdegree
    return indegree(v1)+outdegree(v1);
}

List Graph::neighbours(Vertex v1) const{
    // return the neighbour list associated with the vertex
    for (size_t i = 0; i <= occupied; i++)
    {
        if (v[i].value == v1.value)
        {
            return v[i].neighbours;
        }
    }
    return {NULL};
}

bool Graph::neighbour(Vertex v1,Vertex v2) const{
    // returns true if v2 exists in neighbour list of v1 and vice versa
    for (size_t i = 0; i <= occupied; i++)
    {
        if (v[i].value == v1.value)
        {
            for (auto &&i : v[i].neighbours)
            {
                if (i == v2.value)
                {
                    return true;
                }
            }
        }
        else if (v[i].value == v2.value)
        {
            for (auto &&i : v[i].neighbours)
            {
                if (i == v1.value)
                {
                    return true;
                }
            }
        }
    }
    return false;
}