TARGETS = Test_Binary_Search_Tree_Numbers bst
CC = g++
CCFLAGS = -std=c++11 -g
MAIN = bst
SRCS = main.cpp Node.cpp BST.cpp
OBJS = $(SRCS:.cpp=.o)
$(MAIN): $(OBJS)
	$(CC) $(CCFLAGS) -o $(MAIN) $(OBJS)
	
Node.o: Node.h NodeInterface.h Node.cpp
BST.o: BST.h BSTInterface.h Node.h NodeInterface.h BST.cpp
main.o: BST.h BSTInterface.h Node.h NodeInterface.h main.cpp

.cpp.o:
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) *.o $(MAIN)

Test_Binary_Search_Tree_Numbers: Test_Binary_Search_Tree_Numbers.cpp Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CC) $(CCFLAGS) -o Test_Binary_Search_Tree_Numbers Test_Binary_Search_Tree_Numbers.cpp