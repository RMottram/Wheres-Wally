#include <iostream>
#include "LoadingBar.h"
#include "Windows.h" // ENABLES THE PROGRAM TO DELAY COMMANDS USING SLEEP() IN MILLISECONDS
#include <cstdlib>

using namespace std;

// JUST MAKES THE PROGRAM SHOW SOMETHING WHILE FILES ARE LOADING
// SO USER KNOWS IT IS RUNNING AND WORKING
void LoadingBar()
{
	char b = 42;
	for (int i = 0; i < 20; i++)
	{
		cout << b;
		Sleep(200);
	}
	cout << endl << endl << "Program loaded succesfully!" << endl;
	Sleep(2000);
	system("CLS");
}