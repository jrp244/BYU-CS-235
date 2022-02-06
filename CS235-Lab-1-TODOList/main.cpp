#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]) {
  TodoList myList;
  string firstArg = argv[1];
  //Takes 2 arguments
  if (firstArg.compare("add")==0) {
    string date = argv [2];
    string task = argv [3];
    myList.add(date, task);
  }
  //Takes 1 argument
  else if (firstArg.compare("remove")==0) {
    string task = argv [2];
    myList.remove(task);
  }
  //Takes 0 arguments
  else if (firstArg.compare("printTodoList")==0) {
    myList.printTodoList();
  }
  //Takes 1 argument
  else if (firstArg.compare("printDaysTasks")==0) {
    string date = argv [2];
    myList.printDaysTasks(date);
  }
  else {
	  cout << "Invalid arguments. Here is a list of valid arguments: add, remove, printTodoList, printDaysTasks" << endl;
  }
}