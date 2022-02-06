#include "QS.h"
using namespace std;

QS::QS() {
	myArray = nullptr;
	maxSize = 0;
	currentPos = 0;
}

QS::~QS() {
	delete [] myArray;
}

void QS::sortAll () {
	if (currentPos > 0) {
		sort(0, currentPos-1);
	}
}

void QS::sort (int first, int last) {
	int pivot = medianOfThree(first, last);
	if (last - first > 2) {
		pivot = partition(first, last, pivot);
		sort (first, pivot-1);
		sort (pivot+1, last);
	};
}

int QS::medianOfThree(int left, int right) {
	int middle = 0;
	if (myArray == nullptr || left < 0 || right < 0 || left >= currentPos || right >= currentPos || left >= right || currentPos == 0) {
		return -1;
	}
	middle = (left + right) / 2;
	bubbleSort(left, right, middle);
	return middle;
}

void QS::bubbleSort(int left, int right, int middle) { //For medianOfThree
	if (myArray[left] > myArray[middle]) {
		exchange(left,middle);
	}
	if (myArray[middle] > myArray[right]) {
		exchange(right,middle);
	}
	if (myArray[left] > myArray[middle]) {
		exchange(left,middle);
	}
}

int QS::partition (int left, int right, int pivotIndex) {
	if (myArray == nullptr || left < 0 || right < 0 || left >= currentPos || right >= currentPos || left >= right || currentPos == 0) {
		return -1;
	}
	// left = first
	//right = last
	int up = left+1;
	int down = right;
	int pivotVal = myArray[pivotIndex];
	exchange (left, pivotIndex);
	do {
		while (myArray[up] <= pivotVal && up < right) {
			++up;
		}
		while (myArray[down] > pivotVal && down > left) {
			--down;
		}
		if (up < down) {
			exchange (up, down);
		}
	} while (up < down);
	exchange (left, down);
	return down;
}

string QS::getArray() const {
	stringstream ss;
	if (myArray == 0) { //If there is nothing there
		ss << "";
		return ss.str();
	}
	for (int i = 0; i < currentPos; i++) {
		if (i == currentPos-1) {
			ss << myArray[i];
		}
		else {
			ss << myArray[i] << ",";
		}
	}
	return ss.str();
}

void QS::exchange (int index1, int index2) {
	int temp = myArray[index1];
	myArray[index1] = myArray[index2];
	myArray[index2] = temp;
}

int QS::getSize() const {
	return currentPos;
}

bool QS::addToArray(int value) {
	if (currentPos >= maxSize) {
		return false;
	}
	myArray[currentPos] = value;
	currentPos++;
	return true;
}

bool QS::createArray(int capacity) {
	if (capacity < 0) {
		return false;
	}
	maxSize = capacity;
	delete [] myArray;
	myArray = nullptr;
	currentPos = 0;
	myArray = new int[capacity];
	return true;
}

void QS::clear() {
	delete [] myArray;
	myArray = nullptr;
	currentPos = 0;
}