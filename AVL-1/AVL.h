#pragma once

#include <iostream>
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL : public AVLInterface {
public:
	AVL() {}
	~AVL() {
		clear();
	}
	int balance(Node*& node);
	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface* getRootNode() const;
	void rebalance (Node*&);
	void rotateRight(Node*& n);
	void rotateLeft(Node*& n);
	int getHeight(Node* node);
	void calculateHeight(Node* node);
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool recursiveadd(Node*& node_ptr, const int data, Node*& tempAbove);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	bool remove(Node* &local_root, int item);
	void replace_parent(Node* &old_root, Node* &local_root);
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clearNode(Node* &nodeptr);

	int height(avl *);
      int difference(Node *);
      Node *rr_rotat(Node *);
      Node *ll_rotat(Node *);
      Node *lr_rotat(Node*);
      Node *rl_rotat(Node *);
      Node * balance(Node *);


protected:
	Node *root = NULL;
};