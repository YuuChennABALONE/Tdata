 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD3 1/4 ", "[math][CurveCalculation][P1][EllipseD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 1.0;
	Vector3  vector3 = CurveCalculation::EllipseD3(0.0, defaultFrame3, major, minor);
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 1.0);
	CHECK(vector3.Z() == 0.0);
}