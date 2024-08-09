 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD1 1/4 ", "[math][CurveCalculation][P1][HyperbolaD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	Vector3  vector3 = CurveCalculation::HyperbolaD1(0.0, defaultFrame3, major, minor); 
	double x = major / minor * atan(major / minor * 0.0);
	double y = minor * cos(M_PI_2 * 0.0);
	CHECK(vector3.X() == x);
	CHECK(vector3.Y() == y);
	CHECK(vector3.Z() == 0.0);
}