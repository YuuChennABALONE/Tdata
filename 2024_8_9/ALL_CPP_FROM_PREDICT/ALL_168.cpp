 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD2 1/4 ", "[math][CurveCalculation][P2][ParabolaD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double focal = 2.0;
	SECTION("u =0") {
		Vector2 vector2 = CurveCalculation::ParabolaD2(0.0, defaultFrame2, focal);
		CHECK(vector2.X() == 0.0);
		CHECK(vector2.Y() == -2.0);
	}}