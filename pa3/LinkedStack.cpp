// LinkedStack.cpp

#ifndef LINKEDLISTSTACK_CPP
#define LINKEDLISTSTACK_CPP

#include "LinkedStack.h"

// assignment operator
// O(n)

LinkedStack& LinkedStack::operator=(const LinkedStack& stack)
{
	LinkedStack s(stack);
	LinkedStack t;
	for(int i = 0; i < stack.size(); ++i)
		t.push(s.pop());
	for(int i = 0; i < stack.size(); ++i)
		push(t.pop());
	return *this;
}

// query function
// O(1)

string LinkedStack::top() const throw(StackEmptyException)
{
	if(ll.isEmpty())
		throw StackEmptyException();
	return ll.first();
}

// update function
// O(1)

string LinkedStack::pop() throw(StackEmptyException)
{
	if(ll.isEmpty())
		throw StackEmptyException();
	return ll.removeFirst();
}

// O(n)

ostream& operator<<(std::ostream& out, const LinkedStack& stack)
{
	if(stack.isEmpty())
		return out << "{}";
	LinkedStack s(stack);
	out << '{';
	for(int i = 0; i < stack.size(); ++i) {
		if(i != 0)
			out << ' ';
		out << s.pop();
	}
	return out << '}';
}


#endif
