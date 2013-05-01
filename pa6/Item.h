//
//  Item.h
//  
//
//  Created by Devin Tuchsen on 3/28/13.
//
//

#ifndef _Item_h
#define _Item_h

template<typename ElemType >
class Item {
	int key;
	ElemType elem;
public:
	Item(const int k = 0, const ElemType& e = ElemType()) : key(k), elem(e) {}
	const int getKey() const {return key;}
	const ElemType& getElem() const {return elem;}
	void setKey(const int k) {key = k;}
	void setElem(const ElemType& e) { elem = e; }
};

#endif
