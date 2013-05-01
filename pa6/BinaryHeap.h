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
#include "ComparisonCounter.h"

class EmptyHeap {};

template<typename ElemType, typename Comp >
class BinaryHeap {
	Comp comp;
	ComparisonCounter* compCount;
	int curSize;
	ElemType *array;
	int length;
	static const int DEF_SIZE = 8;
	void getNewArray(int newSize) {
		array = new ElemType[newSize];
		length = newSize;
	}
public:
	BinaryHeap(int size = DEF_SIZE, ComparisonCounter* comp = NULL) {
		curSize = 0;
		getNewArray(size);
		compCount = comp;
		if(compCount == NULL)
			compCount = new ComparisonCounter;
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
	ElemType& elem(int i) {
		return array[i];
	}
	int getLength() {
		return curSize;
	}
	void shift(int i);
	ComparisonCounter* getCompCounter() {return compCount;}
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
		compCount->addCmp();
		if(child != curSize-1 && comp(array[child], array[child+1]) > 0)
			child++;
		compCount->addCmp();
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

template<typename ElemType, typename Comp >
void BinaryHeap<ElemType, Comp >::shift(int i) {
	while(comp(array[i], array[i-1]) < 0 && i > 0) {
		//compCount->addCmp();
		ElemType tmp = array[i-1];
		array[i-1] = array[i];
		array[i] = tmp;
		--i;
	}
}

#endif /* defined(____BinaryHeap__) */
