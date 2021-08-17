// implement linked list

#include <iostream>
#include "list.hpp"

using std::cout;
using std::endl;

bool List::isEmpty(){
    if (HEAD == nullptr){
        cout << "Empty!" << endl;
        return true;
    }
//    cout << "Not Empty!" << endl;
    return false;
};
void List::addToHead(int data){
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = HEAD;
    HEAD = newNode;
    if (TAIL == nullptr) TAIL = HEAD;
    listSize++;
};
void List::addToTail(int data){
    if (HEAD == nullptr){
        addToHead(data);
        return;
    }
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = nullptr;
    TAIL->next = newNode;
    TAIL = TAIL->next;
    listSize++;
};
void List::add(int data, Node *predecessor){
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = predecessor->next;
    predecessor->next = newNode;
    listSize++;
};
void List::removeFromHead(){
    if (!isEmpty()){
        Node *nodeToDelete;
        nodeToDelete = HEAD;
        HEAD = nodeToDelete->next;
        delete nodeToDelete;
        if (HEAD == nullptr) TAIL = nullptr;
        listSize--;
    }
};
void List::removeFromTail(){
    Node *pred;
    if (HEAD == TAIL)
        HEAD = TAIL = nullptr;
    else{
        pred = HEAD;
        while (pred->next != TAIL)
            pred = pred->next;
        TAIL = pred;
        pred->next = nullptr;
        listSize--;
    }
};
void List::remove(int data){
    if (!isEmpty()){
        if (HEAD->info == data){
            removeFromHead();
        }
        else{
            Node *temp, *prev;
            temp = HEAD->next;
            prev = HEAD;
            while (temp != nullptr){
                if (temp->info == data) break;
                else{
                    prev = prev->next;
                    temp = temp->next;
                }
            }
            if (temp != nullptr){
                prev->next = temp->next;
                delete temp;
                listSize--;
                if (prev->next == nullptr) TAIL = prev;
            }
        }
    }
};

bool List::search(int data){
    Node *temp;
    temp = HEAD;
    while (temp->info != data){
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Not found!" << endl;
            return false;
        }
    }
    cout << "Found!" << endl;
    return true;
};

Node *List::retrieve(int data){
    Node *temp;
    temp = HEAD;
    while (temp->info != data){
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Error!" << endl;
            break;
        }
    }
    return temp;
};

void List::traverse(){
    Node *p;
    p = HEAD;
    if (!isEmpty()) {
        while (p != nullptr) {
            cout << p->info << "->";
            p = p->next;
        }
        cout << endl;
    }
};

int List::size(){
    return listSize;
};