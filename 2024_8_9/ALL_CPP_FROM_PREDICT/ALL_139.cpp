 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaParameter() [1/2] ", "[math][CurveCalculation][P1][HyperbolaParameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 4.0;
	double parameter = AMCAX::CurveCalculation::HyperbolaParameter(defaultFrame2, major, minor, Point2(2.0, 3.0)); 
	CHECK(parameter == M_PI_2);
}