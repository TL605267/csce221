// main function

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
try
{
	LinkedList ll;
	LinkedList ll_copy;
	
	//===== insertion =====
	
	cout << "ll = ";
	cout << ll << endl;
	cout << "length of the list = " << ll.size() << endl << endl;
	//cout << "first element = " << ll.first() << endl << endl; // throws exception
	string s1("AAA");
	ll.insertFirst(s1);
	string s2("RRR");
	ll.insertFirst(s2);
	string s3("OOO");
	ll.insertFirst(s3);
	string s4("GGG");
	ll.insertLast(s4);
	string s5("EEE");
	ll.insertLast(s5);
	
	cout << "After inserting 5 elements to ll, ll = ";
	cout << ll << endl;
	cout << "length of the list = " << ll.size() << endl;
	cout << "first element = " << ll.first() << endl << endl;
	
	//===== assignment operator =====
    
	ll_copy = ll;
	cout << "Assigning ll to ll_copy, ll_copy = ";
	cout << ll_copy << endl;
	cout << "length of the list = " << ll_copy.size() << endl;
	cout << "first element = " << ll_copy.first() << endl << endl;
	
	//===== copy constructor =====
	
	LinkedList ll_copy2(ll);
	cout << "Copying ll to ll_copy2, ll_copy2 = ";
	cout << ll_copy2 << endl;
	cout << "length of the list = " << ll_copy2.size() << endl;
	cout << "first element = " << ll_copy2.first() << endl << endl;
	
	//===== remove(), removeFirst() =====
	
	ll.removeFirst();
	ll.removeFirst();
	ll.removeFirst();
	ll.removeFirst();
	//ll.removeFirst(); // throws exception
	//ll.remove(ll.getHead()); // throws exception
	
	cout << "After removing 4 elements from ll, ll = ";
	cout << ll << endl;
	cout << "length of the list = " << ll.size() << endl;
	//cout << "first element = " << ll.first() << endl << endl; // throws exception
	if (ll.isEmpty())
	cout << "list is empty." << endl;
	cout << endl;
	
	//===== removeAll() =====
	
	ll_copy.removeAll();
	cout << "After removing all elements, ll_copy = ";
	cout << ll_copy << endl;
	cout << "length of the list = " << ll_copy.size() << endl;
	if (ll_copy.isEmpty())
	cout << "list is empty." << endl;
	cout << endl;
	
	cout << "The copy of ll, ll_copy2 = ";
	cout << ll_copy2 << endl;
	cout << "length of the list = " << ll_copy2.size() << endl;
	cout << "first element = " << ll_copy2.first() << endl << endl;
	
	return 0;
	} catch (RuntimeException& e) {
		cout << e <<endl;
	}
	
