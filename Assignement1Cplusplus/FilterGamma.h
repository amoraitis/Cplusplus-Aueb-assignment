#pragma once
#include "Filter.h"
namespace imaging {
	class FilterGamma : public Filter
	{
	private:
		Vec3<float> y;
		bool checkBounds(float a) {
			return a >= 0.5 && a <= 2;
		}
	public:
		Vec3<float> getY() {
			return y;
		}
		bool setY(float x, float y, float z) {
			if (checkBounds(x) && checkBounds(y) && checkBounds(z)) {
				this->y = Vec3<float>(x,y,z);
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