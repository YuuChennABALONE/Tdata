 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD2 1/4 ", "[math][CurveCalculation][P1][HyperbolaD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 4.0;
	Vector2 vector2 = CurveCalculation::HyperbolaD2(0.0, defaultFrame2, major, minor);
	Vector2 vector3 = CurveCalculation::HyperbolaD2(M_PI_2, defaultFrame2, major, minor);
	Vector2 vector4 = CurveCalculation::HyperbolaD2(M_PI, defaultFrame2, major, minor);
	Vector2 vector5 = CurveCalculation::HyperbolaD2(3 * M_PI_2, defaultFrame2, major, minor);
	Vector2 vector6 = CurveCalculation::HyperbolaD2(2 * M_PI, defaultFrame2, major, minor);
	CHECK(vector2.X() == 0.0);
	CHECK(vector2.Y() == 3.0);
	CHECK(vector3.X() == 3.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector4.X() == -4.0);
	CHECK(vector4.Y() == 0.0);
	CHECK(vector5.X() == -3.0);
	CHECK(vector5.Y() == 0.0);
	CHECK(vector6.X() == 0.0);
	CHECK(vector6.Y() == -3.0);
}