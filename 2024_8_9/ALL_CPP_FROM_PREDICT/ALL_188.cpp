 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD2 1/4 ", "[math][CurveCalculation][P1][EllipseD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 2.0;
	Vector2 vector2 = CurveCalculation::EllipseD2(0.0, defaultFrame2, major, minor);
	CHECK(vector2.X() == 3.0);
	CHECK(vector2.Y() == 0.0);
}