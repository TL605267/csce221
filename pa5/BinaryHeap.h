//
//  BinaryHeap.h
//  
//
//  Created by Devin Tuchsen on 3/28/13.
//
//

#ifndef ____BinaryHeap__
#define ____BinaryHeap__

#include <iostream>

class EmptyHeap {};

template<typename ElemType, typename Comp >
class BinaryHeap {
	Comp comp;
	int curSize;
	ElemType *array;
	int length;
	static const int DEF_SIZE = 8;
	void getNewArray(int newSize) {
		array = new ElemType[newSize];
		length = newSize;
	}
public:
	BinaryHeap(int size = DEF_SIZE) {
		curSize = 0;
		getNewArray(size);
	}
	ElemType& findMin() throw(EmptyHeap) {
		if(isEmpty()) throw EmptyHeap();
			return array[0];
	}
	bool isEmpty() const {return curSize == 0;}
	void buildHeap();
	void insert(const ElemType& x);
	void deleteMin() throw(EmptyHeap);
	void walkDown(int hole);
};

template<typename ElemType, typename Comp >
void BinaryHeap<ElemType, Comp >::insert(const ElemType& x) {
	int hole = curSize++;
	for(; hole > 0 && comp(array[(hole-1)/2], x) > 0; hole = (hole-1)/2)
		array[hole] = array[(hole-1)/2];
	array[hole] = x;
}

template<typename ElemType, typename Comp >
void BinaryHeap<ElemType, Comp >::walkDown(int hole) {
	int child;
	ElemType key = array[hole];
	for(; 2*hole+1 < curSize; hole = child) {
		child = 2*hole+1;
		if(child != curSize-1 && comp(array[child], array[child+1]) > 0)
			++child;
		if(comp(key, array[child]) > 0)
			array[hole] = array[child];
		else break;
	}
	array[hole] = key;
}

template<typename ElemType, typename Comp >
void BinaryHeap<ElemType, Comp >::deleteMin() throw(EmptyHeap) {
	array[0] = array [--curSize];
	walkDown(0);
}

#endif /* defined(____BinaryHeap__) */
