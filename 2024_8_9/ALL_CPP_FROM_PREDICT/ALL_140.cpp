 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaParameter() [1/2] ", "[math][CurveCalculation][P1][HyperbolaParameter]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	double u = AMCAX::CurveCalculation::HyperbolaParameter(defaultFrame3, major, minor, Point3(6.0, 0.0, 0.0)); 
	CHECK(u == M_PI_2);
}