 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD2 1/4 ", "[math][CurveCalculation][P1][ParabolaD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double focal = 2.0;
	Point2 p;
	Vector2 v1, v2;
	SECTION("u =0") {
		CurveCalculation::ParabolaD2(0.0, defaultFrame2, focal, p, v1,v2);
		CHECK(p.X() == 2.0);
		CHECK(p.Y() == 0.0);
		CHECK(v1.X() == Approx(0.0));
		CHECK(v1.Y() == Approx(2.0));
		CHECK(v2.X() == Approx(-2.0));
		CHECK(v2.Y() == Approx(0.0));
	}}