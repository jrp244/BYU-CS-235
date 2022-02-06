#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "PathfinderInterface.h"
using namespace std;
#define SIZE 5
const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2;
const int PATH = 3;

class Pathfinder: public PathfinderInterface 
{
public:
	Pathfinder();
	~Pathfinder();
	string toString () const;
	void createRandomMaze();
	bool importMaze (string file_name);
	vector<string> solveMaze();

private:
	bool find_maze_path(int maze[SIZE][SIZE][SIZE], int r, int c, int h);
	vector<string> solution;
	int maze[SIZE][SIZE][SIZE]; //To hold values
};