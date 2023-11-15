/*
 * Luke Scott
 * COSC 320
 * Lab 5
 * Dr. Lu
*/

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <utility>

#include "int.h"
#include "d_except.h"
#include "d_stree.h"

int main()
{
    srand(time(0));

    stree<integer> int_Tree;

    for(int i = 0; i < 10000; i++){
        
        int rndNum = rand() % 7;

        stnode<integer> *searchN = int_Tree.findNode(rndNum);

        if(searchN == NULL)
            int_Tree.insert(rndNum);
        
	else
            searchN->nodeValue.incCount();
    }

    stnode<integer> *temp;

    for(int i = 0; i < 7; i++)
    {
        temp = int_Tree.findNode(i);
        std::cout << temp->nodeValue << std::endl;
    }

    std::cout << std::endl;

    std::cout << "The Tree:" << std::endl;
    int_Tree.displayTree(4);
}
