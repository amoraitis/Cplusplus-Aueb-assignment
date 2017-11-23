#include "ppm.h"
// ppm.cpp : Defines the entry point for the console application.
//
#include <exception>
#include <string>
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

		//read "P*"
		char temp[3];
			mystream.get(temp, 3);
		if (_strcmpi(temp, "P6")!=0) {
			return 0;
		}
		//read space or \n
		char newSpaceLine = mystream.get();
		//init
		const int intSize = 64;
		char buf[intSize];
		//read width
		mystream.get(buf, intSize);
		sscanf_s(buf, "%d", w);
		//read space or \n
		newSpaceLine = mystream.get();
		//read height
		mystream.get(buf, intSize);
		sscanf_s(buf, "%d", h);
		//read space or \n
		newSpaceLine = mystream.get();
		//read pixel format
		int p=-1;
		mystream.get(buf, intSize);
		sscanf_s(buf, "%d", &p);
		if (p > 255)return 0;
		//read space or \n		
		newSpaceLine = mystream.get();
		const int multiply = (*w)*(*h)*3;
		float * result = new float[multiply];
		for (int i = 0; i <multiply; i+=3) {
			for (int j = i; j < i + 3; j++) {
				result[j]= mystream.get();
			}
		}		
	if (mystream.is_open()) {
		mystream.close();
	}
	return result;
	delete result;
}

bool imaging::WritePPM(const float * data, int w, int h, const char * filename)
{
	
	if (data == nullptr)return false;
	ofstream out;
	try
	{
		out.open(filename, ios::trunc | ios::binary | ios::out);
	}
	catch (const std::exception&)
	{
		cout << "We can not open and write to the file!!!";
	}

	string strtowrite = "P6 " + to_string(w) + ' ' + to_string(h) + ' ' + to_string(255)+'\n';
	out << strtowrite;
	strtowrite = "";
	int datasize = w * h; 
	for (int i = 0; i < datasize; i++) {
		strtowrite = to_string(data[i]);
		for (int j = 0; j < strtowrite.length(); j++)
		{
			char x = strtowrite.at(j);
			out << int(x);
		}
	}	
	
	//const char *strchar = strtowrite.c_str();
	
	out.flush();
	if (out.is_open())out.close();

	return true;
}

