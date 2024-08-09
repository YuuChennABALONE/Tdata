 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD2 1/4 ", "[math][CurveCalculation][P1][HyperbolaD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 5.0;
	double minor = 4.0;
	double u = M_PI_2;
	Point2 p;
	Vector2 v1,v2;
	SECTION("major radius 5 minor radius 4 u M_PI_2") {
		CurveCalculation::HyperbolaD2(u, defaultFrame2, major, minor, p, v1,v2);
		CHECK(p.X() == Approx(0.0));
		CHECK(p.Y() == 5.0);
		CHECK(v1.X() == Approx(0.0));
		CHECK(v1.Y() == Approx(-5.0));
		CHECK(v2.X() == Approx(-5.0 / 4).margin(1e-14));
		CHECK(v2.Y() == Approx(0.0).margin(1e-14));
	}}