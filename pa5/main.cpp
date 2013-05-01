#include "PriorityQueue.h"
#include "VectorPriorityQueue.h"
#include <iostream>
#include <fstream>

template<typename ElemType>
PriorityQueue<ElemType> createPriorityQueue(std::string filename) {
	std::ifstream is(filename.c_str());
	int size, key;
	ElemType elem;
	
	is >> size;
	PriorityQueue<ElemType> pq(size);
	while (is.good())
		if(is.good()) {
			is >> key;
			is >> elem;
			pq.insertItem(key, elem);
		}
	return pq;
}

template<typename ElemType>
VectorPriorityQueue<ElemType> createVectorPriorityQueue(std::string filename) {
	std::ifstream is(filename.c_str());
	int size, key;
	ElemType elem;
	
	is >> size;
	VectorPriorityQueue<ElemType> pq;
	while (is.good())
		if(is.good()) {
			is >> key;
			is >> elem;
			pq.insertItem(key, elem);
		}
	return pq;
}

int main() {
	std::string filename = "in.txt";
	std::cout << "Building binary-heap based priority queue with filename: " << filename << std::endl;
	PriorityQueue<std::string> pq = createPriorityQueue<std::string>(filename);
	
	if(pq.isEmpty()) {
		std::cout << "Queue is empty!" << std::endl;
		return 0;
	}
	std::cout << "Min element: " << pq.minElement() << std::endl;
	std::cout << "Min key: " << pq.minKey() << std::endl;
	pq.removeMin();
	std::cout << std::endl << "After removing the minimum element..." << std::endl;
	std::cout << "Min element: " << pq.minElement() << std::endl;
	std::cout << "Min key: " << pq.minKey() << std::endl;
	
	std::cout << std::endl << "Building vector based priority queue with filename: " << filename << std::endl;
	VectorPriorityQueue<std::string> vpq = createVectorPriorityQueue<std::string>(filename);
	
	if(vpq.isEmpty()) {
		std::cout << "Queue is empty!" << std::endl;
		return 0;
	}
	std::cout << "Min element: " << vpq.minElement() << std::endl;
	std::cout << "Min key: " << vpq.minKey() << std::endl;
	vpq.removeMin();
	std::cout << std::endl << "After removing the minimum element..." << std::endl;
	std::cout << "Min element: " << vpq.minElement() << std::endl;
	std::cout << "Min key: " << vpq.minKey() << std::endl;
	
	return 0;
}
