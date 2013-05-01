//
//  BinaryNode.h
//  
//
//  Created by Devin Tuchsen on 3/18/13.
//
//

#ifndef ____BinaryNode__
#define ____BinaryNode__

#include <iostream>

class BinaryNode {
	friend class BinaryTree;
	int element;
	int searchCost;
public:
	BinaryNode *left, *right;
	BinaryNode(int el = 0, int sc = 1, BinaryNode *lt = NULL, BinaryNode *rt = NULL) : element(el), searchCost(sc), left(lt), right(rt) {}
	BinaryNode *getLeft() { return left; }
	BinaryNode *getRight() { return right; }
	int getElem() { return element; }
	int getSearchCost() { return searchCost; }
	int size(BinaryNode *t);
	int height(BinaryNode *t);
	BinaryNode *copy();
};

#endif /* defined(____BinaryNode__) */
