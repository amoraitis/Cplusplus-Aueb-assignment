// Assignement1Cplusplus.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include "ppm.h"
#include "Image.h"
using namespace imaging;
using namespace std;

string getEnding(string *filename);

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
	bool loaded=image->load(orisma, getEnding(&orisma));
	//TODO: change pixels and save
	if(loaded) cout << image->getWidth() <<" "<< image->getHeight() << endl;
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