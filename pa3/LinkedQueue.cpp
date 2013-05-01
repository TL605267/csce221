//LinkedQueue.cpp

#include "LinkedQueue.h"

// assignment operator
// O(n)

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queue)
{
	LinkedQueue q(queue);
	LinkedQueue r;
	for(int i = 0; i < queue.size(); ++i)
		r.enqueue(q.dequeue());
	for(int i = 0; i < queue.size(); ++i)
		enqueue(r.dequeue());
	return *this;
}

// accessor function
// O(1)

string LinkedQueue::first( ) const throw(QueueEmptyException)
{
	if(ll.isEmpty())
	   throw QueueEmptyException();
	return ll.first();
}

// update functions
// O(1)

string LinkedQueue::dequeue( ) throw(QueueEmptyException)
{
	if(ll.isEmpty())
	   throw QueueEmptyException();
	return ll.removeFirst();
}

// O(n)

ostream& operator<<(ostream& out, const LinkedQueue& queue)
{
	if(queue.isEmpty())
		return out << "{}";
	out << '{';
	LinkedQueue q(queue);
	for(int i = 0; i < queue.size(); ++i) {
		if(i != 0)
			out << ' ';
		out << q.dequeue();
	}
	return out << '}';
}
