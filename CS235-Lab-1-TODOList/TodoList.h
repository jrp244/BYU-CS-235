#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"
using namespace std;

class TodoList : public TodoListInterface {
private:
  vector <string> tasks;
  vector <string> dates;
public:
      TodoList() { //Constructor
      ifstream infile ("TodoList.txt");
      string line; 
      if (infile.is_open())
      {
	  int numTasks = 0;
	  infile >> numTasks;
	  infile.ignore();
	  for (int i = 0; i < numTasks; i++)
      {
	  getline (infile,line);
	  dates.push_back(line); //Gets the dates
	  getline (infile,line);
      tasks.push_back(line); //Gets the tasks
      }
      infile.close();
  }

  else cout << "Unable to open file"; 

    }
    virtual ~TodoList() { //Destructor
      ofstream outfile;
      outfile.open ("TodoList.txt", ofstream::out | ofstream::trunc);
	  outfile << tasks.size() << endl;
      for (int i = 0; i < tasks.size(); i++) {
		outfile << dates.at(i) << endl;
        outfile << tasks.at(i) << endl;
      }
      outfile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task); //{
	  //dates.push_back(_duedate);
      //tasks.push_back(_task);
    //}
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
      int returnVar = 0;
      cout << _task << endl;
      for (int i = 0; i < tasks.size(); i++) {
        if (tasks.at(i) == _task) { //If the value in the vector equals the task:
          tasks.erase(tasks.begin() + i); //Removes the item from the vector
          returnVar = 1;
        }
      }
      return returnVar;
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
      for (int i = 0; i < tasks.size(); i++) {
		cout << dates.at(i) << endl;
        cout << tasks.at(i) << endl;
      }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
      for (int i = 0; i < tasks.size(); i++) {
        if (dates.at(i) == _date) { //If the value in the vector equals the task:
          cout << tasks.at(i) << endl;
        }
      }
    }
};
#endif