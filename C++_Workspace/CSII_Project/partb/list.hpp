
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
    void delNode(int index); // delete the item at the desired index
    void showList() const; // print the list
    Station loop(int index) const; // grabs data at list
    int find(int id) const; // get the index of something in the array based on id
    int size(); // the size of the current list
};

#endif
