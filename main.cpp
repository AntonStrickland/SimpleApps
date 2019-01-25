// Programmer: Anton Strickland

#include "Palindrome.h"
#include <iostream>
using namespace std;

bool ShouldRunAgain();

int main()
{
	do
	{
		SimpleApp* app = new Palindrome();
		app->Run();
		delete app;
	} while (ShouldRunAgain());

	return 0;
}

bool ShouldRunAgain()
{
	cout << "Press 1 to run again, or any other key to exit." << endl;
	int key = 0;
	cin >> key;
	return (key == 1);
}