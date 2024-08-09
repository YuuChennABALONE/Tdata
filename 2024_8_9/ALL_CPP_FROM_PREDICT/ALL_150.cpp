 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaD2 1/4 ", "[math][CurveCalculation][P1][HyperbolaD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 3.0;
	double minor = 4.0;
	Vector3 vector3 = CurveCalculation::HyperbolaD2(0.0, defaultFrame3, major, minor);
	Vector3 vector31 = CurveCalculation::HyperbolaD2(M_PI_2, defaultFrame3, major, minor);
	Vector3 vector32 = CurveCalculation::HyperbolaD2(3 * M_PI_2, defaultFrame3, major, minor);
	Vector3 vector33 = CurveCalculation::HyperbolaD2(2 * M_PI, defaultFrame3, major, minor);
	CHECK(vector3.X() == 3.0);
	CHECK(vector3.Y() == -4.0);
	CHECK(vector3.Z() == 0.0);
	CHECK(vector31.X() == Approx(3.0).margin(1e-14));
	CHECK(vector31.Y() == Approx(-4.0).margin(1e-14));
	CHECK(vector31.Z() == 0.0);
	CHECK(vector32.X() == Approx(3.0).margin(1e-14));
	CHECK(vector32.Y() == Approx(4.0).margin(1e-14));
	CHECK(vector32.Z() == 0.0);
	CHECK(vector33.X() == 3.0);
	CHECK(vector33.Y() == 4.0);
	CHECK(vector33.Z() == 0.0);
}