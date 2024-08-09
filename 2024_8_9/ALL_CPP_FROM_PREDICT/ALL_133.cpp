 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleTo3d 1/2 ", "[math][CurveCalculation][P1][CircleTo3d]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	Line2 line2(defaultFrame2);
	SECTION("To3d") {
		Line3 line3 = AMCAX::CurveCalculation::CircleTo3d(line2, 0.0);
		CHECK(line3.Location().IsEqual(line3.Location(), 1e-6));
	}}