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
	map<string, string> s;

	s["Maryland"] = "Salisbury";
	s["Delaware"] = "Milford";
	s["New York"] = "New York City";
	s["California"] = "Los Angelas";
	s["Colorado"] = "Denver";

	string state;

	cout << "Enter a state: \n";
	cin >> state;

	map<string, string>::iterator iter;

	iter = s.find(state);
	if(iter != s.end())
		cout << iter->second << endl;
	else
		cout << "State is not found in map\n";
}
