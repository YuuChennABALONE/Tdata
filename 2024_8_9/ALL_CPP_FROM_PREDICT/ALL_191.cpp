 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD1 1/4 ", "[math][CurveCalculation][P1][EllipseD1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 2.0;
	Point2 p;
	Vector2 v;
	SECTION("u =0") {
		CurveCalculation::EllipseD1(0.0, defaultFrame2, major, minor, p, v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 0.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
	}}