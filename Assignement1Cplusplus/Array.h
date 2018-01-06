
#ifndef _ARRAY

#define _ARRAY
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

namespace imaging {

	//template<typename T>;
	template<class T> 
	class Array
	{
	protected:
		vector<T> * buffer;                              //! Holds the image data.

		unsigned int width, 						 //! The width of the image (in pixels)
			height;		                 //! The height of the image (in pixels)
	public:
		
		// metric accessors

		/*! Returns the width of the image
		*/
		const unsigned int getWidth() const { return width; }

		/*! Returns the height of the image
		*/
		const unsigned int getHeight() const { return height; }

		// data accessors

		/*! Obtains a pointer to the internal data.
		*
		*  This is NOT a copy of the internal image data, but rather a pointer
		*  to the internally allocated space, so DO NOT attempt to delete the pointer.
		*/
		T * getRawDataPtr();

		/*! Obtains the color of the image at location (x,y).
		*
		*  The method should do any necessary bounds checking.
		*
		*  \param x is the (zero-based) horizontal index of the pixel to get.
		*  \param y is the (zero-based) vertical index of the pixel to get.
		*
		*  \return The color of the (x,y) pixel as a Color object. Returns a black (0,0,0) color in case of an out-of-bounds x,y pair.
		*/
		T getPixel(unsigned int x, unsigned int y) const;

		// data mutators

		/*! Sets the RGB values for an (x,y) pixel.
		*
		*  The method should perform any necessary bounds checking.
		*
		*  \param x is the (zero-based) horizontal index of the pixel to set.
		*  \param y is the (zero-based) vertical index of the pixel to set.
		*  \param value is the new color for the (x,y) pixel.
		*/
		void setPixel(unsigned int x, unsigned int y, T & value);

		/*! Copies the image data from an external raw buffer to the internal image buffer.
		*
		*  The member function ASSUMES that the input buffer is of a size compatible with the internal storage of the
		*  Image object and that the data buffer has been already allocated. If the image buffer is not allocated or the
		*  width or height of the image are 0, the method should exit immediately.
		*
		*  \param data_ptr is the reference to the preallocated buffer from where to copy the data to the Image object.
		*/
		void setData(const T * & data_ptr);

		// constructors and destructor

		Array() {
			buffer = new vector<T>[0];
			width = height = 0;
		}
		
		/*! Constructor with width and height specification.
		*
		* \param width is the desired width of the new image.
		* \param height is the desired height of the new image.
		*/
		Array(unsigned int width, unsigned int height);

		/*! Constructor with data initialization.
		*
		* \param width is the desired width of the new image.
		* \param height is the desired height of the new image.
		* \param data_ptr is the source of the data to copy to the internal image buffer.
		*
		* \see setData
		*/
		Array(unsigned int width, unsigned int height, const T * data_ptr);

		/*! Copy constructor.
		*
		* \param src is the source image to replicate in this object.
		*/
		Array(const Array<T> &src);

		~Array() {
			delete[] buffer;
		}

		/*! Copy assignment operator.
		*
		*
		* TODO: implement operator
		*
		* \param right is the source image.
		*/
		Array<T> & operator = (const Array<T> & right);

		T & operator () (int i, int j);
	};
}
#endif