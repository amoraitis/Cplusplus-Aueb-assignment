#include "Array.h"
#include <iostream>

using namespace std;
using namespace imaging;

namespace imaging {

	template<class T>
	T * imaging::Array<T>::getRawDataPtr()
	{
		return buffer;
	}

	template<class T>
	T imaging::Array<T>::getPixel(unsigned int x, unsigned int y) const
	{
		if (!(x >= 0 && x < width && y >= 0 && y < height))return T();
		int position = y * width + x;
		T tmp = buffer[position];
		return tmp;
	}

	template<class T>
	void imaging::Array<T>::setPixel(unsigned int x, unsigned int y, T & value)
	{
		if (!(x >= 0 && x < width && y >= 0 && y < height))return;
		int position = y * width + x;
		buffer[position] = value;
	}

	template<class T>
	void imaging::Array<T>::setData(const T *& data_ptr)
	{
		for (int i = 0; i < width*height; i++) {
			buffer[i] = data_ptr[i];
		}
	}

	template<class T>
	imaging::Array<T>::Array(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
		buffer = new vector<T>[width*height];
	}

	template<class T>
	imaging::Array<T>::Array(unsigned int width, unsigned int height, const T * data_ptr)
	{
		this->width = width;
		this->height = height;
		buffer = new vector<T>[width*height];
		setData(data_ptr);
	}

	template<class T>
	imaging::Array<T>::Array(const Array & src)
	{
		width = src.getWidth();
		height = src.getHeight();
		buffer = src.getRawDataPtr();
	}

	template<class T>
	imaging::Array<T> & imaging::Array<T>::operator = (const imaging::Array<T>& right)
	{
		width = right.getWidth();
		height = right.getHeight();
		buffer = right.getRawDataPtr();
		return *this;
	}

	template<class T>
	T & imaging::Array<T>::operator()(int i, int j)
	{
		if (!(x >= 0 && x < width && y >= 0 && y < height))return T();
		int position = y * width + x;
		T tmp = buffer[position];
		return tmp;
	}
}