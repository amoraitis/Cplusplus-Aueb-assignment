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

	string orisma, filename, format;
	Image image;
	if (argc <= 1) {
		std::cout << "File name of the image to load: " << endl;
		getline(cin, orisma);
	}
	else {

		orisma = argv[1];//-f
		if (_strcmpi(orisma.c_str(), "-f") != 0) {
			cout << "Argument -f is needed!!" << endl;
			system("PAUSE");
			return 0;
		}
		else if (_strcmpi(getEnding(&string(argv[argc - 1])).c_str(), "ppm") != 0){
			cout << "Filname not given!!" << endl;
			system("PAUSE");
			return 0;
		}
		int i = 2;
		filename = getStarting(&string(argv[argc-1]));
		format = getEnding(&string(argv[argc - 1]));
		bool loaded = image.load(filename, format);
		
		if (loaded) {
			cout << image.getWidth() << " " << image.getHeight() << endl;
			while (i < argc - 1) {
				cout << argv[i] << endl;
				if (_strcmpi(argv[i], "gamma") == 0) {
					FilterGamma filterGammma;
					filterGammma.setY(atof(argv[i+1]));
					image = (filterGammma << image);
					i+=2;
				}
				else if (_strcmpi(argv[i], "linear") == 0) {
					FilterLinear filterLinear;
					filterLinear.setA(atof(argv[i+1]),atof(argv[i+2]),atof(argv[i+3]));
					filterLinear.setC(atof(argv[i + 4]), atof(argv[i + 5]), atof(argv[i + 6]));
					image = (filterLinear << image);
					i += 7;
				}
				else {
					cout << "Misspelled filter name!!" << endl;
					system("PAUSE");
					return 0;
				}
			}
			image.save("filterd_"+filename, format);
		}
		else {
			cout << "Couldnt load file!!" << endl;
			system("PAUSE");
			return 0;
		}
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