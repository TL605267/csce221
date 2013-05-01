#include <stdexcept>
#include "vector_jar.h"

//Constructor for given length
VectorJar::VectorJar(int len) {
    for(int i = 0; i < len; ++i)
		while(true) {
			Marble m;
			if(!is_in_jar(m)) {
				vec.push_back(m);
				break;
			}
		}
}

//Copy constructor
VectorJar::VectorJar(const VectorJar& jar) {
	for(int i = 0; i < jar.marble_number(); ++i) {
		vec[i] = jar.get_elem(i);
	}
}

//Gets an element from the jar
const Marble& VectorJar::get_elem(int i) const {
	return vec[i];
}

//Adds an alement to the jar if it does not already exist
void VectorJar::add(const Marble& m) {
	if(!is_in_jar(m))
		vec.push_back(m);
}

//Checks to see if m exists in the jar
bool VectorJar::is_in_jar(const Marble& m) const {
	for(int i = 0; i < vec.size(); ++i)
		if(vec[i] == m)
			return true;
	return false;
}

//Removes given marble from the jar
void VectorJar::remove(const Marble& m) {
	for(int i = 0; i < vec.size(); ++i) {
		if(m == vec[i]) {
			vec.erase(vec.begin() + i);
			return;
		}
	}
	runtime_error("Marble does not exist!");
}

//Removes some random marble from the jar and returns it
Marble VectorJar::remove_any() {
	srand(time(NULL));
	int i;
	if(!vec.empty())
		i = rand() % vec.size();
	else
		runtime_error("No marbles in jar!");
	Marble m = vec[i];
	vec.erase(vec.begin() + i);
	return m;
}

//Clears the jar
void VectorJar::clear() {
	vec.clear();
}

//Returns the number of marbles in the jar
int VectorJar::marble_number() const {
	return vec.size();
}

//Returns the number of marbles with size s in the jar
int VectorJar::marble_nsize(Marble::Size s) const {
	int n = 0;
	for(int i = 0; vec.size(); ++i)
		if(vec[i].get_size() == s)
			++n;
	return n;
}

//Returns the number of marbles with color c in the jar
int VectorJar::marble_ncolor(Marble::Color c) const {
	int n = 0;
	for(int i = 0; i < vec.size(); ++i)
		if(vec[i].get_color() == c)
			++n;
	return n;
}

//Determines if the jar is empty
bool VectorJar::is_empty() const {
	return vec.empty();
}

//Merges two jars
void VectorJar::merge(const Jar& jar1, const Jar& jar2) {
	difference(jar1,jar2);
	
	for (int i = 0; i < jar2.marble_number(); ++i)
		if(!is_in_jar(jar2.get_elem(i)))
			vec.push_back(jar2.get_elem(i));
	
}

//Intersects two jars
void VectorJar::intersect(const Jar& jar1, const Jar& jar2) {
	vec.clear();
	for(int i = 0; i < jar1.marble_number(); ++i)
		for(int j = 0; j < jar2.marble_number(); ++j)
			if(jar1.get_elem(i) == jar2.get_elem(j))
				if(!is_in_jar(jar1.get_elem(i))) {
					vec.push_back(jar1.get_elem(i));
					break;
				}
}

//Finds the difference of two jars
void VectorJar::difference(const Jar& jar1, const Jar& jar2) {
	vec.clear();
	for(int i = 0; i < jar1.marble_number(); ++i) {
		bool in_jar2 = false;
		for(int j = 0; j < jar2.marble_number(); ++j) {
			if(jar1.get_elem(i) == jar2.get_elem(j)) {
				in_jar2 = true;
				break;
			}
		}
		if(!in_jar2 && !is_in_jar(jar1.get_elem(i)))
			vec.push_back(jar1.get_elem(i));
	}
}
