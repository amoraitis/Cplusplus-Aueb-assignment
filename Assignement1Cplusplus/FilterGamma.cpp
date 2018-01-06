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
			currentColor.r = result.getPixel(w, h).r;
			currentColor.g = result.getPixel(w, h).g;
			currentColor.b = result.getPixel(w, h).b;
		}
		return result;
	}
}