#include "FilterLinear.h"
using namespace math;

namespace imaging {
	FilterLinear::FilterLinear()
	{
		
	}


	FilterLinear::~FilterLinear()
	{
	}
	Image FilterLinear::operator<<(const Image & image)
	{
		Image result = image;
		const int size = (const int)(result.getHeight() * result.getWidth());
		for (int i = 0; i < size; i++) {
			int w = (i) % (result.getWidth());
			int h = (i) / result.getWidth();
			Color currentColor = result.getPixel(w,h);
			currentColor *= getA();
			currentColor += getC();
			currentColor=currentColor.clampToLowerBound(0);
			currentColor=currentColor.clampToUpperBound(255);
			result.setPixel(w,h,currentColor);
		}
		return result;
	}
}