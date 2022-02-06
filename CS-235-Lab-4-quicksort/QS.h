#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "QSInterface.h"
using namespace std;
#define SIZE 5
const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2;
const int PATH = 3;

class QS: public QSInterface 
{
public:
	QS();
	~QS();
	void sortAll ();
	void sort (int first, int last);
	int medianOfThree(int left, int right);
	int partition (int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();

private:
	void bubbleSort(int left, int right, int middle);
	void exchange(int index1, int index2);
	int currentPos = 0;
	int *myArray;
	int maxSize;
};