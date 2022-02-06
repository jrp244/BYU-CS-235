#include "AVL.h"

using namespace std;

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/

NodeInterface* AVL::getRootNode() const {
	return root;
}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true 	if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
int AVL::height(Node *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int AVL::difference(Node *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
Node *AVL::rr_rotat(Node *parent) {
   Node *t;
   t = parent->root;
   parent->root = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
Node *AVL::ll_rotat(Node *parent) {
   Node *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
Node *avl_tree::lr_rotat(Node *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
Node *AVL::rl_rotat(Node *parent) {
   Node *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
Node* AVL::balance(Node *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}

bool AVL::add(int data) {
	Node* tempAbove = root;
	int counter = 0;
	if (root == NULL) {
		root = new Node(data);
		return true;
	}
	else if (recursiveadd(this->root, data, tempAbove)) {
		return true;
	}
	else {
		return false;
	}
}

int AVL::getHeight(Node* node) {
	if (node == NULL) {
		return 0;
	} else {
		return node->height;
	}
}

void AVL::calculateHeight(Node* node) {
	if (node == NULL) {
		return;
	}
	int max = 0;
	if (getHeight(node->left) > max) {
		max = getHeight(node->left);
	}
	if (getHeight(node->right) > max) {
		max = getHeight(node->right);
	}
	node->height = max + 1;
	//cout << "calc height" << node->data << "=" << node->height << endl;
}

bool AVL::recursiveadd(Node*& node_ptr, const int data, Node*& tempAbove) {
	// Endpoint - duplicate, returning false
	if (node_ptr -> getData() == data) {
		return false;
	}

	Node*& next_node = (node_ptr->data < data) ? node_ptr->right : node_ptr->left;

	// Endpoint - not found, adding
	if (next_node == NULL) {
		next_node = new Node(data);
		//next_node->above = node_ptr;
		//cout << next_node->data << endl;
		//cout << next_node->above->data << endl;
		calculateHeight(node_ptr);
		rebalance(node_ptr);
		//cout << node_ptr->data << endl;
		//cout << next_node->data << endl;
		//cout << tempAbove->data << endl;
		next_node->above = tempAbove;
		return true;
	}

	// Recursion
	if (recursiveadd(next_node, data, tempAbove)) {
		tempAbove = next_node;
		calculateHeight(node_ptr);
		rebalance(node_ptr);
		return true;
	}
	return false;
}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
bool AVL::remove(int data) {
	return remove(this->root, data);
}

bool AVL::remove(Node* &local_root, int item) {
	if (local_root == NULL) {
    	return false;
  	}
    else if (item < local_root->data) {
	  //calculateHeight(local_root);
	  //rebalance(local_root);  
      return remove(local_root->left, item);
	}
    else if (local_root->data < item) {
	  //calculateHeight(local_root);
	  //rebalance(local_root);  
      return remove(local_root->right, item);
	}
    else { // Found item
      Node* old_root = local_root;
	  if (local_root->left == NULL && local_root->right == NULL) {
		calculateHeight(local_root);
	    rebalance(local_root);
		delete local_root;
		local_root = NULL;
		return true;
	  }
      if (local_root->left == NULL) {
        local_root = local_root->right;
      } else if (local_root->right == NULL) {
        local_root = local_root->left;
      } else {
        replace_parent(old_root, old_root->left);
      }
	  calculateHeight(local_root);
	  rebalance(local_root);
      delete old_root;
	  calculateHeight(local_root);
	  rebalance(local_root);
      return true;
  }
}

void AVL::replace_parent(Node* &old_root, Node* &local_root) { //When there are 2 children
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

void AVL::clear() {
	clearNode(root);
}

void AVL::clearNode(Node* &nodeptr) {
	if (nodeptr != NULL) {
		clearNode(nodeptr->left);
		clearNode(nodeptr->right);
	}
	delete nodeptr;
	nodeptr = NULL;
}