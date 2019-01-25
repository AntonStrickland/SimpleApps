#include "Palindrome.h"
#include <iostream>
#include <string>
using namespace std;

void Palindrome::Run()
{
	string word = "";
	cout << "This program will verify whether a word is a palindrome or not." << endl;
	cout << "Please enter a word to verify: " << endl;
	cin >> word;

	bool isPalindrome = true;
	int length = word.length() - 1;

	for (int i = 0; i < length+1; i++)
	{
		//cout << word[i] << " == " << word[length - i] << endl;
		if (word[i] != word[length - i])
			isPalindrome = false;
	}

	if (isPalindrome)
	{
		cout << "Yes, the word '" + word + "' is a palindrome!" << endl;
	}
	else
	{
		cout << "No, the word '" + word + "' is NOT a palindrome!" << endl;
	}
}