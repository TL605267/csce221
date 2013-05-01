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
public:
	PriorityQueue(int size = DEF_SIZE) : T(size) {}
	bool isEmpty() const {return T.isEmpty();}
	void insertItem(const int k, const ElemType& e) {T.insert(Item(k,e));}
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
};

#endif /* defined(____PriorityQueue__) */
