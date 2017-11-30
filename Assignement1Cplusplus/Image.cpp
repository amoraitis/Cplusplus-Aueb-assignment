#include "Image.h"
#include "ppm.h"
using namespace imaging;
namespace imaging {

	Color * imaging::Image::getRawDataPtr()
	{
		return *&buffer;
	}

	Color imaging::Image::getPixel(unsigned int x, unsigned int y) const
	{
		if (!(x >= 0 && x < width && y>0 && y <= height))return Color();
		return buffer[(y-1)*width+x];
	}

	void imaging::Image::setPixel(unsigned int x, unsigned int y, Color & value)
	{
		if (!(x >= 0 && x < width && y>0 && y <= height))return;
		buffer[(y - 1)*width + x] = value;
	}
	//TODO: the BIG mistake
	void imaging::Image::setData(const Color *& data_ptr)
	{		
		for (int i=0; i < width*height; i++) {
			buffer[i] = data_ptr[i];
		}
	}

	Image::Image()
	{
		buffer = nullptr;
		width = height = 0;
	}

	Image::Image(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
		buffer = nullptr;
		
	}

	imaging::Image::Image(unsigned int width, unsigned int height, const Color * data_ptr)
	{
		this->width = width;
		this->height = height;
		setData(data_ptr);
	}

	imaging::Image::Image(const Image & src)
	{
		setData((src.getRawDataPtr));
		this->width = src.getWidth();
		this->height = src.getHeight();
	}

	imaging::Image::~Image()
	{
	}

	Image & imaging::Image::operator=(const Image & right)
	{
		const Color * tmpBuffer = right.buffer;		
		return Image(right.getWidth(), right.getHeight(),tmpBuffer);
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