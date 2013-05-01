#include "Edge.h"

Edge::Edge() {
	
}

Edge::Edge(Vertex* svert, Vertex* evert,int weit) : sVertP(svert), eVertP(evert), weight(weit) {}

int Edge::getWeight() {
	return weight;
}

Vertex* Edge::getsVertP() {
	return sVertP;
}

Vertex* Edge::geteVertP() {
	return eVertP;
}
