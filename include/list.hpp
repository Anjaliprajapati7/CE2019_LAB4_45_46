// interface class
#pragma once

#include "node.hpp"

class List
{
private:
    Node *HEAD;
    Node *TAIL;
    int listSize = 0;
public:
    List(){
        HEAD = nullptr;
        TAIL = nullptr;
    };
    ~List(){};
    bool isEmpty();
    void addToHead(int data);
    void addToTail(int data);
    void add(int data, Node *predecessor);
    void removeFromHead();
    void removeFromTail();
    void remove(int data);
    bool search(int data);
    Node *retrieve(int data);
    void traverse();
    int size();
    Node *getHead();
};