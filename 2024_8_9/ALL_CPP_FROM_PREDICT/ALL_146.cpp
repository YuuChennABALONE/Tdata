 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD3 1/4 ", "[math][CurveCalculation][P1][HyperbolaD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 3.0;
	double minor = 4.0;
	Vector3 vector3 = CurveCalculation::HyperbolaD3(0.0, defaultFrame3, major, minor);
	std::cout << vector3.X() << " " << vector3.Y() << " " << vector3.Z() << " " << std::endl;
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector3.Z() == 0.0);
}