 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD3 1/4 ", "[math][CurveCalculation][P1][ParabolaD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	Vector3 vector3 = CurveCalculation::ParabolaD3(0.0, defaultFrame3, focal);
	Vector3 vector31 = CurveCalculation::ParabolaD3(1.0 / (2.0 * focal), defaultFrame3, focal);
	Vector3 vector32 = CurveCalculation::ParabolaD3(2.0 / (2.0 * focal), defaultFrame3, focal);
	Vector3 vector33 = CurveCalculation::ParabolaD3(3.0 / (2.0 * focal), defaultFrame3, focal);
	CHECK(vector3.X() == 1.0);
	CHECK(vector3.Y() == 0.5);
	CHECK(vector31.X() == Approx(0.0));
	CHECK(vector31.Y() == Approx(1.0));
	CHECK(vector32.X() == Approx(-0.5));
	CHECK(vector32.Y() == Approx(0.0));
	CHECK(vector33.X() == Approx(-1.0));
	CHECK(vector33.Y() == Approx(-0.5));
}