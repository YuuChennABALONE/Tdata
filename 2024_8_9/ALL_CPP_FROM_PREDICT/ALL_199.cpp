 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::LineParameter() [1/2] ", "[math][CurveCalculation][P1][LineParameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	Axis2 defaultAxis2(defaultFrame2);
	double parameter = AMCAX::CurveCalculation::LineParameter(defaultAxis2, Point2(0.0, 1.0)); 
	CHECK(parameter == M_PI_2);
}