 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD3 1/4 ", "[math][CurveCalculation][P1][CylinderD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	AMCAX::Cylinder3 cylinder3(defaultFrame3, radius);
	auto result = AMCAX::CurveCalculation::CylinderD3(0.0, 0.0, cylinder3);
	double du3 = std::approx(result.first, 1e-6, 0.0);
	double dv3 = std::approx(result.second, 1e-6, 0.0);
	double duv2 = result.third;
	CHECK(du3 == 0);
	CHECK(dv3 == 0);
	CHECK(duv2 == 2.0);
}