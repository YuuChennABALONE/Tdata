 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseD2 1/4 ", "[math][CurveCalculation][P1][EllipseD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 3.0;
	double minor = 2.0;
	Vector3  vector3 = AMCAX::CurveCalculation::EllipseD2(0.0, defaultFrame3, major, minor);
	Vector3 vector31 = AMCAX::CurveCalculation::EllipseD2(90.0, defaultFrame3, major, minor);
	Vector3 vector32 = AMCAX::CurveCalculation::EllipseD2(180.0, defaultFrame3, major, minor);
	Vector3 vector33 = AMCAX::CurveCalculation::EllipseD2(270.0, defaultFrame3, major, minor);
	CHECK(vector3.X() == 3.0);
	CHECK(vector3.Y() == 0.0);
	CHECK(vector3.Z() == 0.0);
	CHECK(vector31.X() == -2.0);
	CHECK(vector31.Y() == 0.0);
	CHECK(vector31.Z() == 0.0);
	CHECK(vector32.X() == -3.0);
	CHECK(vector32.Y() == 0.0);
	CHECK(vector32.Z() == 0.0);
	CHECK(vector33.X() == 0.0);
	CHECK(vector33.Y() == -2.0);
	CHECK(vector33.Z() == 0.0);
}