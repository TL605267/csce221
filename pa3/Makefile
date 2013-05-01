 # Makefile

all: reverse
test_all: linkedlist linkedstack linkedqueue reverse

linkedlist: LinkedListMain.cpp LinkedList.cpp LinkedList.h
	c++ -Wall -g -o linkedlist LinkedList.cpp LinkedListMain.cpp

linkedstack: LinkedList.cpp LinkedStack.cpp LinkedStackMain.cpp LinkedStack.h LinkedList.h
	c++ -Wall -g -o linkedstack LinkedList.cpp LinkedStack.cpp \
	     LinkedStackMain.cpp

linkedqueue: LinkedList.cpp LinkedQueue.cpp LinkedQueueMain.cpp LinkedQueue.h LinkedList.h
	c++ -Wall -g -o linkedqueue LinkedList.cpp  LinkedQueue.cpp \
	     LinkedQueueMain.cpp

reverse: LinkedList.cpp LinkedStack.cpp LinkedQueue.cpp reverseMain.cpp LinkedList.h LinkedStack.h LinkedQueue.h
	c++ -Wall -g -o reverse LinkedList.cpp  LinkedStack.cpp \
	     LinkedQueue.cpp reverseMain.cpp

.PHONY: clean

clean:
	/bin/rm -fr *.o *.dSYM linkedlist linkedstack linkedqueue reverse
