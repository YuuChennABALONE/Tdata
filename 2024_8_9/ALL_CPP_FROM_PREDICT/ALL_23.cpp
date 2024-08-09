 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereD2 1/2 ", "[math][CurveCalculation][P1][SphereD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0; 
	std::tuple<double, double, double> result = AMCAX::CurveCalculation::SphereD2(0.0, 0.0, defaultFrame3, radius);
	CHECK(std::get<0>(result) == 12.0);
	CHECK(std::get<1>(result) == 0.0);
	CHECK(std::get<2>(result) == 4.0);
}