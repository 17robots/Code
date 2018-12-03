#include "list.hpp"
#include <iostream>

List::List() {
	head = new Node;
	head->next = nullptr;
}

List::~List() {
	if(head != nullptr) {
		if(head->next != nullptr) {
				while(head != nullptr) {
					Node* tmpNode = head->next;
					Node* nodeToDelete = head;
					head = tmpNode;
					delete nodeToDelete;
					nodeToDelete = nullptr;
				}
		} else {
			delete head;
			head = nullptr;
		}
	}
}

void List::appNode(Station &station) {
	Node* temp = new Node;
    temp->data = station;
    temp->next = nullptr;

	if(head) {
		if(!head->next) { // empty list becomes the new node
	        head->next = temp;
	        return;
	    } else { // find last and link the new node
	        Node* last = head;
	        while(last->next) {last=last->next;}
	        last->next = temp;
	        std::cout << last->next << std::endl;
	    }
	}
}

void List::delNode(int index) {
	Node* currentNode = head;
	Node* previousNode = nullptr;
	int counter = 0;
	if(index >= 0) {
		for(int i = 0; i < index; ++i) {
			if(currentNode) {
				previousNode = currentNode;
				currentNode = currentNode->next;
				counter++;
			}
		}
		std::cout << "Counter: " << counter << std::endl;
		std::cout << "Index: " << index << std::endl;
		if(counter == index) {
			// delete the data
			if(currentNode->next != nullptr) {
				previousNode->next = currentNode->next;
			} else {
				previousNode->next = nullptr;
			}
			delete currentNode;
			currentNode = nullptr;
		} else {
			std::cout << "Index too big." << std::endl;
		}
	} else {
		std::cout << "Index too small." << std::endl;
	}
}

	void List::showList() const {
		Node * currentNode;
		if(!head) {
			std::cout << "There is no data here" << std::endl;
		} else {
			if(head->next) {
				int counter = 1;
				currentNode = head->next;
				while(currentNode) {
					std::cout << counter << ". ";
					std::cout << currentNode->data;
					currentNode = currentNode->next;
					++counter;
				}
			} else {
				std::cout << "There is no data" << std::endl;
			}
		}
	}

	Station List::loop(int index) const {
		Node* currentNode = head;
		Node* previousNode = currentNode;
		int counter = 0;
		if(index >= 0) {
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
				return Station(-1, "", -1);
			}
		} else {
			return Station(-1, "", -1);
		}
	}

	int List::size() const {
		Node* currentNode = head;
		Node* previousNode = nullptr;
		int counter = 0;
		while(currentNode) {
			if(currentNode) {
				// std::cout << "Made it here" << std::endl;
				previousNode = currentNode;
				currentNode = currentNode->next;
				counter++;
			}
		}
		return counter;
	}

	int List::find(int id) const {
		Node * currentNode;
		if(!head) {
			std::cout << "There is no data here" << std::endl;
		} else {
			if(head->next) {
				int counter = 1;
				currentNode = head->next;
				while(currentNode) {
					if(currentNode->data.getId() == id) {
						return counter;
					}
					currentNode = currentNode->next;
					++counter;
				}
			}
		}
		return -1;
	}
