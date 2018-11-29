#include "list.hpp"
#include <iostream>

List::List() {
	head = nullptr;
	last = nullptr;
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

void List::delNode(int index) { // really only calling this when we deallocate all of the lists
	Node* currentNode = head;
	Node* previousNode = nullptr;
	int counter = 0;
	if(index >= 0) {
		for(int i = 0; i < index; ++i) {
			if(currentNode->next) {
				previousNode = currentNode;
				currentNode = currentNode->next;
				counter++;
			} else {
				std::cout << "Didn't make it here" << std::endl;
			}
		}
		if(counter == index) {
			// delete the data
			previousNode->next = currentNode->next;
			delete currentNode;
			currentNode = nullptr;
		} else {
			std::cout << "Index too big" << std::endl;
		}
	} else {
		std::cout << "Index too small" << std::endl;
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
				return Station(999, "", 999, 999);
			}
		} else {
			std::cout << "Fail 1" << std::endl;
			return Station(999, "", 999, 999);
		}
	}
