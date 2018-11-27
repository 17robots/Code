#include "list.hpp"
#include <iostream>

List::List() {
    head = nullptr;
    last = nullptr;
}

List::~List() {
    if(head == nullptr) {
        
    } else {
        while(head->next) {
            this->delNode();
        }   
    }
}

void List::appNode(Station station) {
    Node* newNode;  
    Node* currentNode;
    Node* previousNode;
    newNode = new Node;
    newNode->data = station;
    newNode->next = nullptr;
    
    if(head) {
        currentNode = head;
        while(currentNode) {
            previousNode = currentNode;
            if(currentNode)
            currentNode = currentNode->next;
        }
        previousNode->next = newNode; 
    } else {
	head = newNode;
    }
}

void List::delNode() { // really only calling this when we deallocate all of the lists
    Node* currentNode;
    Node* previousNode;
    
    if(head) {
        currentNode = head;
        while(currentNode) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        delete previousNode->next;
        previousNode->next = nullptr;
    }
}

void List::showList() const {
    Node * currentNode;
    if(!head) {
        std::cout << "There is no data here" << std::endl;
    } else {
        if(head->next) {
            currentNode = head;
            while(currentNode) {
                std::cout << currentNode->data;
                currentNode = currentNode->next;
            }
        } else {
            std::cout << "There is no data here" << std::endl;
        }
    }
}

Station List::loop(int index) const {
    Node* currentNode = head;
    Node* previousNode = nullptr;
    int counter = 0;
    if(index > 0) {
        for(int i = 0; i < index; ++i) {
            if(currentNode) {
                std::cout << "Made it here" << std::endl;
                previousNode = currentNode;
                currentNode = currentNode->next;
                counter++;
            } else {
                std::cout << "Didn't make it here" << std::endl;
            }
        }
        std::cout << "counter: " << counter << " index: " << index << std::endl;
         if(counter == index) {
            return previousNode->data;
        } else {
            return Station(999, "", 999, 999);
        }
    } else {
        std::cout << "Fail 1" << std::endl;
        return Station(999, "", 999, 999);
    }
}
