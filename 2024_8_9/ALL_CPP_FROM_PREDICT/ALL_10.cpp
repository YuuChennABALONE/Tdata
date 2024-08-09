 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusD2 1/4 ", "[math][CurveCalculation][P1][TorusD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 2.0;
	double minorRadius = 1.0;
	Vector3 vector3 = AMCAX::CurveCalculation::TorusD2(0.0, 0.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector31 = AMCAX::CurveCalculation::TorusD2(0.0, 1.0, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector32 = AMCAX::CurveCalculation::TorusD2(0.0, 1.5, defaultFrame3, majorRadius, minorRadius);
	Vector3 vector33 = AMCAX::CurveCalculation::TorusD2(0.0, 2.0, defaultFrame3, majorRadius, minorRadius);
	CHECK(vector3.X() == 2.0);
	CHECK(vector3.Y() == 1.0);
	CHECK(vector3.Z() == 0.0);
	CHECK(vector31.X() == Approx(2.0).margin(1e-14));
	CHECK(vector31.Y() == 0.0);
	CHECK(vector31.Z() == 1.0);
	CHECK(vector32.X() == Approx(-1.0).margin(1e-14));
	CHECK(vector32.Y() == 0.0);
	CHECK(vector32.Z() == 0.0);
	CHECK(vector33.X() == -2.0);
	CHECK(vector33.Y() == 1.0);
	CHECK(vector33.Z() == 0.0);
}