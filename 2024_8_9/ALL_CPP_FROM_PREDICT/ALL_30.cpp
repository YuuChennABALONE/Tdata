 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ConeParameter 1/2 ", "[math][CurveCalculation][P1][ConeParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double angle = M_PI / 4; 
	std::pair<double, double> uv = AMCAX::CurveCalculation::ConeParameter(defaultFrame3, radius, angle, Point3(1.0, 1.0, 0.0)); 
	CHECK(uv.first == 0.0);
	CHECK(uv.second == M_PI_4);
}