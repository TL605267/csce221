#include <iostream>
#include <fstream>
#include "BinaryTree.h"

int main() {
	//Input the file
	string file;
	cout << "Enter a file: ";
	cin >> file;
	ifstream is(file.c_str(), ifstream::in);
	
	//Output file contents
	cout << "Given input: " << endl;
	int el;
	is >> el;
	cout << el << endl;
	BinaryTree bt(el);
	while(is.good()) {
		is >> el;
		if(is.good()) {
			cout << el << endl;
			bt.insertNode(el);
		}
	}
	cout << endl;
	
	//Output tree
	int* sc = new int(0);
	if(bt.size() < 16)
		cout << "Binary tree: " << endl << bt;
	else {
		ofstream os("out1.txt");
		os << bt;
		cout << "Tree output to file: out1.txt" << endl;
	}
	cout << "Number of nodes: " << bt.size() << endl;
	cout << "Average search cost: " << bt.avgSearchCost(bt.getRoot(), sc) << endl << endl;
	
	//Pick an element to remove, remove it
	cout << "Please enter an element to remove: ";
	cin >> el;
	bt.removeNode(el, bt.getRoot());
	
	//Output new tree
	*sc = 0;
	if(bt.size() < 16)
		cout << endl << "Binary tree after element removed: " << endl << bt;
	else {
		ofstream os("out2.txt");
		os << bt;
		cout << "Tree output to file: out2.txt" << endl;
	}
	cout << "Number of nodes: " << bt.size() << endl;
	cout << "Average search cost: " << bt.avgSearchCost(bt.getRoot(), sc) << endl;
	
	delete sc;
}
