 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD1 1/4 ", "[math][CurveCalculation][P1][CylinderD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	Point3 p;
	Vector3 vecu, vecv;
	SECTION("v is 0") {
		AMCAX::CurveCalculation::CylinderD1(0.0, 0.0, defaultFrame3, radius, p, vecu, vecv);
		CHECK(p.X() == 3.0);
		CHECK(p.Y() == 1.0);
		CHECK(p.Z() == 0.0);
		CHECK(vecu.X() == Approx(0.0));
		CHECK(vecu.Y() == Approx(2.0));
		CHECK(vecu.Z() == Approx(0.0));
		CHECK(vecv.X() == Approx(0.0));
		CHECK(vecv.Y() == Approx(-2.0));
		CHECK(vecv.Z() == Approx(0.0));
	}}