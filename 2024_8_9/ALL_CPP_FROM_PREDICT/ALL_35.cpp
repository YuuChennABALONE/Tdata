 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeD2 1/4 ", "[math][CurveCalculation][P1][ConeD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double angle = M_PI_2; 
	std::tuple<double, double, double> result = AMCAX::CurveCalculation::ConeD2(0.0, 0.0, defaultFrame3, radius, angle);
	CHECK(std::get<0>(result) == 2.0);
	CHECK(std::get<1>(result) == -2.0);
	CHECK(std::get<2>(result) == -2.0);
}