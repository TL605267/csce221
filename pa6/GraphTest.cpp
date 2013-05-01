#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int main()
{
	// you can use the following code to test your graph.
	// you can also change your input file to do more testing
	// verify the results
	
	string str;
	
	cout << "Enter filename of graph: ";
	cin >> str;
	Graph graph(str);
	cout << endl;
	
	while(true) {
		cout << "1) Add vertex" << endl
		<< "2) Add edge" << endl
		<< "3) Print adjacent vertices" << endl
		<< "4) Print entire graph" << endl
		<< "5) Compute shortest path" << endl
		<< "6) Exit" << endl;
		cout << "Enter choice: ";
		int choice;
		cin >> choice;
		cout << endl;
		
		int x,y,weit;
		Vertex* u = NULL;
		Vertex* z = NULL;
		Edge* e = NULL;
		
		switch(choice) {
			case 1:
				graph.addVertex();
				cout << "Vertex added." << endl;
				break;
			case 2:
				cout << "Enter source vertex: ";
				cin >> x;
				u = graph.getVertices()[x-1];
				cout << "Enter end vertex: ";
				cin >> y;
				z = graph.getVertices()[y-1];
				cout << "Enter weight: ";
				cin >> weit;
				e = new Edge(u,z,weit);
				graph.addEdge(e);
				cout << "Edge added." << endl;
				break;
			case 3:
				cout << "Enter vertex: ";
				cin >> x;
				u = graph.getVertices()[x-1];
				cout << "Outgoing vertices: ";
				for(unsigned int i = 0; i < graph.getVertices()[x-1]->getOutEdges().size(); ++i)
					cout << graph.getVertices()[x-1]->getOutEdges()[i]->geteVertP()->getID() << ' ';
				cout << endl << "Incoming vertices: ";
				for(unsigned int i = 0; i < graph.getVertices()[x-1]->getInEdges().size(); ++i)
					cout << graph.getVertices()[x-1]->getInEdges()[i]->getsVertP()->getID() << ' ';
				cout << endl;
				break;
			case 4:
				graph.PrintGraph();
				break;
			case 5:
				cout << "Enter first vertex: ";
				cin >> x;
				u = graph.getVertices()[x-1];
				cout << "Enter second vertex: ";
				cin >> y;
				z = graph.getVertices()[y-1];
				graph.PrintShortestPath(u, z);
				break;
			case 6:
				return 0;
			default:
				break;
		}
		cout << endl;
	}
	return 0;
}
