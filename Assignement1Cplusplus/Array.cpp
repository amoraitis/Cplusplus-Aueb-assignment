#include "Array.h"
#include <iostream>

using namespace std;
using namespace imaging;

namespace imaging {

	template<class T>
	T * imaging::Array<T>::getRawDataPtr()
	{
		return nullptr;
	}

	template<class T>
	T imaging::Array<T>::getPixel(unsigned int x, unsigned int y) const
	{
		return T();
	}

	template<class T>
	void imaging::Array<T>::setPixel(unsigned int x, unsigned int y, T & value)
	{
	}

	template<class T>
	void imaging::Array<T>::setData(const T *& data_ptr)
	{
	}

	template<class T>
	Array<T>::Array()
	{
	}

	template<class T>
	imaging::Array<T>::Array(unsigned int width, unsigned int height)
	{
	}

	template<class T>
	imaging::Array<T>::Array(unsigned int width, unsigned int height, const T * data_ptr)
	{
	}

	template<class T>
	imaging::Array<T>::Array(const Array & src)
	{
	}

	template<class T>
	Array<T>::~Array()
	{
	}


	template<class T>
	T & imaging::Array<T>::operator()(int i, int j)
	{
		return nullptr;
	}
}