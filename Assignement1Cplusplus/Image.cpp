#include "Image.h"
#include "ppm.h"
using namespace imaging;
namespace imaging {

	//TODO: check for errors
	Color * imaging::Image::getRawDataPtr()
	{
		return buffer;
	}

	//TODO: check for errors
	Color imaging::Image::getPixel(unsigned int x, unsigned int y) const
	{
		if (!(x >= 0 && x < width && y>=0 && y < height))return Color();
		int position =  y*width + x;
		Color tmp = buffer[position];
		return tmp;
	}

	//TODO: check for errors
	void imaging::Image::setPixel(unsigned int x, unsigned int y, Color & value)
	{
		if (!(x >= 0 && x < width && y>=0 && y < height))return;
		int position = y*width + x;
		buffer[position]= value;
	}

	//TODO: the BIG mistake
	void imaging::Image::setData(const Color *& data_ptr)
	{		
		for (int i=0; i < width*height; i++) {
			buffer[i] = data_ptr[i];
		}
	}
#pragma region Constructors
	//Done
	Image::Image()
	{
		buffer = nullptr;
		width = height = 0;
	}

	//TODO: check for errors
	Image::Image(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
		buffer = nullptr;
		
	}

	//Done
	imaging::Image::Image(unsigned int width, unsigned int height, const Color * data_ptr)
	{
		this->width = width;
		this->height = height;
		setData(data_ptr);
	}

	//Done
	imaging::Image::Image(const Image & src)
	{
		Image* temp = (Image *)&src;
		
		Color *& tmp =(Color *&) (*temp->getRawDataPtr());
		this->setData((const Color *&)tmp);
		this->width = src.getWidth();
		this->height = src.getHeight();
	}

	//Done
	imaging::Image::~Image()
	{
		delete[] buffer;
	}
#pragma endregion

	//TODO: check for errors
	Image & imaging::Image::operator=(const Image & right)
	{//anathesi topikwn metablitwn apo arguments
		return Image(right.getWidth(), right.getHeight(),right.buffer);
	}

	//Done
	bool imaging::Image::load(const std::string & filename, const std::string & format)
	{
		if (format != "ppm")return false;
		int w = width;
		int h = height;
		
				
		std::string file = filename+"."+format;
		float * image = ReadPPM(file.c_str(), &w, &h);
		Color * curentColors = new Color[w*h];
		int multiply = w*h;
		Color tmp;
		for (int i = 0; i <multiply*3; i += 3) {
			(tmp).r = image[i];
			(tmp).g = image[i + 1];
			(tmp).b = image[i + 2];
			//setPixel( i/3/w, i/3%w,* tmp);
			curentColors[i/3] = tmp;
		}
		buffer = curentColors;
		width = (unsigned int) w;
		height = (unsigned int) h;
		delete image;
		return true;
	}

	//TODO: check for errors
	bool imaging::Image::save(const std::string & filename, const std::string & format)
	{
		if (format != "ppm")return false;
		int w = width;
		int h = height;
		const int multiply = w*h*3;		
		std::string file = filename + "." + format;
		float * data = new float[multiply];
		for (int i = 0; i <multiply; i += 3) {
			Color tmp;
			tmp.r = buffer[i/3].r;
			tmp.g = buffer[i/3].g;
			tmp.b = buffer[i / 3].b;

			data[i] = tmp.r;
			data[i + 1] =tmp.g;
			data[i + 2] = tmp.b;
		}
		bool written = WritePPM(data,w,h,file.c_str());
		delete data;
		return true;
	}
}