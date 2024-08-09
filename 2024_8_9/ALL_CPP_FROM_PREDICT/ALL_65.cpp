 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() [1/2] ", "[math][CurveCalculation][P1][Parameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double u = 0.0;
	double v = 0.0;
	double w = 0.0;
	SECTION("Parameter sphere2") {
		Sphere sphere2(defaultFrame3, 2.0);
		auto param = CurveCalculation::Parameter(sphere2, Point3(2.0, 2.0, 0.0));
		CHECK(param.first == M_PI_2);
		CHECK(param.second == Approx(0.0));
	}}