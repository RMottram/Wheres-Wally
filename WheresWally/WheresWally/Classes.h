#pragma once
#include <iostream>
#include <fstream>

using namespace std;

// BASE CLASS WHERE FUNCTIONS AND VARIABLES WILL BE INITIALISED
// OTHER CLASSES WILL INHERIT THE VALUES AND FUNCTIONS
class BaseImage
{
public:
	int rows;
	int cols;
	double** pixelData;

	BaseImage();
	BaseImage(const int width, const int height, double *pixelData);
	double* singleArray();
	virtual void matrixMessage() = 0;
	~BaseImage();
};

// WALLY IMAGE CLASS
class RefImage : public BaseImage
{
public:
	RefImage();
	RefImage(int width, int height, double *pixelData);
	virtual void matrixMessage();
	~RefImage();
};

// CLUTTERED SCENE IMAGE CLASS
class LargeImage : public BaseImage
{
public:
	LargeImage();
	LargeImage(int width, int height, double *pixelData);
	virtual void matrixMessage();
	void shadeWally(int x, int y);
	~LargeImage();
};