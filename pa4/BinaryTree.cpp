//
//  BinaryTree.cpp
//  
//
//  Created by Devin Tuchsen on 3/18/13.
//
//

#include <queue>
#include "BinaryTree.h"

double BinaryTree::avgSearchCost(BinaryNode *node, int *cost) {
	*cost += node->getSearchCost();
	if (node->left != NULL)
		avgSearchCost(node->left, cost);
	if (node->right != NULL)
		avgSearchCost(node->right, cost);
	return (double)(*cost) / (double)(size());
}

void BinaryTree::merge(int rootItem, BinaryTree& t1, BinaryTree& t2) {
	if (t1.root == t2.root && t1.root != NULL) {
		std::cerr << "Left tree == right tree; "
				  << "merge aborted" << std::endl;
		return;
	}
	if(this != &t1 && this != &t2) deleteTree(root);
	root = new BinaryNode(rootItem, 1, t1.root, t2.root);
	if(this != &t1) t1.root = NULL;
	if(this != &t2) t2.root = NULL;
}

void BinaryTree::deleteTree(BinaryNode *root) {
	if (root == NULL) return;
	if (root->left != NULL)
		deleteTree(root->left);
	if(root->right != NULL)
		deleteTree(root->right);
	delete root;
}

BinaryNode *BinaryTree::findMin(BinaryNode *t) throw(EmptyTree) {
	if(t == NULL)
		throw EmptyTree();
	while(t->left != NULL) t = t->left;
	return t;
}

BinaryNode *BinaryTree::removeMin(BinaryNode *t) throw(ItemNotFound) {
	if(t == NULL) throw ItemNotFound();
	if(t->left != NULL)
		t->left = removeMin(t->left);
	else {
		BinaryNode *node = t;
		t = t->right;
		delete node;
	}
	return t;
}

//Recursive function for insertNode
void insertRecur(BinaryNode *node, int el, int numCmps) {
	++numCmps;
	if(el < node->getElem()) {
		if(node->left == NULL)
			node->left = new BinaryNode(el, numCmps);
		else
			insertRecur(node->left, el, numCmps);
	}
	else {
		if(node->right == NULL)
			node->right = new BinaryNode(el, numCmps);
		else
			insertRecur(node->right, el, numCmps);
	}
}

void BinaryTree::insertNode(int el) {
	BinaryNode *node = root;
	if (root == NULL)
		root = new BinaryNode(el);
	else
		insertRecur(root, el, 1);
}

BinaryNode *BinaryTree::removeNode(int el, BinaryNode *t) throw(ItemNotFound) {
	if(t == NULL)
		throw ItemNotFound();
	if(el < t->element)
		t->left = removeNode(el, t->left);
	else if(el > t->element)
		t->right = removeNode(el, t->right);
	else if(t->left != NULL && t->right != NULL) {
		t->element = findMin(t->right)->element;
		t->right = removeMin(t->right);
	} else {
		BinaryNode *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
	}
	return t;
}

//Overloaded << operator, for output
ostream& operator<<(ostream& os, const BinaryTree& bt) {
	if(bt.isEmpty()) return os;
	queue<BinaryNode*> nodeQueue;
	int currLevel = 1;
	int nextLevel = 0;
	int currHeight = -1;
	nodeQueue.push(bt.getRoot());
	while (!nodeQueue.empty()) {
		BinaryNode *node = nodeQueue.front();
		nodeQueue.pop();
		--currLevel;
		if(node != NULL) {
			os << node->getElem() << '[' << node->getSearchCost() << "] ";
			nodeQueue.push(node->getLeft());
			nodeQueue.push(node->getRight());
			nextLevel += 2;
		}
		else if(currHeight != bt.height())
			os << "X ";
		if(currLevel == 0) {
			os << endl;
			currLevel = nextLevel;
			nextLevel = 0;
			++currHeight;
		}
	}
	return os;
}
