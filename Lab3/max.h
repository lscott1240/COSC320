#ifndef COUNTONECHILD_H
#define COUNTONECHILE_H

#include "d_tnode.h"
#include "d_tnodel.h"

template <typename T>
int max (tnode<T> * t, int& maxV)
{
	if (t!= NULL)
	{
		if (t->nodeValue > maxV)
			maxV = t->nodeValue;

		max(t->left, maxV);
		max(t->right, maxV);
	}

	return maxV;
}

#endif
