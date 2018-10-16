#include <iostream>

template <class T>
struct Node {
    T data;
   Node * next;
   Node() {
       next = NULL;
   }
   Node(T Data) {
       next = NULL;
       data = Data;
   }
   
   ~Node() {
       
   }
   
   void add() {
       if(next != NULL) {
           Node * tmp = next;
           next = new Node();
           next->next = tmp;
       } else {
           next = new Node();
           next->next = NULL;
       }
   }
   
   void add(T Data) {
       if(next != NULL) {
           Node * tmp = next;
           next = new Node(Data);
           next->next = tmp;
       } else {
           next = new Node(Data);
           next->next = NULL;
       }
   }
   
   void remove() {
       if(next != NULL) {
           
       } else {
           
       }
   }
   
   void append() {
       Node * tmp = next;
       while(next) {
           tmp = next->next;
       }
       
       tmp->next = new Node();
       tmp->next->next = NULL;
   }
   
   void append(T Data) {
       Node * tmp = next;
       while(next) {
           tmp = next->next;
       }
       
       tmp->next = new Node(Data);
       tmp->next->next = NULL;
   }
   
   T getData() {
       return data;
   }
} *head = new Node();

int main() {
    return 0;
}