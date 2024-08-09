 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double u = 0.0, v = 0.0;
	SECTION("cone 2/1") {
		Cone cone(defaultFrame3, 3.0, 2.0);
		auto [u1, v1] = AMCAX::CurveCalculation::Parameter(cone, Point3(3.0, 0.0, 0.0));
		CHECK(u1 == 0.0);
		CHECK(v1 == Approx(0.0).margin(1e-14));
	}}