/*
*
* THIS FUNCTION GOES THROUGH THE PROCESS OF COMPARING THE PIXEL DATA VALUES OF WALLY TO THE CLUTTERED SCENE IMAGE PIXEL DATA
* SUM OF SQUARED DIFFERENCE IS USED TO CALCULATE THE SIMILARITIES OF WALLY AND SCENE PIXEL DATA
*
*/

#include "TemplateMatching.h"
#include "LoadingBar.h"
#include "Windows.h"
#include "WallyFacts.h"

using namespace std;

double TemplateMatch(LargeImage scene, RefImage wally)
{
	// SET INITIAL SIMILARITY SCORE TO HIGH VALUE
	// AS THE LOWER THE SUMSQRDIFF VALUE IS, THE MORE CHANCES IT BEING WALLY
	double similarity = 10000000;
	double sumSqrDiff = 0;
	int wallyX = 0, wallyY = 0;

	cout << "Finding all the possible Wally's and calculating the similarity scores..." << endl;
	cout << "This will take approximately 20 seconds..." << endl << endl;
	cout << "In the mean time heres some Where's Wally Facts!" << endl << endl;
	Sleep(1000);
	wallyFacts();

	for (int x = 0; x < scene.cols - wally.cols; x++) // X AXIS OF SCENE AND WALLY
	{
		for (int y = 0; y < scene.rows - wally.rows; y++) // Y AXIS OF SCENE AND WALLY
		{

			sumSqrDiff = 0;

			for (int i = 0; i < wally.cols; i++)
			{
				for (int j = 0; j < wally.rows; j++)
				{
					// TO FIND THE VERY CLOSEST MATCH OF WALLY, IGNORE WHITE PIXELS
					if (wally.pixelData[i][j] != 255)
					{
						// X + U & Y + V SOLVES THE OUT OF BOUNDS EXCEPTION WHEN LOOKING FOR WALLY
						sumSqrDiff += pow((scene.pixelData[x + i][y + j] - wally.pixelData[i][j]), 2);
					}						
				}
			}
			if (sumSqrDiff < similarity)
			{
				similarity = sumSqrDiff;
				wallyX = x;
				wallyY = y;

				// OUTPUTS THE POSSIBLE POSITIONS OF WALLY DOESNT NEED TO BE OUTPUTTED
				//cout << wallyX << " : " << wallyY << endl;
			}
		}
	}

	cout << endl << "Similarity score calculated!" << endl;

	// CALL THE FUNCTION TO SHADE OUT WALLY IN THE CLUTTERED SCENE IMAGE
	// AFTER FINDING IT USING SUMSQRDIFF
	scene.shadeWally(wallyX, wallyY);

	cout << endl << "Wally found! Written to image file named \"wally_found.pgm\"" << endl;
	cout << "The similarity score is: " << similarity << endl;
	cout << endl << "Program finished, have a nice day!" << endl;
	cout << endl << "PROGRAM WILL CLOSE AUTOMATICALLY" << endl;

	return similarity;
	
}
