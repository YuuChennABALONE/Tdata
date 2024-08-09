 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD1 1/4 ", "[math][CurveCalculation][P1][ParabolaD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double focal = 2.0;
	Point3 p;
	Vector3 v;
	SECTION("u =0") {
		CurveCalculation::ParabolaD1(0.0, defaultFrame3, focal, p, v);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(v.X() == Approx(0.0));
		CHECK(v.Y() == Approx(2.0));
		CHECK(v.Z() == Approx(0.0));
	}}