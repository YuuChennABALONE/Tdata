 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleParameter() [1/2] ", "[math][CurveCalculation][P1][CircleParameter]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double u1 = AMCAX::CurveCalculation::CircleParameter(defaultFrame2, Point2(0.0, 1.0)); 
	CHECK(u1 == M_PI_2);
	double u2 = AMCAX::CurveCalculation::CircleParameter(defaultFrame2, Point2(0.0, 0.0));
	CHECK(u2 == 0.0);
}