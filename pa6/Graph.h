#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include "Vertex.h"
#include "Edge.h"
#include "PriorityQueue.h"

using namespace std;

class Edge;
class Vertex;

class Graph{
private:
	vector<Vertex*> vertList;
	vector<Edge*> edgeList;
	ComparisonCounter* comp;
	void Dijkstra(Vertex* v);
public:
	Graph(string filename);
	~Graph();
	vector<Vertex*> getVertices() const {return vertList;}
	void addVertex();
	void addEdge(Edge* e);
	void PrintGraph(); // print out all the edges and associated vertices in the entire graph
	void PrintShortestPath(Vertex* u, Vertex* v);
};

#endif
