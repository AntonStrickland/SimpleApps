#include "Words.h"
#include <iostream>
#include <string>
using namespace std;

void Words::Run()
{
	Reverse();
}

void Words::Reverse()
{
	string theString = "";
	cout << "This program will reverse every word in a string, but keep the words in order." << endl;
	cout << "Please enter a string: " << endl;
	getline(cin, theString);

	string newString = "";

	int wordStartIndex = 0;

	if (theString[theString.length() - 1] != ' ')
		theString += ' ';

	int length = theString.length();

	for (int i = 0; i < length; i++)
	{
		if (theString[i] == ' ')
		{
			for (int k = i; k >= wordStartIndex; k--)
			{
				newString += theString[k];
			}
			wordStartIndex = i + 1;
		}
	}

	cout << "Result: " << newString << endl;
}