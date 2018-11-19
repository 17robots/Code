#include "list.hpp"
#include <iostream>

List::List() {
    head = nullptr;
}

List::~List() {
    while(head->next != nullptr) {
        this->delNode();
    }
    
    delete head;
    head = nullptr;
}

void List::appNode(Station station) {
    Node * newNode; 
    Node * currentNode;
    Node * previousNode;
    previousNode = nullptr;
    
    newNode = new Node;
    newNode->data = station;
    if(!head) {
        head = newNode;
    } else {
        currentNode = head;
        while(currentNode != nullptr) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        previousNode->next = newNode;
        newNode->next = nullptr;
    }
}

void List::delNode() { // really only calling this when we deallocate all of the lists
    Node * currentNode; 
    Node * previousNode;
    
    if(head == nullptr) {
        currentNode = head;
    } else {
        currentNode = head;
        while(currentNode->next != nullptr) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        delete currentNode;
        currentNode = nullptr;
        previousNode->next = nullptr;
    }
    
}

void List::showList() const {
    Node * currentNode;
    if(!head) {
        std::cout << "There is no data here" << std::endl;
    } else {
        currentNode = head;
        while(!currentNode->next) {
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
    }
}