// Assignement1Cplusplus.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "ppm.h"
using namespace imaging;

int main()
{
	int * x=0, * y=0;
	ReadPPM("Image06.ppm", x, y);
	system("PAUSE");
    return 0;
}

