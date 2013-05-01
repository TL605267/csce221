//
//  BinaryTree.h
//
//
//  Created by Devin Tuchsen on 3/18/13.
//
//

#ifndef ____BinaryTree__
#define ____BinaryTree__

#include <iostream>
#include "BinaryNode.h"

using namespace std;

class EmptyTree {};
class ItemNotFound {};

class BinaryTree {
	BinaryNode *root;
	void deleteTree(BinaryNode *root);
public:
	BinaryTree() { root = NULL; }
	BinaryTree(int el) { root = new BinaryNode(el); }
	~BinaryTree() { deleteTree(root); root = NULL; }
	
	BinaryNode *getRoot() const { return root; }
	bool isEmpty() const { return root == NULL; }
	int size() { return (root == NULL) ? 0 : root->size(root); }
	int height() const { return (root == NULL) ? 0 : root->height(root); }
	double avgSearchCost(BinaryNode *root, int *cost);
	void copy(BinaryTree& rhs) {
		if (this != &rhs) {
			deleteTree(root);
			if(rhs.root != NULL)
				root = rhs.root->copy();
		}
	}
	void merge(int rootItem, BinaryTree& t1, BinaryTree& t2);
	BinaryNode* findMin(BinaryNode *t) throw(EmptyTree);
	BinaryNode* removeMin(BinaryNode *t) throw(ItemNotFound);
	void insertNode(int el);
	BinaryNode* removeNode(int el, BinaryNode *t) throw(ItemNotFound);
};

ostream& operator<<(ostream& os, const BinaryTree& bt);

#endif /* defined(____BinaryTree__) */
