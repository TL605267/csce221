//
//  VectorPriorityQueue.h
//
//
//  Created by Devin Tuchsen on 4/5/13.
//
//

#ifndef _VectorPriorityQueue_h
#define _VectorPriorityQueue_h

#include <climits>
#include <vector>

template<typename ElemType >
class VectorPriorityQueue {
protected:
	typedef Item<ElemType > Item;
	typedef PQComp<ElemType > PQComp;
private:
	std::vector<Item > T;
	static const int DEF_SIZE = 8;
public:
	VectorPriorityQueue() {}
	bool isEmpty() const {return T.empty();}
	void insertItem(const int k, const ElemType& e) {T.push_back(Item(k,e));}
	const ElemType& minElement() throw(EmptyPriorityQueue) {
		if(T.empty())
			throw EmptyPriorityQueue();
			ElemType *min = new ElemType;
		int minKey = INT_MAX;
		for(int i = 0; i < T.size(); ++i)
			if(T[i].getKey() < minKey) {
				minKey = T[i].getKey();
				*min = T[i].getElem();
			}
		return *min;
	}
	const int minKey() throw(EmptyPriorityQueue) {
		if(T.empty()) throw EmptyPriorityQueue();
			int minKey = INT_MAX;
		for(int i = 0; i < T.size(); ++i)
			if(T[i].getKey() < minKey)
				minKey = T[i].getKey();
				return minKey;
	}
	void removeMin() throw(EmptyPriorityQueue) {
		if(T.empty()) throw EmptyPriorityQueue();
			int minKey = INT_MAX;
		int j = 0;
		for(int i = 0; i < T.size(); ++i)
			if(T[i].getKey() < minKey) {
				minKey = T[i].getKey();
				j = i;
			}
		T.erase(T.begin()+j);
	}
};

#endif
