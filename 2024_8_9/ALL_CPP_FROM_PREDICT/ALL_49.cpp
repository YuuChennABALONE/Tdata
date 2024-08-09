 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD1 1/4 ", "[math][CurveCalculation][P1][CylinderD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Cylinder cylinder(defaultFrame3, radius);
	SECTION("u =0 v =0") {
		auto [du, dv] = AMCAX::CurveCalculation::CylinderD1(0.0, 0.0, cylinder.Position(), cylinder.Radius());
		CHECK(du.X() == Approx(-2.0));
		CHECK(du.Y() == Approx(0.0));
		CHECK(du.Z() == Approx(0.0));
		CHECK(dv.X() == Approx(0.0));
		CHECK(dv.Y() == Approx(2.0));
		CHECK(dv.Z() == Approx(0.0));
	}}