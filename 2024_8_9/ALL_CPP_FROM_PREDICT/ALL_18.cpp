 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereParameter 1/2 ", "[math][CurveCalculation][P1][SphereParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	SECTION("Test the pair of uv parameters") {
		std::pair<double, double> uv = AMCAX::CurveCalculation::SphereParameter(defaultFrame3, radius, Point3(2.0, 1.0, 0.0)); 
		CHECK(uv.first == M_PI_2);
		CHECK(uv.second == M_PI_2);
	}}