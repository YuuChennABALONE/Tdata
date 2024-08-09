 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD1 1/4 ", "[math][CurveCalculation][P1][TorusD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double major = 3.0;
	double minor = 1.0;
	std::vector<double> uv(2, 0.0);
	auto result1 = AMCAX::CurveCalculation::TorusD1(uv[0], uv[1], defaultFrame3, major, minor);
	auto result2 = AMCAX::CurveCalculation::TorusD1(uv[0], uv[1], Point3(1.0, 1.0, 0.0), initialDir, major, minor);
	CHECK(result1[0] == result2[0]);
	CHECK(result1[1] == result2[1]);
}