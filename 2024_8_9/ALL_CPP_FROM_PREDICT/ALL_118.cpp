 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::GetCurveLength() ", "[math][CurveCalculation][P1]") {
	Axis3 axis;
	double radius = 5.0;
	Frame3 frame(axis);
	Direction3 initialDirection(0.0, 0.0, 1.0);
	Frame3 frame;
	double length = CurveCalculation::GetCurveLength(frame, 0.0, 1.0, initialDirection);
	double approx = 20.94395102;
	CHECK(length == approx);
}