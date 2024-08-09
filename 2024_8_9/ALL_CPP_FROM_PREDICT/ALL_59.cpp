 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::PlaneD2 1/2 ", "[math][CurveCalculation][P1][PlaneD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double du2, dv2, dudv;
	std::tuple<double, double, double> result = AMCAX::CurveCalculation::PlaneD2(0.0, 0.0, defaultFrame3);
	SECTION("du2") {
		du2 = std::get<0>(result);
		CHECK(du2 == 0.0);
	}}