#include <iostream>
#include "Node.h"
using namespace std;

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
int Node::getData() const {
	return data;
}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
Node* Node::getLeftChild() const {
	return left;
}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
Node* Node::getRightChild() const {
	return right;
}