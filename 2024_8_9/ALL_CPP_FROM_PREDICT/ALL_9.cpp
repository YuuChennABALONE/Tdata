 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD3 1/4 ", "[math][CurveCalculation][P1][TorusD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 2.0;
	double minorRadius = 1.0;
	auto calc = AMCAX::CurveCalculation::TorusD3(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	double du3 = std::get<0>(calc);
	double du2v = std::get<1>(calc);
	double duv2 = std::get<2>(calc);
	double dv3 = std::get<3>(calc);
	SECTION("du3") {
		CHECK(du3 == 12.0 / 25.0);
	}}