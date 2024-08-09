 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD2 1/4 ", "[math][CurveCalculation][P1][EllipseD2]") {
	Direction2 defaultDirection(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(0.0, 0.0), defaultDirection);
	double major = 3.0;
	double minor = 2.0;
	Vector2 tangentAt0, tangentAt90, tangentAt180, tangentAt270;
	SECTION("u =0") {
		AMCAX::CurveCalculation::EllipseD2(0.0, defaultFrame2, major, minor, tangentAt0, tangentAt90, tangentAt180, tangentAt270);
		CHECK(tangentAt0.X() == 0.0);
		CHECK(tangentAt0.Y() == 3.0);
		CHECK(tangentAt90.X() == Approx(0.0).margin(1e-14));
		CHECK(tangentAt90.Y() == Approx(-2.0).margin(1e-14));
		CHECK(tangentAt180.X() == Approx(-3.0).margin(1e-14));
		CHECK(tangentAt180.Y() == Approx(0.0).margin(1e-14));
		CHECK(tangentAt270.X() == Approx(-2.0).margin(1e-14));
		CHECK(tangentAt270.Y() == Approx(0.0).margin(1e-14));
	}}