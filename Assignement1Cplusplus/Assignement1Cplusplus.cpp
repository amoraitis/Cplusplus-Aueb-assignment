// Assignement1Cplusplus.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "ppm.h"
using namespace imaging;
using namespace std;

int main()
{
	int  x=0,  y=0;
	const float *data = ReadPPM("Image01.ppm", &x, &y);
	bool done = WritePPM(data, x, y, "Image01-new.ppm");
	if (done)cout << "File wrote successful?????";
	cout << x<<" "<< y << endl;
	system("PAUSE");
    return 0;
}

