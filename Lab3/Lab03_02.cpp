#include <iostream>
#include "d_tnode.h"
#include "d_tnodel.h"
#include "countOneChild.h"
#include "max.h"

using namespace std;

int main()
{
	int maxValue = 0;
	tnode<int> * root = buildIntTree(3);
	maxValue = max(root, maxValue);
	cout << "\nMax value in Tree 2: " << maxValue;

	cout << "\nTesting sample outputs for max:\n-------------------------";
	
	tnode<int> * root0 = buildIntTree(0);
	tnode<int> * root1 = buildIntTree(1);
	tnode<int> * root2 = buildIntTree(2);


	maxValue = 0;
	maxValue = max(root0, maxValue);
	cout << "\nMax value in test tree 0: " << maxValue;
	maxValue = 0;
	maxValue = max(root1, maxValue);
	cout << "\nMax value in test tree 1: " << maxValue;
	maxValue = 0;
	maxValue = max(root2, maxValue);
	cout << "\nMax value in test tree 2: " << maxValue << endl;
}
