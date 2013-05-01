#include "Vertex.h"

Vertex::Vertex(int sid) : id(sid) {}

int Vertex::getID() const {
	return id;
}

vector<Edge*> Vertex::getOutEdges() const {
	return outList;
}

vector<Edge*> Vertex::getInEdges() const {
	return inList;
}
