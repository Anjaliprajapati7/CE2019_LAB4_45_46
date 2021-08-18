#include <iostream>
#include "graphDec.hpp"


bool Graph::isEmpty() const{
    // if HEAD == nullptr return true
    if (HEAD == nullptr && graphSize == 0) return true;
    else return false;
}

bool Graph::isDirected() const{
    // *return false if all edges go from
    // v1 to v2 as well as v2 to v1
     Vertex *temp1 = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        Vertex *temp2 = HEAD;
        for (size_t j = 0; j < temp1->neighbours.size(); j++)
        {
            auto h = temp1->neighbours.getHead();
            int f1 = h->info;
            if (temp2->value == f1)
            {
                if(!temp2->neighbours.search(temp1->value))
                {
                    return true;
                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        
    }
    
    return false;
}

void Graph::addVertex(Vertex newVertex){
    // add new vertex and point its next to HEAD
    // then point the HEAD to the address of new vertex
    auto *newV = new Vertex();
    newV->value = newVertex.value;
    newV->neighbours = newVertex.neighbours;
    newV->next = HEAD;
    HEAD = newV;
    graphSize++;
}

void Graph::addEdge(Vertex v1, Vertex v2){
    // add the edge to the list of associated vertex
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (v1.value == temp->value)
        {
            temp->neighbours.addToHead(v2.value);
            break;
        }
        else
        {
            temp = temp->next;
        }
        
    }

}

void Graph::removeVertex(Vertex vertexToRemove){
    // delete the Vertex and also 
    // remove all the occurances of the value from neighbours of other vertices
    if (HEAD->value == vertexToRemove.value)
    {
        delete HEAD;
        HEAD = nullptr;
        graphSize = 0;
    }
    else
    {
        Vertex *temp, *prev;
        prev = HEAD;
        temp = HEAD->next;
        for (size_t i = 0; i < graphSize; i++)
        {
            if (vertexToRemove.value == temp->value)
            {
                prev->next = temp->next;
                delete temp;
                graphSize--;
                break;
            }
            else
            {
                prev = prev->next;
                temp = temp->next;
            }
            
        }
    }
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (temp->neighbours.search(vertexToRemove.value))
        {
            temp->neighbours.remove(vertexToRemove.value);
        }
        temp = temp->next;
    }
    
}

void Graph::removeEdge(Vertex v1, Vertex v2){
    // remove the element from the list of neighbours of associated vertex
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (temp->value == v1.value)
        {
            temp->neighbours.remove(v2.value);
            return;
        }
        temp = temp->next;
    }
}

int Graph::numVertices() const{
    // return size of Graph
    return graphSize;
}


int Graph::numEdges() const{
    // sum of all the neighbour lists
    int count = 0;
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        count += temp->neighbours.size();
        temp = temp->next;
    }
    return count;
}


int Graph::indegree(Vertex v1) const{
    // sum of all the occuraces of vertex v in neighbours of other vertices
    int count = 0;
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (temp->neighbours.search(v1.value))
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}


int Graph::outdegree(Vertex v1) const{
    // size of neighbour list
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (temp->value == v1.value)
        {
            return temp->neighbours.size();
        }
        else
        {
            temp = temp->next;
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
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (v1.value == temp->value)
        {
            return temp->neighbours;
        }
        temp = temp->next;
    }
}

bool Graph::neighbour(Vertex v1,Vertex v2) const{
    // returns true if v2 exists in neighbour list of v1 and vice versa
    Vertex *temp = HEAD;
    for (size_t i = 0; i < graphSize; i++)
    {
        if (v1.value == temp->value)
        {
            return temp->neighbours.search(v2.value);
        }
        else
        {
            temp = temp->next;
        }
        
    }
    return false;
}