
#ifndef LIST_HPP
#define LIST_HPP
#include "station.hpp"

class List {
  private:
  struct Node {
      struct Node* next;
      Station data;
  }
  Node * head;
  public:
  List(); // default constructor
  ~List(); // destructor 
  void appNode(Station station); // push something onto the list 
  void delNode(); // pop the last thing off the list
  void showList() const; // print the list
};

#endif