//LinkedList.cpp
#include <iostream>
#include "LinkedList.h"

using namespace std;

// destructor

LinkedList::~LinkedList() {
	removeAll();
}

// copy constructor
// O(n)

LinkedList::LinkedList(const LinkedList& ll) {
	head = new ListNode(*ll.head);
	ListNode *node1 = head;
	ListNode *node2 = ll.head->next;
	while(node2 != NULL) {
		node1->next = new ListNode(*node2);
		node1 = node1->next;
		node2 = node2->next;
	}
	tail = new ListNode(*ll.tail);
}

// assignment operator
// O(1)

LinkedList& LinkedList::operator=(const LinkedList& ll)
{
	head = new ListNode(*ll.head);
	ListNode *node1 = head;
	ListNode *node2 = ll.head->next;
	while(node2 != NULL) {
		node1->next = new ListNode(*node2);
		node1 = node1->next;
		node2 = node2->next;
	}
	tail = new ListNode(*ll.tail);
	return *this;
}

// query function
// O(n)

int LinkedList::size() const {
	int count = 0;
	ListNode *current = head;
	while(current != NULL) {
		++count;
		current = current->next;
	}
	return count;
}

// accessor function
// O(1)

string& LinkedList::first() const throw(EmptyLinkedListException)
{
	if(head == NULL)
		throw new EmptyLinkedListException;
	else
		return head->obj;
}

// update functions
// O(1)

void LinkedList::insertFirst(string newobj)
{
	ListNode *node = new ListNode(newobj);
	if(head == NULL)
		tail = node;
	node->next = head;
	head = node;
}

void LinkedList::insertLast(string newobj)
{
	ListNode *node = new ListNode(newobj);
	if(head == NULL)
		head = tail = node;
	else {
		tail->next = node;
		tail = node;
	}
}


string LinkedList::removeFirst() throw(EmptyLinkedListException)
{
	if(head == NULL)
		throw EmptyLinkedListException();
	ListNode *node = head;
	head = node->next;
	if(head == NULL)
		tail = NULL;
	string obj = node->obj;
	delete node;
	return obj;
}

// O(n)

void LinkedList::removeAll()
{
	if(head == tail) {
		head = NULL;
		tail = NULL;
		return;
	}
	ListNode *node;
	while(head != NULL) {
		node = head;
		head = head->next;
		delete node;
	}
	tail = NULL;
}

// O(n)

ostream& operator<<(ostream& os, const LinkedList& ll)
{
	if(ll.getHead() == NULL)
		return os << "{}";
	ListNode *node = ll.getHead();
	os << '{';
	while(node != NULL) {
		os << node->obj;
		node = node->next;
		if(node != NULL)
			os << ' ';
	}
	os << '}';
	return os;
}
