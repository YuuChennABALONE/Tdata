 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseValue()[1 / 2] ", "[math][CurveCalculation][P1][EllipseValue]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), defaultDirection);
	double major = 2.0;
	double minor = 1.0; 
	Point2 point2 = AMCAX::CurveCalculation::EllipseValue(0.0, defaultFrame2, major, minor);
	CHECK(point2.X() == 3.0);
	CHECK(point2.Y() == 1.0);
}