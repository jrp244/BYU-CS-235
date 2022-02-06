#include "Hashmap.h"

Hashmap::Hashmap() {
	mapSize = 0;
	for (int i = 0; i < BUCKETS; i++) {
		buckets[i] = NULL;
	}
}

Hashmap::~Hashmap() {
	//cout << "destruct" << endl;
	clear();
}

void Hashmap::insert(string key, int value) {
	//cout << "insert" << endl;
	int &valptr = at(key);
	valptr = value;
}


bool Hashmap::contains(string key) const {
	int hashval = hash(key); // Compute the hash value
	Node* temp = buckets[hashval];
	while (temp != NULL) {
		if (temp->key == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}


int Hashmap::get(string key) const {
	//cout << "get " << endl;
	int hashval = hash(key); // Compute the hash value
	Node* temp = buckets[hashval];
	while (temp != NULL) {
		if (temp->key == key) {
			return temp->value;
		}
		temp = temp->next;
	}
	//cout << "ivalid" << endl;
	throw invalid_argument("Invalid arguement");
}


int& Hashmap::at(string name) {
	//cout << " at" << endl;
		int hashval = hash(name); // Compute the hash value for this name, for now assume it is 0
		Node *ptr = buckets[hashval];
		while(ptr != NULL) {
			// cout <<"comparing "<<name<<" first "<<ptr->context.first<<endl;
			if(name == ptr->key) { // We found it
				break;
			} else {
			  //cout << "ptr"<< ptr<<"next "<< ptr->next<<endl;
			  ptr = ptr->next;
			}
		}
		if(ptr == NULL) { // We need to create a new node, put it on the front of the list
			ptr = new Node;
			mapSize++;
			//cout << "new node "<< static_cast<void*>(&(ptr->context.second))<<endl;
			ptr->next = buckets[hashval];
			buckets[hashval] = ptr;
			ptr->key = name;
			if (ptr->next) {
				ptr->next->prev = ptr; //Connect the previous
			}
		}
		//cout << "return "<< static_cast<void*>(&(ptr->context.second))<<endl;
		return(ptr->value);
	}


bool Hashmap::remove(string key) {
	unsigned int bucket = hash(key);
	Node* current = buckets[bucket];
	
	while ((current != NULL) && (current->key != key)) {
		current = current->next;
	}
	if (current == NULL) {
		return false; //Didn't find it
	}
	if (current->next != NULL) {
		current->next->prev = current->prev;
	}
	if (current->prev == NULL) {
		buckets[bucket] = current->next;
	} else {
		current->prev->next = current->next;
	}
	delete current;
	current = NULL;
	mapSize--;
	return true;
}


void Hashmap::clear() {
	for (int i = 0; i < BUCKETS; i++) {
		//Node* currentptr = buckets[i];
		while (buckets[i] != NULL) {
			remove(buckets[i]->key);
		}
	}
	mapSize = 0;
	//cout << "clear" << endl;
}


string Hashmap::toString() const {
	//cout << "tostring" << endl;
	stringstream ss;
	for (int i = 0; i < BUCKETS; i++) {
		Node* head = buckets[i];
		if (head == NULL) { //Hash bucket is empty
			ss << "[" << i << "]" << endl;
		} else { //There was something in this has bucket
			Node* current = head;
			ss << "[" << i << "]";
			while (current != NULL) {
				ss << current->key << "=>" << current->value;
				if (current -> next != NULL) {
					ss << ", ";
				}
				current = current->next;
				ss << endl;
			}
		}
	}
	//cout << "end" << endl;
	return ss.str();
}


int Hashmap::size() const {
	//cout << " Size" << endl;
	return mapSize;
	//cout <<"why" << endl;
}


string Hashmap::toSortedString() const
{
  stringstream ss;
  priority_queue<Node*, vector<Node*>, NodeCompare> nodeHeap;
  for (int i = 0; i < BUCKETS; i++)
  {
	Node* current = buckets[i];
    // Iterate through each bucket. Use nodeHeap.push to push all Node* onto heap.
	while (current != NULL) {
		nodeHeap.push(current);
		current = current->next;
	}
  }
  while (!nodeHeap.empty())
  {
    Node* top = nodeHeap.top(); // Get top node (next node in sorted order)
    ss << top->key << " => " << top->value << endl; // Add node data to stringstream
    nodeHeap.pop(); // Pop it off
  }
  return ss.str();
}

int& Hashmap::operator[](string key) {
	  // Is the key in the map?
  unsigned int bucket = hash(key);
  Node* last = NULL;
  Node* current = buckets[bucket];
  while(current != NULL && current->key != key)
  {
    last = current;
    current = current->next;
  }
  // If current is not NULL, then that means I found it
  if(current != NULL)
    return current->value;

  // If current is NULL, then i did not find it and I need to add it
  Node* newNode = new Node();
  mapSize++;
  newNode->key = key;
  newNode->value = 0;
  if(last == NULL) // There is nothing in this bucket yet
  {
    // Update head pointer to point to new node
    buckets[bucket] = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode->value;
  }

  // If there is something in this bucket, append newNode to the end
  last->next = newNode;
  newNode->prev = last;
  newNode->next = NULL;
  return newNode->value;
	//return at(key);
}

unsigned int Hashmap::hash(string key) const {
	unsigned int hashCode = 0;
	for (int i = 0; i < key.length(); i++) {
		hashCode = hashCode * 31 * key.at(i);
	}
	return hashCode % BUCKETS;
}
