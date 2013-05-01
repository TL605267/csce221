#include <cstdlib>
#include <iostream>
#include "llist_jar.h"

using namespace std;

// default constructor
LListJar::LListJar() {}

// constructor
LListJar::LListJar(int num)
{
	//Check for invalid input
	while(num > 12 || num < 0) {
		cout << "Invalid amount of marbles!" << endl
		<< "Only up to 12 marbles can be created (no duplicates)."
		<< endl << "Enter number of marbles: ";
		cin >> num;
	}
	
	while(marble_number() < num) {
		while(true) {
			Marble temp;
			if(!is_in_jar(temp)) {
				ll.push_back(temp);
				break;
			}
		}
	}
}

// copy constructor
LListJar::LListJar(const LListJar& jar)
{
	for (int i = 0; i < jar.marble_number(); i++) {
		ll.push_back(jar.get_elem(i));
	}
}

// get_elem is useful for copying marbles;
// another possibility is to use a stack (less efficient)
const Marble& LListJar::get_elem(int i) const
{
	list<Marble>::const_iterator it = ll.begin()--;
	advance(it,i);
	return *it;
}

void LListJar::add(const Marble& m)
{
	if(!is_in_jar(m)) {  // is_in_jar checks for uniqeness BUG FIXED
		ll.push_back(m);
	}
}

bool LListJar::is_in_jar(const Marble& m) const
{
	list<Marble>:: const_iterator it = ll.begin()--;
	while(it != ll.end()) {
		if(*it == m) {
			return true;
		}
		advance(it,1);
	}
	return false;
}

void LListJar::remove(const Marble& m)
{
	list<Marble>::iterator it;
	
	for (it = ll.begin(); it != ll.end(); ++it) {
		if (*it == m) {
			ll.erase(it); // make yourself familiar with the functions of
			// list class in STL
			break;
		}
	}
}

Marble LListJar::remove_any()
{
	if (ll.empty()) throw Empty_jar();
	
	list<Marble>::iterator it;
	advance(it, rand() % ll.size());
	Marble temp = *it;
	ll.erase(it);
	return temp;
}

void LListJar::clear()
{
	ll.clear(); //Improved
}

int LListJar::marble_number() const
{
	return ll.size();
}

int LListJar::marble_nsize(Marble::Size s) const
{
	int num = 0;
	
	list<Marble> temp = ll;
	for (int i = 0; i < temp.size(); i++) {
		if(temp.front().get_size() == s)
			num++;
		temp.pop_front();
	}
	return num;
}

int LListJar::marble_ncolor(Marble::Color c) const
{
	int num = 0;
	
	list<Marble> temp = ll;
	for(int i = 0; i < temp.size(); i++){
		if(temp.front().get_color() == c)
			num++;
		temp.pop_front();
	}
	return num;
}

bool LListJar::is_empty() const
{
	return ll.empty();
}

void LListJar::merge(const Jar& jar1, const Jar& jar2)
{
	difference(jar1, jar2);
	
	for (int i = 0; i < jar2.marble_number(); i++) {
		add (jar2.get_elem(i));
	}
}

void LListJar::intersect(const Jar& jar1, const Jar& jar2)
{
	clear();
	
	for(int i = 0; i < jar1.marble_number(); i++) {
		for (int j = 0; j < jar2.marble_number(); j++) {
			if (jar1.get_elem(i) == jar2.get_elem(j)) { //BUG FIXED
				add(jar1.get_elem(i));
				break;
			}
		}
	}
}


void LListJar::difference(const Jar& jar1, const Jar& jar2)
{
	clear();
	
	for(int i = 0; i < jar1.marble_number(); i++) {
		bool found = false;
		for(int j = 0; j < jar2.marble_number(); j++) {
			if(jar1.get_elem(i) == jar2.get_elem(j)) {
				found = true;
				break;
			}
		}
		if(!found) {
			add(jar1.get_elem(i));
		}
	}
}
