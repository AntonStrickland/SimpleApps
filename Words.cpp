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
	string newString = "";
	int wordStartIndex = 0;

	cout << "This program will reverse every word in a string, but keep the words in order." << endl;
	cout << "Please enter a string: " << endl;
	getline(cin, theString);

	// If the final word does not end with a space, add an extra space to the end
	if (theString[theString.length() - 1] != ' ')
		theString += ' ';

	int length = theString.length();

	for (int i = 0; i < length; i++)
	{
		// Move forward until we reach the end of a word
		if (theString[i] == ' ')
		{
			// Add that word backwards into the new string
			for (int k = i; k >= wordStartIndex; k--)
			{
				newString += theString[k];
			}
			wordStartIndex = i + 1;
		}
	}

	cout << "Result: " << newString << endl;
}