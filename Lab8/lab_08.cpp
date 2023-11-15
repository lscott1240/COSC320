/*
 * Luke Scott
 * COSC 320
 * Lab 8
 * Dr. Lu
*/

#include <iostream>
#include <cstdlib>

#include "d_except.h"
#include "d_pqueue.h"
#include "d_heap.h"
#include "preqrec.h"

int main()
{
	miniPQ <procReqRec> mpq;
	
	srand(time(0));

	procReqRec A("Process A", rand() % 39);
	procReqRec B("Process B", rand() % 39);
	procReqRec C("Process C", rand() % 39);
	procReqRec D("Process D", rand() % 39);
	procReqRec E("Process E", rand() % 39);
	procReqRec F("Process F", rand() % 39);
	procReqRec G("Process G", rand() % 39);
	procReqRec H("Process H", rand() % 39);
	procReqRec I("Process I", rand() % 39);
	procReqRec J("Process J", rand() % 39);

	mpq.push(A);
	mpq.push(B);
	mpq.push(C);
	mpq.push(D);
	mpq.push(E);
	mpq.push(F);
	mpq.push(G);
	mpq.push(H);
	mpq.push(I);
	mpq.push(J);

	while (!mpq.empty())
	{
		cout << mpq.top() << endl;
		mpq.pop();
	}
}
