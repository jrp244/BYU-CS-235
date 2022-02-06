#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoList.h"
#include "TodoListInterface.h"
using namespace std;
    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    void TodoList::add(string _duedate, string _task) {
	  dates.push_back(_duedate);
      tasks.push_back(_task);
    }
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    int TodoList::remove(string _task) {
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
    void TodoList::printTodoList() {
      for (int i = 0; i < tasks.size(); i++) {
		cout << dates.at(i) << endl;
        cout << tasks.at(i) << endl;
      }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    void TodoList::printDaysTasks(string _date) {
      for (int i = 0; i < tasks.size(); i++) {
        if (dates.at(i) == _date) { //If the value in the vector equals the task:
          cout << tasks.at(i) << endl;
        }
      }
    }
#endif