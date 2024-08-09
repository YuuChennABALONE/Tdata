 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD2 1/4 ", "[math][CurveCalculation][P1][CylinderD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double u = 0.0; 
	double v = 0.0; 
	std::tuple<double, double, double> expectedDu2 = Approx(12.0 / 3.0);
	std::tuple<double, double, double> expectedDv2 = Approx(4.0 / 3.0);
	std::tuple<double, double, double> expectedDuv = Approx(-4.0 / 3.0);
	auto result = AMCAX::CurveCalculation::CylinderD2(u, v, defaultFrame3, radius);
	CHECK(std::get<0>(result) == std::get<0>(expectedDu2));
	CHECK(std::get<1>(result) == std::get<1>(expectedDv2));
	CHECK(std::get<2>(result) == std::get<2>(expectedDuv));
}