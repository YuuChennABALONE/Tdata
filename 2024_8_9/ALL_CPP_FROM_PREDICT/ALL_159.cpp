 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaParameter() [1/2] ", "[math][CurveCalculation][P1][ParabolaParameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double focal = 2.0;
	double parameter = AMCAX::CurveCalculation::ParabolaParameter(defaultFrame2, focal, Point2(0.0, 0.5)); 
	CHECK(parameter == M_PI_2);
}