 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::HyperbolaDN 3/4 ", "[math][CurveCalculation][P1][HyperbolaDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double major = 2.0;
	double minor = 3.0;
	Vector3 vector3 = CurveCalculation::HyperbolaDN(M_PI_2, defaultFrame3, major, minor, 2);
	Vector3 vector31 = CurveCalculation::HyperbolaDN(3 * M_PI_2, defaultFrame3, minor, major, 2);
	Vector3 vector32 = CurveCalculation::HyperbolaDN(2 * M_PI_2, defaultFrame3, major, minor, 2);
	Vector3 vector33 = CurveCalculation::HyperbolaDN(7 * M_PI_2, defaultFrame3, major, minor, 2);
	Vector3 vector34 = CurveCalculation::HyperbolaDN(5 * M_PI_2, defaultFrame3, minor, major, 2);
	CHECK(vector3.X() == Approx(-1.0 / 2.0));
	CHECK(vector3.Y() == Approx(9.0 / 2.0));
	CHECK(vector3.Z() == Approx(0.0));
	CHECK(vector31.X() == Approx(3.0 / 2.0));
	CHECK(vector31.Y() == Approx(-4.0 / 3.0));
	CHECK(vector31.Z() == Approx(0.0));
	CHECK(vector32.X() == Approx(-2.0));
	CHECK(vector32.Y() == Approx(-9.0 / 2.0));
	CHECK(vector32.Z() == Approx(0.0));
	CHECK(vector33.X() == Approx(1.0));
	CHECK(vector33.Y() == Approx(-15.0 / 4.0));
	CHECK(vector33.Z() == Approx(0.0));
	CHECK(vector34.X() == Approx(-3.0 / 2.0));
	CHECK(vector34.Y() == Approx(4.0 / 3.0));
	CHECK(vector34.Z() == Approx(0.0));
}