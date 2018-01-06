#pragma once
#include "Filter.h"
namespace imaging {
	class FilterGamma : public Filter
	{
	float y;

	public:
		float getY() {
			return y;
		}
		bool setY(float y) {
			if (y >= 0.5 && y <= 2.0) {
				this->y = y;
				return true;
			}
			else {
				//std::cout << "Value out of bounds!" << endl;
				return false;//handle out of bounds in main
			}
		}
		FilterGamma();
		~FilterGamma();
		Image operator << (const Image & image);
	};
}