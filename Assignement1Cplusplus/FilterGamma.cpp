#include "FilterGamma.h"

namespace  imaging {
	FilterGamma::FilterGamma()
	{
	}


	FilterGamma::~FilterGamma()
	{
	}
	Image FilterGamma::operator<<(const Image & image)
	{
		Image result = image;
		const int size = (const int)(result.getHeight() * result.getWidth());
		for (int i = 0; i < size; i++) {
			int w = (i) % (result.getWidth());
			int h = (i) / result.getWidth();
			Color currentColor;
			currentColor.r = pow(result.getPixel(w, h).r, getY());
			currentColor.g = pow(result.getPixel(w, h).g, getY());
			currentColor.b = pow(result.getPixel(w, h).b, getY());
			currentColor = currentColor.clampToLowerBound(0);
			currentColor = currentColor.clampToUpperBound(1);
			result.setPixel(w, h, currentColor);
		}
		return result;
	}
}