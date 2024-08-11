 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleD2 1/4 ", "[math][CurveCalculation][P1][CircleD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 2.0;
	double u = 0.0; 
	Vector2  vector2 = CurveCalculation::CircleD2(u, defaultFrame2, r);
	Vector2 vector21 = CurveCalculation::CircleD2(u, defaultFrame2, r, Vector2());
	CHECK(vector2.X() == 2.0);
	CHECK(vector2.Y() == 0.0);
	CHECK(vector21.X() == 2.0);
	CHECK(vector21.Y() == 0.0);
}