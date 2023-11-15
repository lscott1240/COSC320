#include <iostream>
#include "d_tnode.h"
#include "d_tnodel.h"
#include "countOneChild.h"

using namespace std;

int main()
{
	int count;
	tnode<char> * root = buildTree(3);
	countOneChild(root, count);

	cout << "\nNumber of nodes with one child for Tree 1: " << count;

	cout << "\nTesting Sample outputs:\n-----------------------" << endl;

	tnode <char> * root0 = buildTree(0);
	tnode <char> * root1 = buildTree(1);
	tnode <char> * root2 = buildTree(2);

	count = 0;
	countOneChild(root0, count);
	cout << "\nNumber of nodes with one child for test Tree 0: " << count;
	count = 0;
	countOneChild(root1, count);
	cout << "\nNumber of nodes with one child for test Tree 1: " << count;
	count = 0;
	countOneChild(root2, count);
	cout << "\nNumber of nodes with one child for test Tree 2: " << count << endl;


}
