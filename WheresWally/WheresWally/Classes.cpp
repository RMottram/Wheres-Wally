#include <iostream>
#include <string>
#include <fstream>
#include "Classes.h"
#include "ReadWriteFunctions.h"
#include "Windows.h"

using namespace std;

// BASE IMAGE CONSTRUCTOR DEFINITIONS

// BASE IMAGE DEFAULT CONSTRUCTOR
BaseImage::BaseImage()
{
	//cout << "Default BaseImage constructor" << endl;
}

// PARAMETERISED CONSTRUCTOR FOR BASE IMAGE
BaseImage::BaseImage(int width, int height, double *pixelData)
{

	// SET COLS AND WIDTH VALUES FROM THE WIDTH AND HEIGHT ARGS
	this->cols = width;
	this->rows = height;

	// INTIALISE PIXELDATA ARRAY
	this->pixelData = new double*[width];

	for (int i = 0; i < width; i++)
	{
		this->pixelData[i] = new double[height];
	}

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			this->pixelData[x][y] = pixelData[(x * height) + y];
		}
	}

}

// CREATE SINGLE DIMENSION ARRAY TO BE USED WITH READ_TEXT / WRITE_PGM FUNCTIONS
double* BaseImage::singleArray()
{
	double* tempArray = new double[this->rows * this->cols];
	
	for (int x = 0; x < cols; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			tempArray[(x * rows) + y] = this->pixelData[x][y];
		}
	}
	return tempArray;
}

// BASE IMAGE DESTRUCTOR
BaseImage::~BaseImage()
{
	//cout << "BaseImage destructor" << endl;
}


// REFERENCE IMAGE CONSTRUCTOR DEFINITIONS

// DEFAULT CONSTRUCTOR
RefImage::RefImage()
{
	//cout << "RefImage constructor" << endl;
}

// PARAMETERISED CONSTRUCTOR INHERITED FROM BASEIMAGE
RefImage::RefImage(int width, int height, double *pixelData):BaseImage(width,height,pixelData)
{
	matrixMessage();
}

void RefImage::matrixMessage()
{
	cout << "Creating Wally matrix..." << endl;
}

//REFIMG DESTRUCTOR
RefImage::~RefImage()
{
	//cout << "RefImage destructor" << endl;
}

// LARGE IMAGE CONSTRUCTOR DEFINITIONS

// DEFAULT CONSTRUCTOR
LargeImage::LargeImage()
{
	//cout << "LargeImage constructor" << endl;
}

// LARGE IMAGE DESTRUCTOR
LargeImage::~LargeImage()
{
	//cout << "LargeImage destructor" << endl;
}

// PARAMETERISED CONSTRUCTOR INHERITED FROM BASEIMAGE
LargeImage::LargeImage(int width, int height, double *pixelData):BaseImage(width, height, pixelData)
{
	matrixMessage();
}

void LargeImage::matrixMessage()
{
	cout << "Creating scene matrix..." << endl << endl;
}

// THIS FUNCTION SHADES IN THE AREA WHERE WALLY IS IN THE CLUTTERED SCENE IMAGE
void LargeImage::shadeWally(int x, int y)
{
	for (int i = x; i < x + 49; i++)
	{
		for (int j = y; j < y + 36; j++)
		{
			// GETS THE VALUES OF THE PIXEL DATA AND HALVES THEM TO GET A DARKER SHADE
			pixelData[i][j] /= 2;
		}
	}
}
