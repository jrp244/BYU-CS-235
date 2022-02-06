#include "BST.h"

using namespace std;

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
NodeInterface* BST::getRootNode() const {
	return root;
}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
bool BST::add(int data) {
	if (root == NULL) {
		root = new Node(data);
		return true;
	}
	else if (recursiveadd(this->root,data)) {
		return true;
	}
	else {
		return false;
	}
}

bool BST::recursiveadd(Node* node_ptr, int data) {
	if (node_ptr -> getData() == data) {
		return false;
	}
	else if (node_ptr->getData() < data) {
		if (node_ptr->getRightChild() == NULL) {
			Node* newNode_ptr = new Node(data);
			node_ptr -> right = newNode_ptr;
			return true;
		}
		return recursiveadd(node_ptr->right, data);
	}
	else if (node_ptr->getData() > data) {
		if (node_ptr->getLeftChild() == NULL) {
			Node* newNode_ptr = new Node(data);
			node_ptr -> left = newNode_ptr;
			return true;
		}
		return recursiveadd(node_ptr->left, data);
	}
}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
bool BST::remove(int data) {
	return erase(this->root, data);
}

bool BST::erase (Node* &local_root, int item) {
	if (local_root == NULL) {
    	return false;
  	}
    else if (item < local_root->data) {
      return erase(local_root->left, item);
	}
    else if (local_root->data < item) {
      return erase(local_root->right, item);
	}
    else { // Found item
      Node* old_root = local_root;
      if (local_root->left == NULL) {
        local_root = local_root->right;
      } else if (local_root->right == NULL) {
        local_root = local_root->left;
      } else {
        replace_parent(old_root, old_root->left);
      }
      delete old_root;      
      return true;
  }
}

void BST::replace_parent(Node* &old_root, Node* &local_root) {
	if (local_root->right != NULL) {
		replace_parent(old_root, local_root->right);
	}
	else {
   	 	old_root->data = local_root->data;
    	old_root = local_root;
    	local_root = local_root->left;
	}
}


	//* Removes all nodes from the tree, resulting in an empty tree.

void BST::clear() {
	clearNode(root);
}

void BST::clearNode(Node* &nodeptr) {
	if (nodeptr != NULL) {
		clearNode(nodeptr->left);
		clearNode(nodeptr->right);
	}
	delete nodeptr;
	nodeptr = NULL;
}