#include "WallyFacts.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Windows.h"

using namespace std;

// JUST FOR FUN WHILE THE PROGRAM IS SEARCHING FOR WALLY
void wallyFacts()
{
	vector<string> factsVect;
	vector<string>::iterator factsIt;

	factsVect.push_back("Where's Wally first appeared in 1987 and created by Martin Handford!");
	factsVect.push_back("Each scene is drawn by hand and takes 8 weeks to make!");
	factsVect.push_back("Every scene has 300 - 500 characters!");
	factsVect.push_back("In Early 2018, Google brought Where's Wally to Google Maps for a limited time!");

	for (factsIt = factsVect.begin(); factsIt != factsVect.end(); factsIt++)
	{
		cout << *factsIt << endl;
		Sleep(1000);
	}
}