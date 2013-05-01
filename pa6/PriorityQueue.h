//
//  PriorityQueue.h
//  
//
//  Created by Devin Tuchsen on 3/28/13.
//
//

#ifndef ____PriorityQueue__
#define ____PriorityQueue__

#include "BinaryHeap.h"
#include "PQComp.h"

class EmptyPriorityQueue {};

template<typename ElemType >
class PriorityQueue {
protected:
	typedef Item<ElemType > Item;
	typedef PQComp<ElemType > PQComp;
private:
	BinaryHeap<Item, PQComp > T;
	static const int DEF_SIZE = 8;
	ComparisonCounter* compCount;
public:
	PriorityQueue(int size = DEF_SIZE, ComparisonCounter* comp = NULL) : T(size, comp) {
		compCount = comp;
		if(compCount == NULL)
			compCount = new ComparisonCounter;
	}
	bool isEmpty() const {return T.isEmpty();}
	void insertItem(const int k, const ElemType& e) {T.insert(Item(k,e));}
	ComparisonCounter* getCompCounter() {return compCount;}
	const ElemType& minElement() throw(EmptyPriorityQueue) {
		if(T.isEmpty()) throw EmptyPriorityQueue();
			return T.findMin().getElem();
	}
	const int minKey() throw(EmptyPriorityQueue) {
		if(T.isEmpty()) throw EmptyPriorityQueue();
			return T.findMin().getKey();
	}
	void removeMin() throw(EmptyPriorityQueue) {
		if(T.isEmpty()) throw EmptyPriorityQueue();
			T.deleteMin();
	}
	void updateKey(const int k, const ElemType& e) {
		for(int i = 0; i < T.getLength(); ++i) {
			compCount->addCmp();
			if(T.elem(i).getElem() == e) {
				T.elem(i).setKey(k);
				T.shift(i);
				return;
			}
		}
	}
};

#endif /* defined(____PriorityQueue__) */
