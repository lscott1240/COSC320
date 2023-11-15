/*
 * Luke Scott
 * COSC 320
 * Lab 6
 * Dr. Lu
*/

#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

using namespace std;

int main()
{
	set<stateCity> s;

	stateCity sal("Maryland","Salisbury");
	stateCity mil("Delaware","Milford");
	stateCity nyc("New York","New York City");
	stateCity la("California","Los Angelas");
	stateCity den("Colorado","Denver");

	s.insert(sal);
	s.insert(mil);
	s.insert(nyc);
	s.insert(la);
	s.insert(den);

	string state;

	cout << "Enter a state: ";
	cin >> state;

	bool found = true;

	set<stateCity>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		if (iter->stateName == state)
		{
			cout << *iter << endl;
			found = false;
		}

	if (found)
		cout << "City not found" << endl;
}
