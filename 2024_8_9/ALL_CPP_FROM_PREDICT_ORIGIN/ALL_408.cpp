 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleDN 1/2 ", "[math][CurveCalculation][P1][CircleDN]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double 	r = 2.0;
	double u = 0.0;
	SECTION("2 derivative vector") {
		Vector2  vector2 = CurveCalculation::CircleDN(u, defaultFrame2, r, 2); 
		std::cout << vector2.X() << " " << vector2.Y() << " " << std::endl;
		CHECK(vector2.X() == -2.0);
		CHECK(vector2.Y() == Approx(0.0).margin(1e-14));
	}}