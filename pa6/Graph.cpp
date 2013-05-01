#include "Graph.h"

void Graph::Dijkstra(Vertex* v) {
	PriorityQueue<Vertex*> q(vertList.size(), comp);
	for(unsigned int i = 0; i < vertList.size(); ++i) { // Initialize d[u] and π[u] for each vertex u in vertList
		Vertex* u = vertList[i];
		u->d = INT_MAX;
		u->p = NULL;
	}
	v->d = 0;
	for(unsigned int i = 0; i < vertList.size(); ++i) { // Initialize the MPQ
		Vertex* u = vertList[i];
		q.insertItem(u->d,u);
	}
	while(!q.isEmpty()) {
		Vertex* u = q.minElement();
		q.removeMin();
		for(unsigned int i = 0; i < u->getOutEdges().size(); ++i) { // Relax each edge
			Edge* e = u->getOutEdges()[i]; 
			Vertex* z = e->geteVertP();
			if(z->d >= u->d + e->getWeight()) {
				z->d = u->d + e->getWeight();
				z->p = u;
				q.updateKey(z->d, z);
			}
		}
	}
}

Graph::Graph(string filename) {
	comp = new ComparisonCounter;
	ifstream ifs(filename.c_str());
	int vertnum;
	ifs>>vertnum;
	for(int i=0;i<vertnum;i++) // push all vertices into the vertex vector before assigning the in and out list
	{
		Vertex *vert = new Vertex(i+1);
		vertList.push_back(vert);
	}
	int svert,evert,weit;
	ifs>>svert;
	while(svert!=-1)
	{
		ifs>>evert;
		while(evert!=-1)
		{
			ifs>>weit; // one weight means one edge
			Edge *tempedge = new Edge(vertList[svert-1],vertList[evert-1],weit); // new edge
			edgeList.push_back(tempedge);
			vertList[svert-1]->outList.push_back(tempedge);
			vertList[evert-1]->inList.push_back(tempedge);
			ifs>>evert;
		}
		ifs>>svert;
	}
	ifs.close();
}

Graph::~Graph() {
	for(unsigned int i = 0; i < vertList.size(); i++)
		delete vertList[i];
	for(unsigned int i = 0; i < edgeList.size(); i++)
		delete edgeList[i];
	delete comp;
}

void Graph::PrintGraph() {
	cout << vertList.size() << endl;
	for(unsigned int i = 0; i < vertList.size(); ++i) {
		Vertex* v = vertList[i];
		cout << v->getID() << ' ';
		for(unsigned int i = 0; i < v->getOutEdges().size(); ++i) {
			Edge* e = v->getOutEdges()[i];
			cout << e->geteVertP()->getID() << ' ' << e->getWeight() << ' ';
		}
		cout << "-1" << endl;
	}
	cout << "-1" << endl;
}

void Graph::addVertex() {
	Vertex* v = new Vertex(vertList.size() + 1);
	vertList.push_back(v);
}

void Graph::addEdge(Edge* e) {
	edgeList.push_back(e);
	e->getsVertP()->outList.push_back(e);
	e->geteVertP()->inList.push_back(e);
}

void Graph::PrintShortestPath(Vertex* v, Vertex* u) {
	Dijkstra(v); // Do some magic
	Vertex* p = u->p;
	vector<Vertex*> vec;
	vec.push_back(u);
	while(p != NULL) { // Create a chain of vertices (the path)
		vec.push_back(p);
		p = p->p;
	}
	for(int i = vec.size() - 1; i >= 0; --i) { // Print in reverse order
		cout << vec[i]->getID();
		if(i != 0)
			cout << " -[" << vec[i-1]->d - vec[i]->d << "]-> ";
	}
	cout << endl;
	cout << "Total weight of the shortest path from " << v->getID() << " to " << u->getID() << ": " << u->d << endl;
	cout << "Total number of comparisons: " << comp->getCmps() << endl;
	comp->reset();
}
