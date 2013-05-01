// Linked Stack

#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
try {
	LinkedStack stack;
	LinkedStack stack_copy;
	
	//===== push() =====
	
	string s1("O");
	stack.push(s1);
	string s2("RR");
	stack.push(s2);
	string s3("AAA");
	stack.push(s3);
	string s4("NNNN");
	stack.push(s4);
	string s5("GGG");
	stack.push(s5);
	string s6("ABCDE");
	stack.push(s6);
	
	cout << "stack = " << stack << endl;
	cout << "size of stack = " << stack.size() << endl;
	cout << "top of stack = " << stack.top() << endl << endl;
	
	//===== assignment operator =====
	
	stack_copy = stack;
	cout << "assigning stack to stack_copy, stack_copy = ";
	cout << stack_copy << endl;
	cout << "size of stack_copy = " << stack_copy.size() << endl;
	cout << "top of stack_copy = " << stack_copy.top() << endl << endl;
	
	//===== copy constructor =====
	
	LinkedStack stack_copy2(stack);
	cout << "copy constructor stack = ";
	cout << stack_copy2 << endl;
	cout << "size of stack_copy2 = " << stack_copy2.size() << endl;
	cout << "top of stack_copy2 = " << stack_copy2.top() << endl << endl;
	
	//===== pop() =====
	
	while (!stack_copy2.isEmpty()) {
		cout << stack_copy2.pop() << endl;
	}
	
	cout << "popping all elements from stack_copy2, stack_copy2 = ";
	cout << stack_copy2 << endl;
	
	// stack_copy2.pop() Throws exception
	
	cout << endl;
	
	cout << "original stack:" << endl;
	cout << stack << endl;
	
	return 0;
	} catch(RuntimeException &e) {
		cout << e << endl;
	}
