/*
*
*	CMP2090M OBJECT ORIENTED PROGRAMMING
*	ASSESSMENT 1
*	------------------------------------
*	CREATED 15/11/2018
*	BY RYAN MOTTRAM 16639499
*
*/

#include <iostream>
#include <string>
#include "ReadWriteFunctions.h"
#include "Classes.h"
#include "Windows.h"
#include "TemplateMatching.h"
#include "LoadingBar.h"

// PRE-PROCESSED GLOBAL VARIABLES INCASE NEEDED IN MULTIPLE PARTS OF PROGRAM
#define WALLYHEIGHT 36
#define WALLYWIDTH 49
#define SCENEHEIGHT 768
#define SCENEWIDTH 1024

using namespace std;

int main()
{
	cout << "LOADING PROGRAM" << endl << endl;
	cout << "Please wait while loading files..." << endl << endl;
	LoadingBar();


	// INITIALISE CLUTTERED SCENE ARRAY
	char input[] = "Cluttered_scene.txt";
	char output[] = "wally_found.pgm"; // THIS WILL OUTPUT THE IMAGE WHEN WALLY IS FOUND
	
	// INITIALISE WALLY IMAGE ARRAY
	char wallyInput[] = "Wally_grey.txt";
	char wallyOutput[] = "wally.pgm";
	

	// WALLY IMAGE INSTANCE
	RefImage wally = RefImage(WALLYWIDTH, WALLYHEIGHT, read_text(wallyInput, WALLYHEIGHT, WALLYWIDTH));

	// SCENE IMAGE INSTANCE
	LargeImage clutteredScene = LargeImage(SCENEHEIGHT, SCENEWIDTH, read_text(input, SCENEHEIGHT, SCENEWIDTH));
	TemplateMatch(clutteredScene, wally);

	// CREATE THE WALLY AND CLUTTERED SCENE IMAGES
	write_pgm(output, clutteredScene.singleArray(), SCENEHEIGHT, SCENEWIDTH, 255);
	write_pgm(wallyOutput, wally.singleArray(), WALLYWIDTH, WALLYHEIGHT, 255);

	// AFTER THE PROGRAM HAS WRITTEN THE PMG FILE WITH WALLY HIGHLIGHTED
	// THE PROGRAM WILL PAUSE FOR 6 SECONDS AND QUIT AUTOMATICALLY
	Sleep(6000);
	exit(0);

	cin.get();
	return 0;
}
