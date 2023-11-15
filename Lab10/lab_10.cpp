/*
 * Luke Scott
 * COSC 320
 * Lab 10
 * Dr. Lu
*/

#include <iostream>
#include <string>
#include <fstream>
#include "d_graph.h"
#include "d_util.h"

using namespace std;

int main()
{
	graph<string> B;

	int vert, edge;

	ifstream file;
	file.open("graphB.dat");
	file >> vert;

	for (int i = 0; i < vert; i++)
	{
		string temp;
		file >> temp;
		B.insertVertex(temp);
	}

	file >> edge;

	for (int i = 0; i < edge; i++)
	{
		string one, two;
		int w;
		file >> one >> two >> w;
		B.insertEdge(one, two, w);
	}

	string input;
	cout << "Insert a Vertex: \n";
	cin >> input;

	set<string> visitedVertices = bfs(B, input);

	set<string>::iterator startbfs = visitedVertices.begin();
	set<string>::iterator lastbfs = visitedVertices.end();
	writeContainer(startbfs, lastbfs, " ");

	list<string> reverseVert = { "F", "E", "D", "C", "B", "A" };
	dfs(B, reverseVert);

	list<string>::iterator startdfs = reverseVert.begin();
	list<string>::iterator lastdfs = reverseVert.end();
	cout << endl;
	writeContainer(startdfs, lastdfs, " ");
	cout << endl;

	return 0;
}
