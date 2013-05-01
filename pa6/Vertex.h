#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "Edge.h"

using namespace std;

class Graph;
class Edge;

class Vertex {

private:
	vector<Edge*> inList; // source vertex
    vector<Edge*> outList; // end vertex 
	int id;
	friend class Graph;
	unsigned int d; // d[v]
	Vertex* p; // π[v]
public:
	Vertex(int sid);
	int getID() const;
	vector<Edge*> getOutEdges() const;
	vector<Edge*> getInEdges() const;
};

#endif
