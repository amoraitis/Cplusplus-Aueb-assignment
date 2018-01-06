#pragma once
#include "Filter.h"
using namespace math;
namespace imaging {
	class FilterLinear : public Filter
	{
	private:
		Vec3<float> a, c;
		
	public:
		Vec3<float> getA() {
			return a;
		}
		Vec3<float> getC() {
			return c;
		}
		void setA(float x, float y, float z) {
			a = Vec3<float>(x, y, z);
		}
		void setC(float x, float y, float z) {
			c = Vec3<float>(x, y, z);
		}
		FilterLinear();
		~FilterLinear();
		Image operator << (const Image & image);
	};
}