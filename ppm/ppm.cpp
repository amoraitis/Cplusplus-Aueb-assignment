#include "ppm.h"
// ppm.cpp : Defines the entry point for the console application.
//
#include <exception>
#include <fstream>
#include <iostream>
using namespace std;

float * imaging::ReadPPM(const char * filename, int * w, int * h)
{
	std::string format;
	std::ifstream mystream;
	try
	{
		mystream.open(filename, ios::binary);
	}
	catch (const std::exception&)
	{
		cout << "We can not open the file!!!";
	}
	//Diabazoume 2 charactires, tous enonoume se string
	//if "p3" throw exc, else while(w,h==0) diabase charaktira
	//diabase charaktira, diabase int(255), diabase pinaka
	const int intSize = 64;
	char buf[intSize];
	mystream.get(buf, intSize);
	if (_strcmpi(buf, "P6")==0) {
		cout << "This is a fie of our own format!"<<endl;
	}
	for (int i = 0; i < 2; i++) {
		char newLine = mystream.get();
		cout << newLine << endl;
		if (newLine == '\n') {
			char buf[intSize];
			mystream.get(buf, intSize);
			cout << "File contains " << buf << " integers\n";
		}
		else if (newLine == ' ') {
			char buf[intSize];
			mystream.get(buf, intSize);
			cout << "File contains " << buf << " integers\n";
		}
	}
	

	if (mystream.is_open()) {
		mystream.close();
	}
	return nullptr;
}

bool imaging::WritePPM(const float * data, int w, int h, const char * filename)
{
	return false;
}
