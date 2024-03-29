#include "ppm.h"
// ppm.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include <bitset>
#include <sstream>
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
		std::cout << "We can not open the file!!!";
	}

	int p = -1;
	sscanf_s("-1","%d", w);
	sscanf_s("-1", "%d", h);
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
		//sscanf_s(buf, "%d", w);
		string tmp="";
		int counter = 0, i = 0;
		while (*w == -1 || *h == -1 || p == -1) {

			if (buf[i] == '\0') {
				if (counter == 0) {
					istringstream(tmp) >> *w;
				}
				else if (counter == 1) {
					istringstream(tmp) >> *h;
				}
				else if (counter == 2) {
					istringstream(tmp) >> p;
				}
				break;
			}
			else if (buf[i]==' ') {
				counter++;
				if (counter == 1) {
					istringstream(tmp) >> *w;
					tmp = "";
				}
				else if (counter == 2) {
					istringstream(tmp) >> *h;
					tmp = "";
				}
			}			
			else {
				tmp += buf[i];
			}
			
			i++;
		}
		//read space or \n
		newSpaceLine = mystream.get();
		if (*h == -1) {
			//read height
			mystream.get(buf, intSize);
			sscanf_s(buf, "%d", h);
			//read space or \n
			newSpaceLine = mystream.get();
		}
		if (p == -1) {
			//read pixel format
			mystream.get(buf, intSize);
			sscanf_s(buf, "%d", &p);
			//read space or \n		
			newSpaceLine = mystream.get();
		}		
		if (p > 255)return nullptr;		
		const int multiply = (*w)*(*h)*3;
		float * result = new float[multiply];
		for (int i = 0; i <multiply; i+=3) {
			for (int j = i; j < i + 3; j++) {
				
				result[j] = mystream.get();
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

	const int size = w * h*3;
	for (int i = 0; i < size; i++) {
		float curent_comp = data[i];
		//cout << to_string(data[i])<<endl;
		out.put((unsigned char)curent_comp);
		
	}
	
	out.flush();
	if (out.is_open())out.close();
	return true;
}

 