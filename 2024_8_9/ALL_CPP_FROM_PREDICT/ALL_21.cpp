 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereD3 1/4 ", "[math][CurveCalculation][P1][SphereD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0; 
	std::tuple<double, double, double, double>  result = AMCAX::CurveCalculation::SphereD3(0.0, M_PI / 2.0, defaultFrame3, radius);
	CHECK(std::get<0>(result) == 0.0);
	CHECK(std::get<1>(result) == -2.0);
	CHECK(std::get<2>(result) == 0.0);
	CHECK(std::get<3>(result) == 0.0);
}