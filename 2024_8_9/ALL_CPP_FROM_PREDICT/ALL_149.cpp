 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD2 1/4 ", "[math][CurveCalculation][P1][HyperbolaD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	Vector3 vector3 = AMCAX::CurveCalculation::HyperbolaD2(0.0, defaultFrame3, major, minor);
	Vector3 vector31 = AMCAX::CurveCalculation::HyperbolaD2(1.0, defaultFrame3, major, minor);
	Vector3 vector32 = AMCAX::CurveCalculation::HyperbolaD2(2.0, defaultFrame3, major, minor);
	CHECK(vector3.X() == 2.0);
	CHECK(vector3.Y() == -3.0);
	CHECK(vector3.Z() == Approx(0.0).margin(1e-14));
	CHECK(vector31.X() == Approx(-1.33333).margin(1e-14));
	CHECK(vector31.Y() == 0.0);
	CHECK(vector31.Z() == Approx(1.0).margin(1e-14));
	CHECK(vector32.X() == Approx(-0.66666).margin(1e-14));
	CHECK(vector32.Y() == -1.0);
	CHECK(vector32.Z() == Approx(1.0).margin(1e-14));
}