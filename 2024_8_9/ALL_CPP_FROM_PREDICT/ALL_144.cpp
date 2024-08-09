 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD3 1/4 ", "[math][CurveCalculation][P1][HyperbolaD3]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 4.0;
	Vector2 vector2 = CurveCalculation::HyperbolaD3(0.0, defaultFrame2, major, minor);
	Vector2 vector3 = CurveCalculation::HyperbolaD3(1.0, defaultFrame2, major, minor);
	Vector2 vector4 = CurveCalculation::HyperbolaD3(2.0, defaultFrame2, major, minor);
	Vector2 vector5 = CurveCalculation::HyperbolaD3(3.0, defaultFrame2, major, minor);
	CHECK(vector2.X() == 3.0);
	CHECK(vector2.Y() == 0.0);
	CHECK(vector3.X() == Approx(3.0 / 25.0).margin(1e-14));
	CHECK(vector3.Y() == -48.0 / 25.0);
	CHECK(vector4.X() == Approx(-3.0 / 5.0).margin(1e-14));
	CHECK(vector4.Y() == 24.0 / 5.0);
	CHECK(vector5.X() == -3.0);
	CHECK(vector5.Y() == 0.0);
}