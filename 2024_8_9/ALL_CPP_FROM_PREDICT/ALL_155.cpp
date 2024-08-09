 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD0 1/4 ", "[math][CurveCalculation][P1][HyperbolaD0]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 4.0;
	Point2 point2 = AMCAX::CurveCalculation::HyperbolaD0(0.0, defaultFrame2, major, minor);
	CHECK(point2.X() == 3.0);
	CHECK(point2.Y() == 0.0);
}