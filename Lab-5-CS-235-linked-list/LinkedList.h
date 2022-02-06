#pragma once
#include "LinkedListInterface.h"
#include <string>
#include <sstream>

template <class T>

class LinkedList: public LinkedListInterface<T> {
  public:
  struct Node {
    T item;
    Node* next;
	Node (const T data, Node* next_val = NULL) : //Constructor
		item(data) {next = next_val;}
  };
  Node* head;
  int num_items;

  LinkedList() {
	  head = NULL;
	  num_items = 0;
  }

  ~LinkedList() {
	  clear();
  }

/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) {
		if(head == NULL){
			head = new Node(value, NULL);
			num_items++;
			return;
		}
		for (Node *ptr = head; ptr != NULL; ptr = ptr->next) { //Duplicate value testing
			if (ptr->item == value) {
				cout << "Value is already in the list\n";
				return;
			}
		}
		Node* ptr = head;
		head = new Node(value);
		head -> next = ptr;
		num_items++;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
		if(head == NULL) {
			head = new Node(value, NULL);
			num_items++;
			return;
		}
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) { //Duplicate value testing
			if (ptr->item == value) {
				cout << "Value is already in the list\n";
				return;
			}
		}
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->next == NULL) {
				ptr->next = new Node(value);
				ptr->next->next = NULL;
				num_items++;
				return;
			}
		}
	}


	void insertAfter(T value, T insertionNode) {
		if(head == NULL) {
			head = new Node(value, NULL);
			num_items++;
			return;
		}
		for (Node *ptr = head; ptr != NULL; ptr = ptr->next) { //Duplicate value testing
			if (ptr->item == value) {
				cout << "Value is already in the list\n";
				return;
			}
		}
		for (Node *ptr = head; ptr != NULL; ptr = ptr->next) { 
			if (ptr->item == insertionNode) {
				Node* bob = new Node(value);
				bob->next = ptr->next;	// Step 1 
				ptr->next = bob;	 //Step 2
				num_items++;
				break;
			}
		}
	}

  void remove(T value) {
	if (num_items == 0) {
		return;
	}
	if (head->item == value) {
		Node* current = head;
		head = head->next;
		delete current;
		//head = NULL;
		num_items--;
	} else {
		for (Node *ptr = head; ptr->next != NULL; ptr = ptr->next) {
			if (ptr->next->item == value) {
				Node *current = ptr->next;
		  		ptr->next = ptr->next->next;
		  		delete current;
				num_items--;
				return;
			}
		}
	}
  }


	void clear() {
		/*if (num_items == 0) {
			return;
		}*/
		while (head != NULL) {
			Node* current = head;
		  	head = head->next;
		  	delete current;
			//head = NULL;
		}
		//head = NULL;
		num_items = 0;
	}
	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
		int i = 0;
		if (index >= num_items) {
			throw std::out_of_range("Out of range");
		} else {
			for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
				if (i == index) {
					return T(ptr->item);
				}
				i++;
			}
		}
		throw std::out_of_range("Doesn't exist");
	}
	

	int size(){
		//cout << "In size"<<endl; 
		return(num_items);
	};


	string toString() {
		stringstream ss;
		for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
			if (ptr->next != NULL) {
				ss << ptr->item << " ";
			} else {
				ss << ptr->item;
			}
		}
		return (ss.str());
	}

};