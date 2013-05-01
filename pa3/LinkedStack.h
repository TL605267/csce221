// LinkedListStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "LinkedList.h"

class LinkedStack
{
private:
	LinkedList ll;
public:
	// user-defined exceptions
	class StackEmptyException : public RuntimeException {
	public:
		StackEmptyException() : RuntimeException("Stack is empty") {}
	};
	
	LinkedStack() { } // default constructor
	~LinkedStack() { ll.removeAll(); } // destructor
	LinkedStack(const LinkedStack& stack) : ll(stack.ll) {  } // copy constructor
	LinkedStack& operator=(const LinkedStack& stack); // assignmnet operator
	
	// query functions
	bool isEmpty() const { return ll.isEmpty(); }
	int size() const { return ll.size(); }
	
	// accessor function
	string top() const throw(StackEmptyException);
	
	// update functions
	void push(const string elem) { ll.insertFirst(elem); }
	string pop() throw(StackEmptyException);
};

ostream& operator<<(std::ostream& out,
					const LinkedStack& stack); //overload <<

#endif
