#include "Image.h"
#include "ppm.h"
using namespace imaging;
namespace imaging {

	//DONE
	Color * imaging::Image::getRawDataPtr()
	{
		return buffer;
	}

	//DONE
	Color imaging::Image::getPixel(unsigned int x, unsigned int y) const
	{
		if (!(x >= 0 && x < width && y>=0 && y < height))return Color();
		int position =  y*width + x;
		Color tmp = buffer[position];
		return tmp;
	}

	//Done
	void imaging::Image::setPixel(unsigned int x, unsigned int y, Color & value)
	{
		if (!(x >= 0 && x < width && y>=0 && y < height))return;
		int position = y*width + x;
		buffer[position]= value;
	}

	//Done
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

	//DONE
	Image::Image(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
		buffer = new Color[width*height];
		
	}

	//Done
	imaging::Image::Image(unsigned int width, unsigned int height, const Color * data_ptr)
	{
		this->width = width;
		this->height = height;
		buffer = new Color[width*height];
		setData(data_ptr);
	}

	//DONE
	imaging::Image::Image(const Image & src)
	{
		width = src.getWidth();
		height = src.getHeight();
		buffer = src.buffer;
	}

	//Done
	imaging::Image::~Image()
	{
		//delete buffer;
	}
#pragma endregion

	//DONE
	imaging::Image & imaging::Image::operator=(const Image & right)
	{
		width = right.getWidth();
		height = right.getHeight();
		int size = width*height;		
		buffer = new Vec3<float>[size];
		for (int i = 0; i < size; i++) {
			buffer[i] = Color(right.buffer[i]);
		}
		return *this;
	}

	//Done
	bool imaging::Image::load(const std::string & filename, const std::string & format)
	{
		if (format != "ppm")return false;
		int w = width;
		int h = height;
		
				
		std::string file = filename+"."+format;
		float * image = ReadPPM(file.c_str(), &w, &h);
		buffer = new Color[w*h];
		int multiply = w*h;
		Color tmp;
		for (int i = 0; i <multiply*3; i += 3) {
			(tmp).r = image[i];
			(tmp).g = image[i + 1];
			(tmp).b = image[i + 2];
			//setPixel( i/3/w, i/3%w,* tmp);
			buffer[i/3] = tmp;
		}
		
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
		
		return true;
	}
}