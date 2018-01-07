// Assignement1Cplusplus.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include "ppm.h"
#include "Image.h"
#include "FilterLinear.h"
#include "FilterGamma.h"
using namespace imaging;
using namespace std;

string getEnding(string *filename);
string getStarting(string *filename);

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
	string filename = getStarting(&orisma),
		format = getEnding(&orisma);
	Image image;
	bool loaded=image.load(filename, format);	
	if (loaded) {

		cout << image.getWidth() << " " << image.getHeight() << endl;
		
		/*const int size = (const int)(image.getHeight() * image.getWidth());
		for (int i = 0; i < size; i++)
		{
			int w = (i) % (image.getWidth());
			int h = (i) / image.getWidth();
			Color tmp(255, 255, 255);
			Color currentColor;
			currentColor.r = image.getPixel(w, h).r;
			currentColor.g = image.getPixel(w, h).g;
			currentColor.b = image.getPixel(w, h).b;
			image.setPixel(w, h, tmp - currentColor);

		}
		image.save(filename + "_neg", format);*/
		FilterLinear filterLinear;
		filterLinear.setA(2,2,2);
		filterLinear.setC(0,0,0);
		image = (filterLinear << image);
		image.save(filename + "_linear", format);
		/*FilterGamma filterGammma;
		filterGammma.setY()*/
	}
	system("PAUSE");
    return 0;
}

string getEnding(string *filename) {
	char dot ='.';
	char * currentstr = (char*)filename->c_str();
	for (int i = 0; i < filename->length(); i++) {
		
		if (currentstr[i]==dot) {
			return filename->substr(i + 1, filename->length());
		}
	}
	return "";
}
string getStarting(string *filename) {
	char dot = '.';
	char * currentstr = (char*)filename->c_str();
	for (int i = 0; i < filename->length(); i++) {

		if (currentstr[i] == dot) {
			return filename->substr(0, i);
		}
	}
	return "";
}