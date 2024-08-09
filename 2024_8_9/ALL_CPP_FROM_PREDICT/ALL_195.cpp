 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD0 1/4 ", "[math][CurveCalculation][P1][EllipseD0]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 5.0;
	double minor = 4.0;
	double u = 0.0;
	double x = CurveCalculation::EllipseD0(u, defaultFrame2, major, minor);
	double y = CurveCalculation::EllipseD0(u, defaultFrame2, minor, major);
	double x2 = major * minor / sqrt(pow(minor, 2) + pow(major, 2) * pow(u, 2));
	double y2 = minor * minor * u / sqrt(pow(minor, 2) + pow(major, 2) * pow(u, 2));
	CHECK(x == x2);
	CHECK(y == y2);
}