#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Pathfinder.h"
using namespace std;

Pathfinder::Pathfinder() {
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				maze[i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder() {
	//TODO
}

void Pathfinder::createRandomMaze() { //Creates a random maze
	int maze[SIZE][SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				maze[i][j][k] = rand()%2;
			}
		}
	}
}

string Pathfinder::toString() const { //Converts the info into a string
	stringstream ss;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				ss << maze[i][j][k];
				if (k == SIZE-1) {
					ss << endl;
				}
				else {
					ss << " ";
				}
			}
		}
		if (i < 4) {
			ss << endl;
		}
	}
	return ss.str();
}

bool Pathfinder::importMaze(string file_name) { //Imports the maze 
	ifstream file (file_name);
	//file.open(file_name);
	if (!file.is_open()) {
		return false; //If file doesn't open
	}
	int mazeValues[125];
	int newValue = 0;
	for (int i = 0; i < 125; i++) {
		file >> newValue;
		if (file.fail()) {
			return false;  //If input can't be read from the file
		}
		if ((newValue != 0) && (newValue != 1)) {
			return false; //Not valid input
		}
		mazeValues[i] = newValue;
	}
	if (file >> newValue) {
		return false; // file is too long
	}
	file.close();
	if (mazeValues[0] != 1 || mazeValues[124] != 1) {
		return false;  //Checking to see if the 1st element and last element are 1s
	}
	int index = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				maze[i][j][k] = mazeValues[index++];
			}
		}
	}
	return true;
}

bool Pathfinder::find_maze_path(int maze[SIZE][SIZE][SIZE], int r, int c, int h) {
	//cout << "find_maze_path ["<<r<<"]["<<c<<"]"<<endl;
	//cout << this->toString();
	if (r < 0 || c < 0 || r >= SIZE || c >= SIZE)
	  return false;      // Cell is out of bounds.
	else if (maze[r][c][h] != BACKGROUND)
		return false;      // Cell is on barrier or dead end.
	else if (r == SIZE - 1 && c == SIZE - 1 && h == SIZE - 1) {
		maze[r][c][h] = PATH;         // Cell is on path
	    solution.push_back("("+to_string(r)+","+to_string(c)+","+to_string(h)+")");
	    return true;               // and is maze exit.
	}
	else if (maze[r][c][h] == TEMPORARY) {
		return false;
	}
	else { 
	    // Recursive case.
	    // Attempt to find a path from each neighbor.
	    // Tentatively mark cell as on path.
	    maze[r][c][h] = PATH;
		if (find_maze_path(maze, r - 1, c, h)
	        || find_maze_path(maze, r + 1, c, h)
	        || find_maze_path(maze, r, c - 1, h)
	        || find_maze_path(maze, r, c + 1, h )
			|| find_maze_path(maze, r, c, h - 1)
	        || find_maze_path(maze, r, c, h + 1 ) ) {
	      solution.push_back("("+to_string(r)+","+to_string(c)+","+to_string(h)+")");
	    return true;
	    }
	    else {
	      //maze[r][c][h] = TEMPORARY;  // Dead end.
	      return false;
	    }
	}
}


vector<string> Pathfinder::solveMaze()
{
	//cout << "Reach" << endl;
	int mymaze [SIZE][SIZE][SIZE]; //Temp maze
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				mymaze[i][j][k] = maze[i][j][k];
				//cout << maze[i][j][k];
			}
			//cout << endl;
		}
	}
	find_maze_path(mymaze, 0,0,0);
	//for(auto s:solution) {
		//cout << s << endl;
	//}
	//if (!solution.empty()){
	//	return solution;
	//}

	return solution;
}