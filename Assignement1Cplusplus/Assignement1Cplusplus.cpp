// Assignement1Cplusplus.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include "ppm.h"
#include "Image.h"
using namespace imaging;
using namespace std;

int main(int argc, char* argv[])
{

	string orisma;
	if (argc <= 1) {
		std::cout << "File name of the image to load: " << endl;
		getline(cin, orisma);
	}
	else {
		orisma = argv[1];
	}
	Image * image;
	image = new Image();
	image->load()
	int  x=0,  y=0;
	const float *data = ReadPPM("Image01.ppm", &x, &y);
	bool done = WritePPM(data, x, y, "Image01-new.ppm");
	if (done)cout << "File wrote successful?????";
	cout << x<<" "<< y << endl;
	system("PAUSE");
    return 0;
}

