/*
 * Luke Scott
 * COSC 320
 * Lab 9
 * Dr. Lu
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <set>
#include "d_graph.h"

using namespace std;

int main()
{
	graph<char> A;

	int vert, edge;

	ifstream file;
	file.open("graphA.dat");
	file >> vert;

	for (int i = 0; i < vert; i++)
	{
		char temp;
		file >> temp;

		A.insertVertex(temp);
	}

	file >> edge;
	for (int i = 0; i < edge; i++)
	{
		char one, two;
		int w;
		file >> one >> two >> w;
		A.insertEdge(one, two, w);
	}

	A.insertEdge('F', 'D', 1);
	A.eraseVertex('B');
	A.eraseEdge('A', 'D');

	char usr;
	cout << "Insert a Vertex: \n";
	cin >> usr;

	set<char> aVert;

	aVert = A.getNeighbors(usr);

	set<char>::iterator it = aVert.begin();
	cout << "Neighbors of " << usr << ":\n";
	while (it != aVert.end())
	{
		cout << *it << " ";
		it++;
	}

	A.insertVertex('G');
	A.insertEdge('G', 'C', 1);
	A.insertEdge('G', 'F', 1);
	A.insertEdge('D', 'G', 1);
	cout << endl << A;
}
