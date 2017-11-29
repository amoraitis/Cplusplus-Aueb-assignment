#include "Image.h"
#include "ppm.h"
using namespace imaging;
namespace imaging {

	Color * imaging::Image::getRawDataPtr()
	{
		return nullptr;
	}

	Color imaging::Image::getPixel(unsigned int x, unsigned int y) const
	{
		return Color();
	}

	void imaging::Image::setPixel(unsigned int x, unsigned int y, Color & value)
	{
	}

	void imaging::Image::setData(const Color *& data_ptr)
	{
	}

	Image::Image()
	{
	}

	Image::Image(unsigned int width, unsigned int height)
	{
	}

	imaging::Image::Image(unsigned int width, unsigned int height, const Color * data_ptr)
	{
	}

	imaging::Image::Image(const Image & src)
	{
	}

	imaging::Image::~Image()
	{
	}

	Image & imaging::Image::operator=(const Image & right)
	{
		// TODO: insert return statement here
	}

	bool imaging::Image::load(const std::string & filename, const std::string & format)
	{
		if (format != "ppm")return false;
		int w = (int)width;
		int h = (int)height;
		int multiply = w*h;
		buffer = new Color[w*h];			
		std::string file = filename + "." + format;
		float * image = ReadPPM(file.c_str(), &w, &h);
		for (int i = 0; i <multiply*3; i += 3) {
			Color tmp(image[i], image[i + 1], image[i + 2]);
			buffer[i] = tmp;
		}
		delete image;
		return true;
	}

	bool imaging::Image::save(const std::string & filename, const std::string & format)
	{
		if (format != "ppm")return false;
		int w = (int)width;
		int h = (int)height;
		const int multiply = w*h*3;		
		std::string file = filename + "." + format;
		float * data = new float[multiply];
		for (int i = 0; i <multiply * 3; i += 3) {
			
			data[i] = buffer[i][0];
			data[i + 1] = buffer[i][1];
			data[i + 2] = buffer[i][2];
		}
		bool written = WritePPM(data,w,h,file.c_str());
		delete data;
		return true;
	}
}