#ifndef COUNTONECHILD_H
#define COUNTONECHILE_H

#include "d_tnode.h"
#include "d_tnodel.h"

template <typename T>
void countOneChild (tnode<T> * t, int& count)
{
	if (t!= NULL)
	{
		if ((t->left == NULL || t->right == NULL) && (t->left != NULL || t->right != NULL))
			count++;

		countOneChild(t->left, count);
		countOneChild(t->right, count);
	}
}

#endif
