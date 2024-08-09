 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaDN 1/2 ", "[math][CurveCalculation][P1][ParabolaDN]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double focal = 2.0;
	SECTION("n is 1") {
		Vector2 vector2 = CurveCalculation::ParabolaDN(0.0, defaultFrame2, focal, 1);
		std::cout << vector2.X() << " " << vector2.Y() << " " << std::endl;
		CHECK(vector2.X() == -0.5);
		CHECK(vector2.Y() == Approx(0.0).margin(1e-14));
	}}