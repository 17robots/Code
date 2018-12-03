
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
    
    //pre:station is properly defined
    //post: adds a new node to the end of the list
    void appNode(Station &station); // push something onto the list
    
    //pre: index is proprly defined
    //post: deletes a node and rewires it 
    void delNode(int index); // delete the item at the desired index
    
    //pre: none
    //post: displays the list
    void showList() const; // print the list
    
    //pre: index is properly defined
    //post: returns the station at the index
    Station loop(int index) const; // grabs data at list
    
    //pre: id is properly defined
    //post: returns the index of the location of the station that matches id or -1
    int find(int id) const; // get the index of something in the array based on id
    
    //pre: none
    //post: returns the number of elements in the list
    int size() const; // the size of the current list
};

#endif
