
#ifndef LIST_HPP
#define LIST_HPP
#include "station.hpp"

class List {
  private:
    struct Node {
        Node* next;
        Station data;
    };
    Node* head;
    Node* last;
  public:
    List(); // default constructor
    ~List(); // destructor 
    void appNode(Station station); // push something onto the list 
    void delNode(); // pop the last thing off the list
    void showList() const; // print the list
    Station loop(int index) const; // grabs data at list
};

#endif
