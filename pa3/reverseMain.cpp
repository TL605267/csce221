// reverse a queue

#include <iostream>
#include <fstream>
#include "LinkedQueue.h"
#include "LinkedStack.h"

using namespace std;

// add your functions here

int main()
try {
	LinkedQueue lq;
	ifstream is;
	is.open("input.txt");
	string read_str;
	cout << "Original list:" << endl;
	while(getline(is,read_str)) { //Put contents of input.txt into lq
		lq.enqueue(read_str);
		cout << read_str << endl;
	}
	LinkedStack ls;
	int size = lq.size();
	for(int i = 0; i < size; ++i) { //Put contents of lq into ls
		ls.push(lq.dequeue());
	}
	cout << endl << "Reversed list:" << endl;
	for(int i = 0; i < size; ++i) { //Output ls
		cout << ls.pop() << endl;
		}
		
		} catch(RuntimeException &e) {
			cout << e << endl;
		}