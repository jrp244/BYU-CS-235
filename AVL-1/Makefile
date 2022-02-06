TARGETS = Test_Binary_Search_Tree_Numbers bst
CXX = g++
CXXFLAGS = -std=c++11 -g
MAIN = avl
SRCS = main.cpp Node.cpp AVL.cpp
OBJS = $(SRCS:.cpp=.o)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJS)
	
Node.o: Node.h NodeInterface.h Node.cpp
BST.o: AVL.h AVLInterface.h Node.h NodeInterface.h AVL.cpp
main.o: AVL.h AVLInterface.h Node.h NodeInterface.h main.cpp

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) *.o $(MAIN)

turnin.txt: $(MAIN)
	./$(MAIN)
	bash check.sh

clean_check:
	$(RM) out_file* turnin.txt details.txt

valgrind: $(MAIN)
	valgrind ./$(MAIN)

Test_Binary_Search_Tree_Numbers: Test_Binary_Search_Tree_Numbers.cpp Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CXX) $(CXXFLAGS) -o Test_Binary_Search_Tree_Numbers Test_Binary_Search_Tree_Numbers.cpp