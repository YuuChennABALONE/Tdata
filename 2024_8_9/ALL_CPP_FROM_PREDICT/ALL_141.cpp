 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaDN 1/2 ", "[math][CurveCalculation][P1][HyperbolaDN]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 1.0), defaultDirection);
	double major = 3.0;
	double minor = 4.0;
	double u = 0.0;
	SECTION("2 derivative vector") {
		Vector2  vector2 = CurveCalculation::HyperbolaDN(u, defaultFrame2, major, minor, 2);
		std::cout << vector2.X() << " " << vector2.Y() << " " << std::endl;
		CHECK(vector2.X() == -3.0);
		CHECK(vector2.Y() == Approx(0.0).margin(1e-14));
	}
}