/*
 * Luke Scott
 * COSC 320
 * Lab 7
 * Dr. Lu
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "d_except.h"
#include "d_hash.h"
#include "d_hashf.h"

using namespace std;

ifstream& getWord(ifstream& fin, string& w);

int main()
{
	myhash<string, hFstring>hash(1373);

	ifstream file ("dict.dat");
	if(file.is_open())
	{
		string word;

		for (int i = 0; i < 25025; i++)
		{
			file >> word;
			hash.insert(word);
		}
	}
	else
		cout << "File Open Error\n";

	file.close();

	string document;

	cout << "Enter the name for the document: ";
	cin >> document;

	ifstream output (document);

	string getword;

	if (output.is_open())
	{
		cout << "Words mispelled :\n";
		while (!output.eof())
		{
			getWord(output, getword);
			if (hash.end() == hash.find(getword))
				cout << getword << endl;
		}
		output.close();
	}
	else
		cout << "File Open Error\n";
}


ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}
