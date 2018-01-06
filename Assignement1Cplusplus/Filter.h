#pragma once
#include "Image.h"
namespace imaging {
	class Filter
	{
	public:
		Filter() {

		}
		~Filter() {

		}

		Filter(const Filter & f) {

		}
		Image operator << (const Image & image);
	};
}