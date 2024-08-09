 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD3 1/4 ", "[math][CurveCalcation][P1][ConeD3]") {
	Frame3 frame;
	double radius = 2.0;
	double angle = M_PI / 4;
	Point3 point(frame.Location().X(), frame.Location().Y() + frame.Location().Z());
	AMCAX::Cone cone(frame, radius, angle);
	auto [du3, d2u2v, d2uv2, d2v3] = AMCAX::CurveCalculation::ConeD3(0.0, 0.0, cone);
	CHECK(du3 == Approx(0));
	CHECK(d2u2v == Approx(0));
	CHECK(d2uv2 == Approx(-2));
	CHECK(d2v3 == Approx(0));
}