 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::LineD1 1/2 ", "[math][CurveCalculation][P1][LineD1]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	Axis2 defaultAxis2(defaultFrame2);
	double u = 0.0;
	Point2 p1(2.0, 1.0);
	Vector2 v1(0.0, 1.0);
	SECTION("LineD1") {
		Vector2 vector2 = CurveCalculation::LineD1(u, defaultAxis2);
		CHECK(vector2.X() == v1.X());
		CHECK(vector2.Y() == v1.Y());
		CHECK(p1.X() == p.X());
		CHECK(p1.Y() == p.Y());
	}}